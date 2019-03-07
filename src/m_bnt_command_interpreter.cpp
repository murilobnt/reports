#include "interpreter/m_bnt_command_interpreter.hpp"

MBNTCommandInterpreter::MBNTCommandInterpreter(
    Application *application, Document *document,
    DocumentPrinter *document_printer) {
  commands.insert(
      std::pair<std::string, Command *>("p1", new CommandP1(document)));
  commands.insert(
      std::pair<std::string, Command *>("p2", new CommandP2(document)));
  commands.insert(std::pair<std::string, Command *>(
      "finish", new CommandFinish(document, document_printer)));

  set_state_marker(".");
}

MBNTCommandInterpreter::~MBNTCommandInterpreter() {
  for (std::map<std::string, Command *>::iterator it = commands.begin();
       it != commands.end(); ++it) {
    delete it->second;
  }
}
