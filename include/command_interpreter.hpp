#ifndef COMMAND_INTERPRETER_HPP
#define COMMAND_INTERPRETER_HPP

#include "document.hpp"

class CommandInterpreter {
private:
  Document *document;

public:
  CommandInterpreter(Document *document);
  virtual bool interpret(std::string input) = 0;
};

#endif
