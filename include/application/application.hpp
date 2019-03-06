#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>

#include "document.hpp"
#include "interpreter/command_interpreter.hpp"
#include "interpreter/document_command_interpreter.hpp"
#include "printer/document_printer.hpp"
#include "printer/m_bnt_markdown_printer.hpp"

class Application {
private:
  CommandInterpreter *command_interpreter;
  Document document;
  void finish();
  void private_run();

public:
  Application();
  Application(CommandInterpreter *command_interpreter);
  void run();
  void run(DocumentPrinter *document_printer);
  void set_command_interpreter(CommandInterpreter *command_interpreter);
};

#endif
