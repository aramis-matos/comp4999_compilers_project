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

%token <std::string> LETRA "letra"
%token <int> DIGITO "digito"
%token <std::string> ID "id"
%token <std::string> IDCONT "idcont"
%type  <std::string> exp

%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: exps {};

exps: %empty | exps exp {};

////assignment: "identificador" "="

exp:
"letra" {}
| "digito" {}
| "id" {}
| "idcont" {}
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
