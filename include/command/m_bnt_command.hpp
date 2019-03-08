#ifndef M_BNT_COMMAND_HPP
#define M_BNT_COMMAND_HPP

#include <iostream>

#include "application/application.hpp"
#include "command/command.hpp"
#include "document.hpp"
#include "interpreter/command_interpreter.hpp"
#include "printer/document_printer.hpp"

class MBNTCommand : public Command {
protected:
  Application *application;
  Document *document;
  DocumentPrinter *document_printer;
  CommandInterpreter *command_interpreter;

public:
  MBNTCommand(std::string description);
  virtual bool run_command(std::string content) = 0;
};

#endif
