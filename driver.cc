#include "driver.hh"
#include "parser.hh"
#include <fstream>
#include <iostream>

std::map<std::string,std::string> add_keywords (std::map<std::string,std::string>& list) {
    std::ifstream keywords;
    std::string val;

    keywords.open("keywords.txt");
    while (getline(keywords,val)) {
        list[val] = "";
    }
    list["guh"] = "chungus";
    keywords.close();
    return list;
}


driver::driver () : trace_parsing (false), trace_scanning (false)
{
  this->variables = add_keywords(this->variables);
}

int
driver::parse (const std::string &f)
{
  file = f;
  location.initialize (&file);
  scan_begin ();
  yy::parser parser (*this);
  parser.set_debug_level (trace_parsing);
  int res = parser.parse ();
  scan_end ();
  return res;
}
