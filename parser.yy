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
  LPAREN  "("
  RPAREN  ")"
;


%token <std::string> ELEMENTO_QUIMICO "elemento_quimico"
%token <std::string> IDENTIFICADOR "identificador"
%token <std::string> FIN_DE_LINEA "fin_de_linea"
%token <int> DIGITO "digito"
%type  <std::string> exp

%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: exps {};

exps: %empty | exps exp {};

exp:
"elemento_quimico"   {

}
| "identificador" {

}
| "fin_de_linea" {
}
| "digito" {}
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
