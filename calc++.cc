#include <iostream>
#include "driver.hh"

int
main (int argc, char *argv[])
{
  int res = 0;
  driver drv;
  for (int i = 1; i < argc; ++i)
    if (argv[i] == std::string ("-p"))
      drv.trace_parsing = true;
    else if (argv[i] == std::string ("-s"))
      drv.trace_scanning = true;
    else if (!drv.parse (argv[i])) {
      // std::cout << drv.result << '\n';
      for (long unsigned int i = 0; i < drv.parsed_values.size(); i++) {
//       std::cout << drv.parsed_values[i].first  << ": " << drv.parsed_values[i].second << std::endl;
      }
    }
    else
      res = 1;
  return res;
}
