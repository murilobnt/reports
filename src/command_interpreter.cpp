#include "application/application.hpp"
#include "interpreter/command_interpreter.hpp"

CommandInterpreter::CommandInterpreter(Application *application,
                                       Document *document) {
  this->application = application;
  this->document = document;
}

void CommandInterpreter::set_document_printer(
    DocumentPrinter *document_printer) {
  this->document_printer = document_printer;
}
