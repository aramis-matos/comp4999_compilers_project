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

FIN_DE_LINEA (":"|";")

LETRA [A-Za-z]

DIGITO [0-9]

TIPO "modelo"

OPERACION ("graficar2d"|"graficar3d"|"pesomolecular")

VALENCIA [1-9]

ENLACE ("-"|"="|":"|"::")

IDCONT [A-Za-z0-9]+

ID [A-Za-z]|{LETRA}{IDCONT}

ELEMENTO_QUIMICO ("H"|"Li"|"Na"|"K"|"Rb"|"Cs"|"Fr"|"Be"|"Mg"|"Ca"|"Sr"|"Ba"|"Ra"|"Sc"|"Y"|"Ti"|"Zr"|"Hf"|"Db"|"V"|"Nb"|"Ta"|"Ji"|"Cr"|"Mo"|"W"|"Rf"|"Mn"|"Tc"|"Re"|"Bh"|"Fe"|"Ru"|"Os"|"Hn"|"Co"|"Rh"|"Ir"|"Mt"|"Ni"|"Pd"|"Pt"|"Cu"|"Ag"|"Au"|"Zn"|"Cd"|"Hg"|"B"|"Al"|"Ga"|"In"|"Ti"|"C"|"Si"|"Ge"|"Sn"|"Pb"|"N"|"P"|"As"|"Sb"|"Bi"|"O"|"S"|"Se"|"Te"|"Po"|"F"|"Cr"|"Br"|"I"|"At"|"He"|"Ne"|"Ar"|"Kr"|"Xe"|"Rn")

MODELO_MOLECULAR ({ELEMENTO_QUIMICO}|{ELEMENTO_QUIMICO}{VALENCIA}|{ELEMENTO}{GRUPO_FUNCIONAL}|{COMPUESTO}{ELEMENTO}|{COMPUESTO}{ELEMENTO}{GRUPO_FUNCIONAL}|{COMPUESTO}{COMPUESTO}{COMPUESTOS})

COMPUESTO ({ELEMENTO_QUIMICO}|{ELEMENTO_QUIMICO}{VALENCIA}|{ELEMENTO}{GRUPO_FUNCIONAL}|{ELEMENTO}{GRUPO_FUNCIONAL}{ENLACE}|{ELEMENTO}{ENLACE})

COMPUESTOS {COMPUESTO}+

ELEMENTO ({ELEMENTO_QUIMICO}|{ELEMENTO_QUIMICO}{VALENCIA})


GRUPO_FUNCIONAL ({GRUPO_FUNCIONAL_INFERIOR}{GRUPO_FUNCIONAL_SUPERIOR}|{GRUPO_FUNCIONAL_SUPERIOR}{GRUPO_FUNCIONAL_INFERIOR}|"("{MODELO_GRUPO_FUNCIONAL}")"|"["{MODELO_GRUPO_FUNCIONAL}"]")

GRUPO_FUNCIONAL_INFERIOR ("["{MODELO_GRUPO_FUNCIONAL}"]")

GRUPO_FUNCIONAL_SUPERIOR ("("{MODELO_GRUPO_FUNCIONAL}")")

MODELO_GRUPO_FUNCIONAL ({ELEMENTO_QUIMICO}+{VALENCIA}?)+

SENTENCIA ("defina"{ID}"como"{TIPO}|{ID}"="{MODELO_MOLECULAR}|{OPERACION}"("{ID}")")

SENTENCIAS ({SENTENCIA}{FIN_DE_LINEA})+

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


{FIN_DE_LINEA} {
	format_output("FIN_DE_LINEA",yytext,loc);
	return yy::parser::make_FIN_DE_LINEA(yytext,loc);
}
{VALENCIA} {
  	long n = std::stol(yytext);
	format_output("VALENCIA",yytext,loc);
	return yy::parser::make_VALENCIA(n,loc);
}
{DIGITO} {
  long n = std::stol(yytext);
	format_output("DIGITO",yytext,loc);
	return yy::parser::make_DIGITO(n,loc);
}
{TIPO} {
	format_output("TIPO",yytext,loc);
	return yy::parser::make_TIPO(yytext,loc);
}
{OPERACION} {
	format_output("OPERACION",yytext,loc);
	return yy::parser::make_OPERACION(yytext,loc);
}
{ELEMENTO_QUIMICO} {
	format_output("ELEMENTO_QUIMICO",yytext,loc);
	return yy::parser::make_ELEMENTO_QUIMICO(yytext,loc);
}
{ELEMENTO} {
	format_output("ELEMENTO",yytext,loc);
	return yy::parser::make_ELEMENTO(yytext,loc);
}
{GRUPO_FUNCIONAL_INFERIOR} {
	format_output("GRUPO_FUNCIONAL_INFERIOR",yytext,loc);
	return yy::parser::make_GRUPO_FUNCIONAL_INFERIOR(yytext,loc);
}
{GRUPO_FUNCIONAL_SUPERIOR} {
	format_output("GRUPO_FUNCIONAL_SUPERIOR",yytext,loc);
	return yy::parser::make_GRUPO_FUNCIONAL_SUPERIOR(yytext,loc);
}
{ENLACE} {
	format_output("ENLACE",yytext,loc);
	return yy::parser::make_ENLACE(yytext,loc);
}

{MODELO_MOLECULAR} {
	format_output("MODELO_MOLECULAR",yytext,loc);
	return yy::parser::make_MODELO_MOLECULAR(yytext,loc);
}
{COMPUESTO} {
	format_output("COMPUESTO",yytext,loc);
	return yy::parser::make_COMPUESTO(yytext,loc);
}
{GRUPO_FUNCIONAL} {
	format_output("GRUPO_FUNCIONAL",yytext,loc);
	return yy::parser::make_GRUPO_FUNCIONAL(yytext,loc);
}
{COMPUESTOS} {
	format_output("COMPUESTOS",yytext,loc);
	return yy::parser::make_COMPUESTOS(yytext,loc);
}
{LETRA} {
	format_output("LETRA",yytext,loc);
	return yy::parser::make_LETRA(yytext,loc);
}
{ID} {
	format_output("ID",yytext,loc);
	return yy::parser::make_ID(yytext,loc);
}
{IDCONT} {
	format_output("IDCONT",yytext,loc);
	return yy::parser::make_IDCONT(yytext,loc);
}
{SENTENCIAS} {
	format_output("SENTENCIAS",yytext,loc);
	return yy::parser::make_SENTENCIAS(yytext,loc);
}
{SENTENCIA} {
	format_output("SENTENCIA",yytext,loc);
	return yy::parser::make_SENTENCIA(yytext,loc);
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
