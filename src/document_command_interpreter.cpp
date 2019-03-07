#include "interpreter/document_command_interpreter.hpp"

DocumentCommandInterpreter::DocumentCommandInterpreter(Application *application,
                                                       Document *document)
    : CommandInterpreter(application, document) {}

bool DocumentCommandInterpreter::interpret(std::string command,
                                           std::string content) {
  return false;
}

std::string DocumentCommandInterpreter::get_state_marker() { return "."; }
