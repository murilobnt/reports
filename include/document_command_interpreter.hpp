#ifndef DOCUMENT_COMMAND_INTERPRETER_HPP
#define DOCUMENT_COMMAND_INTERPRETER_HPP

#include "command_interpreter.hpp"

class DocumentCommandInterpreter : public CommandInterpreter {
public:
  DocumentCommandInterpreter(Document *document);
  bool interpret(std::string input);
};

#endif
