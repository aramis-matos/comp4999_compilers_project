%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
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
%}

%option noyywrap nounput batch debug noinput

digito   [0-9]+
fin_de_linea (";"|";")
elemento_quimico ("H"|"Li"|"Na"|"K"|"Rb"|"Cs"|"Fr"|"Be"|"Mg"|"Ca"|"Sr"|"Ba"|"Ra"|"Sc"|"Y"|"Ti"|"Zr"|"Hf"|"Db"|"V"|"Nb"|"Ta"|"Ji"|"Cr"|"Mo"|"W"|"Rf"|"Mn"|"Tc"|"Re"|"Bh"|"Fe"|"Ru"|"Os"|"Hn"|"Co"|"Rh"|"Ir"|"Mt"|"Ni"|"Pd"|"Pt"|"Cu"|"Ag"|"Au"|"Zn"|"Cd"|"Hg"|"B"|"Al"|"Ga"|"In"|"Ti"|"C"|"Si"|"Ge"|"Sn"|"Pb"|"N"|"P"|"As"|"Sb"|"Bi"|"O"|"S"|"Se"|"Te"|"Po"|"F"|"Cr"|"Br"|"I"|"At"|"He"|"Ne"|"Ar"|"Kr"|"Xe"|"Rn")
id    [a-zA-Z][a-zA-Z0-9]*
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

"("      return yy::parser::make_LPAREN (loc);
")"      return yy::parser::make_RPAREN (loc);

{digito}      {
  errno = 0;
  long n = strtol (yytext, NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error (loc, "integer is out of range: "
                                    + std::string(yytext));
  return yy::parser::make_DIGITO (n, loc);
}

{elemento_quimico} {
  return yy::parser::make_ELEMENTO_QUIMICO(yytext,loc);
}

{id}       return yy::parser::make_IDENTIFICADOR (yytext, loc);
.          {
             throw yy::parser::syntax_error
               (loc, "invalid character: " + std::string(yytext));
}

{fin_de_linea} {
  return yy::parser::make_FIN_DE_LINEA(yytext,loc);
}

<<EOF>>    return yy::parser::make_END (loc);
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
