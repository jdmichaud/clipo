# Clipo : Command Line Interpreter library based on the boost Program Option library

The idea is to build on top of the program_option library developed by Vladimir Prus (http://www.boost.org/doc/html/program_options.html) an easy to implement command line interpreter library.

## Example
```
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
```
# output:
```
>handler
error: required parameter is missing in 'handler'
>handler 1 2 3
1
2
3
>toto
error: unknown option toto
>exit 0
Press any key to continue . . .
```
