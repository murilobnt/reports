#include "application/application.hpp"
#include "interpreter/command_interpreter.hpp"

CommandInterpreter::CommandInterpreter(Application *application,
                                       Document *document) {
  this->application = application;
  this->document = document;
}
