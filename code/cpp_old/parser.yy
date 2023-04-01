%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.1"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  class driver;

}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {
# include "driver.hh"
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
;

%token <std::string> PARENTESIS_IZQ "parentesis_izq"
%token <std::string> PARENTESIS_DER "parentesis_der"
%token <std::string> FIN_DE_LINEA "fin_de_linea"
%token <std::string> LETRA "letra"
%token <int> DIGITO "digito"
%token <std::string> TIPO "tipo"
%token <std::string> OPERACION "operacion"
%token <int> VALENCIA "valencia"
%token <std::string> ELEMEN "elemen"
%token <std::string> ENLACE "enlace"
%token <std::string> ID "id"
%token <std::string> IDCONT "idcont"
%token <std::string> SENTENCIAS "sentencias"
%token <std::string> SENTENCIA "sentencia"
%token <std::string> MODELO_MOLECULAR "modelo_molecular"
%token <std::string> COMPUESTO "compuesto"
%token <std::string> COMPUESTOS "compuestos"
%token <std::string> ELEMENTO "elemento"
%token <std::string> PALABRA_RESERVADA "palabra_reservada"
%token <std::string> ELEMENTO_QUIMICO "elemento_quimico"
%token <std::string> GRUPO_FUNCIONAL "grupo_funcional"
%token <std::string> GRUPO_FUNCIONAL_INFERIOR "grupo_funcional_inferior"
%token <std::string> GRUPO_FUNCIONAL_SUPERIOR "grupo_funcional_superior"
%token <std::string> MODELO_GRUPO_FUNCIONAL "modelo_grupo_funcional"
%type  <std::string> exp

%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: exps {};

exps: %empty | exps exp {};

////assignment: "identificador" "="

exp:
"fin_de_linea" {}
| "letra" {}
| "digito" {}
| "tipo" {}
| "operacion" {}
| "valencia" {}
| "enlace" {}
| "palabra_reservada" {}
| "elemento_quimico" {}
| "id" {}
| "idcont" {}
| "sentencias" {}
| "sentencia" {}
| "modelo_molecular" {}
| "compuesto" {}
| "compuestos" {}
| "elemento" {}
| "grupo_funcional" {}
| "grupo_funcional_inferior" {}
| "grupo_funcional_superior" {}
| "modelo_grupo_funcional" {}
| "parentesis_izq"
| "parentesis_der"
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
