#ifndef DOCUMENT_COMMAND_INTERPRETER_HPP
#define DOCUMENT_COMMAND_INTERPRETER_HPP

#include "interpreter/command_interpreter.hpp"

class DocumentCommandInterpreter : public CommandInterpreter {
public:
  DocumentCommandInterpreter(Application *application, Document *document);
  bool interpret(std::string input);
  std::string get_state_marker();
};

#endif
