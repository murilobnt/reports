#include "interpreter/m_bnt_command_interpreter.hpp"

MBNTCommandInterpreter::MBNTCommandInterpreter(
    Application *application, Document *document,
    DocumentPrinter *document_printer) {
  commands.insert(std::pair<std::string, Command *>(
      "help", new CommandHelp("Displays this message.", this)));
  commands.insert(std::pair<std::string, Command *>(
      "p1", new CommandP1("Interactive phase 1, relative to the document's "
                          "header. Prompts the user to enter "
                          "document's title, date and description.",
                          document)));
  commands.insert(std::pair<std::string, Command *>(
      "p2",
      new CommandP2(
          "Interactive phase 2, relative to the document's tasks section. "
          "Prompts the user to enter a task's title, description, completion, "
          "description, and the will to add more tasks. The user may enter "
          "cancel to cancel the task addition operation.",
          document)));
  commands.insert(std::pair<std::string, Command *>(
      "finish",
      new CommandFinish("Finish the document. Prompts the user the "
                        "name (relative path) of the output file, and writes "
                        "the information given through p1 and p2 interaction.",
                        document, document_printer)));
  set_state_marker(".");
}

MBNTCommandInterpreter::~MBNTCommandInterpreter() {
  for (std::map<std::string, Command *>::iterator it = commands.begin();
       it != commands.end(); ++it) {
    delete it->second;
  }
}
