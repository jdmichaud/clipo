//  Boost cli library command_line_interpreter.hpp header file  --------------//

//  (C) Copyright Jean-Daniel Michaud 2007. Permission to copy, use, modify, 
//  sell and distribute this software is granted provided this copyright notice 
//  appears in all copies. This software is provided "as is" without express or 
//  implied warranty, and with no claim as to its suitability for any purpose.

//  See http://www.boost.org for updates, documentation, and revision history.
//  See http://www.boost.org/libs/clipo/ for library home page.

#ifndef BOOST_COMMAND_LINE_INTERPRETER
#define BOOST_COMMAND_LINE_INTERPRETER

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <boost/program_options.hpp>

namespace boost { namspace cli {

typedef boost::program_options::options_description commands_description;

class command_line_interpreter
{
public:
  command_line_interpreter(const commands_description& desc)
  {
    m_desc = &desc;  
  }

  void interpret(std::istream &input_stream)
  {
    std::string command;
    while (std::getline(input_stream, command, '\n'))
    {
      std::vector<std::string> args;
      
      // huu, ugly...
      args = boost::program_options::split_winmain(std::string("--") + command); 
      
      try
      {
        boost::program_options::variables_map vm;
        boost::program_options::store(
          boost::program_options::command_line_parser(args).options(*m_desc).run(), 
          vm);
        boost::program_options::notify(vm);
      }
      catch (std::exception& e) 
      {
        std::cerr << "error: " << e.what() << std::endl;
      }
    }
  }
  

private:
  const options_description* m_desc;
};

} // !namespace cli
} // !namespace boost

#endif // !BOOST_COMMAND_LINE_INTERPRETER
