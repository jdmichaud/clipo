//  Boost cli library command_line_interpreter.hpp header file  --------------//

//  (C) Copyright Jean-Daniel Michaud 2007. Permission to copy, use, modify, 
//  sell and distribute this software is granted provided this copyright notice 
//  appears in all copies. This software is provided "as is" without express or 
//  implied warranty, and with no claim as to its suitability for any purpose.

//  See http://www.boost.org for updates, documentation, and revision history.
//  See http://www.boost.org/libs/clipo/ for library home page.

#include <string>
#include <vector>
#include <iostream>
#include <command_line_interpreter.hpp>

int main(int argc, char **argv)
{
  options_description desc;
  desc.add_options()
      ("handler", value< std::vector<std::string> >()->notifier(&handler)->multitoken())
      ("exit", value< unsigned int >()->notifier(&exit_))
      ;

  command_line_interpreter cli(desc);
  cli.interpret(std::cin);
}
