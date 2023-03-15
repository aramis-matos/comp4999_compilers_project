%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
# include <fstream>
# include "driver.hh"
# include "parser.hh"

// Work around an incompatibility in flex (at least versions
// 2.5.31 through 2.5.33): it generates code that does
// not conform to C89.  See Debian bug 333231
// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
# undef yywrap
# define yywrap() 1

// Pacify warnings in yy_init_buffer (observed with Flex 2.6.4)
// and GCC 7.3.0.
#if defined __GNUC__ && 7 <= __GNUC__
# pragma GCC diagnostic ignored "-Wnull-dereference"
#endif

std::ofstream file("output.txt");
void format_output (std::string token,const char* yytext, yy::location& loc) {
  file << "(" << "<" << token << ">," << std::string(yytext) << "," << loc << ")" << std::endl;
}
%}

%option noyywrap nounput batch debug noinput

LETRA [A-Za-z]

DIGITO [0-9]

IDCONT [A-Za-z0-9]+


ID [A-Za-z]|{LETRA}{IDCONT}


blank [ \t]
%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);


  
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}
{blank}+   loc.step ();
[\n]+      loc.lines (yyleng); loc.step ();


{LETRA} {
	format_output("LETRA",yytext,loc);
	return yy::parser::make_LETRA(yytext,loc);
}
{DIGITO} {
  long n = std::stol(yytext);
	format_output("DIGITO",yytext,loc);
	return yy::parser::make_DIGITO(n,loc);
}

{ID} {
	format_output("ID",yytext,loc);
	return yy::parser::make_ID(yytext,loc);
}
{IDCONT} {
	format_output("IDCONT",yytext,loc);
	return yy::parser::make_IDCONT(yytext,loc);
}

<<EOF>>    {
  file << "\n" << "\n" << "Tabla de Simbolos" << std::endl;
  for (auto & [first,second] : drv.variables) {
    file << "(<";
    if (second == "") {
      file << "PALABRA_RESERVADA";
    }
    else {
      file << "ID";
    }
    file << ">," << first << ")" << std::endl;
  }
  file.close();
  return yy::parser::make_END (loc);
  }

. {
  file << "CARACTER INVALIDO " << std::string(yytext) << "," << loc << std::endl;
}
%%

void
driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void
driver::scan_end ()
{
  fclose (yyin);
}
