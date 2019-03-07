#ifndef COMMAND_INTERPRETER_HPP
#define COMMAND_INTERPRETER_HPP

#include "command/command.hpp"
#include "document.hpp"
#include "printer/document_printer.hpp"

class Application;

class CommandInterpreter {
protected:
  Application *application;
  Document *document;
  DocumentPrinter *document_printer;
  // std::vector < std::pair<std::string, Command *> commands;

public:
  CommandInterpreter(Application *application, Document *document);
  virtual bool interpret(std::string command, std::string content) = 0;
  virtual std::string get_state_marker() = 0;
  void set_document_printer(DocumentPrinter *document_printer);
};

#endif
