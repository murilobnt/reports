#ifndef DOCUMENT_COMMAND_INTERPRETER_HPP
#define DOCUMENT_COMMAND_INTERPRETER_HPP

#include <iostream>

#include "document_command.hpp"
#include "interpreter/command_interpreter.hpp"

class DocumentCommandInterpreter : public CommandInterpreter {
public:
  DocumentCommandInterpreter(Application *application, Document *document);
  bool interpret(std::string command, std::string content);
  std::string get_state_marker();
};

#endif
