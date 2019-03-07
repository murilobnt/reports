#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>

#include "document.hpp"
#include "interpreter/command_interpreter.hpp"
#include "printer/document_printer.hpp"
#include "printer/m_bnt_markdown_printer.hpp"

class Application {
public:
  void run(CommandInterpreter *command_interpreter);
};

#endif
