#ifndef COMMAND_INTERPRETER_HPP
#define COMMAND_INTERPRETER_HPP

#include "document.hpp"

class Application;

class CommandInterpreter {
protected:
  Application *application;
  Document *document;

public:
  CommandInterpreter(Application *application, Document *document);
  virtual bool interpret(std::string command, std::string content) = 0;
  virtual std::string get_state_marker() = 0;
};

#endif
