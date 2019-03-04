#include "document_command_interpreter.hpp"

DocumentCommandInterpreter::DocumentCommandInterpreter(Document *document)
    : CommandInterpreter(document) {}

bool DocumentCommandInterpreter::interpret(std::string input) { return false; }
