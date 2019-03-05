#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>

#include "document.hpp"
#include "interpreter/command_interpreter.hpp"
#include "interpreter/document_command_interpreter.hpp"

class Application {
private:
  CommandInterpreter *command_interpreter;
  Document document;

public:
  Application();
  void run();
  void finish();
  void set_command_interpreter(CommandInterpreter *command_interpreter);
};

#endif
