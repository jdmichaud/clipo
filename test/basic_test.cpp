//  Boost cli library command_line_interpreter.hpp header file  --------------//

//  (C) Copyright Jean-Daniel Michaud 2007. Permission to copy, use, modify, 
//  sell and distribute this software is granted provided this copyright notice 
//  appears in all copies. This software is provided "as is" without express or 
//  implied warranty, and with no claim as to its suitability for any purpose.

//  See http://www.boost.org/LICENSE_1_0.txt for licensing.
//  See http://code.google.com/p/clipo/ for library home page.

#include <string>
#include <vector>
#include <iostream>
#include <command_line_interpreter.hpp>

namespace po = boost::program_options;

void handler(const std::vector<std::string> &parameters)
{
  for (std::vector<std::string>::const_iterator it = parameters.begin();
       it != parameters.end();
       ++it)
    std::cout << *it << std::endl;
}

void exit_(unsigned int code = 0)
{
  exit(code);
}

int main(int argc, char **argv)
{
  boost::cli::commands_description desc;
  desc.add_options()
    ("handler", po::value< std::vector<std::string> >()->notifier(&handler)->multitoken())
    ("exit", po::value< unsigned int >()->notifier(&exit_))
    ;

  boost::cli::command_line_interpreter cli(desc, ">");
  cli.interpret(std::cin);
}
