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
unit: exp  { drv.result = $1; };


//assignment:
//  "identifier" ":=" exp { drv.variables[$1] = $3;
//  drv.parsed_values.push_back(std::make_pair("ID",std::string($1)));
//  drv.parsed_values.push_back(std::make_pair("ASSIGN",std::string(":=")));
//  drv.parsed_values.push_back(std::make_pair("INT",std::to_string($3)));
//  };


exp:
"elemento_quimico"   {
drv.parsed_values.push_back(std::make_pair("elemento_quimico",std::string($$)));
}
| "identificador" {
drv.parsed_values.push_back(std::make_pair("indentificador",std::string($$)));
}
| exp
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
