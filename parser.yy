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
  ASIG  "="
  LPAREN  "("
  RPAREN  ")"
  LCOR "["
  RCOR "]"
;


%token <std::string> ELEMENTO_QUIMICO "elemento_quimico"
%token <std::string> ELEMENTO "elemento"
%token <std::string> IDENTIFICADOR "identificador"
%token <std::string> FIN_DE_LINEA "fin_de_linea"
%token <std::string> ENLACE "enlace"
%token <int> DIGITO "digito"
%token <int> VALENCIA "valencia"
%type  <std::string> exp

%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: exps {};

exps: %empty | exps exp {};

////assignment: "identificador" "="

exp:
"elemento_quimico" {

}
| "elemento" {

}
| "identificador" {

}
| "fin_de_linea" {
}
| "valencia" {}
| "digito" {}
| "enlace" {}
| "=" {}
| "[" {}
| "]" {}
| "(" {}
| ")" {}
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
