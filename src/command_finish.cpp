#include "command/command_finish.hpp"

CommandFinish::CommandFinish(std::string description, Document *document,
                             DocumentPrinter *document_printer)
    : MBNTCommand(description) {
  this->document = document;
  this->document_printer = document_printer;
}

bool CommandFinish::run_command(std::string content) {
  if (!document->is_complete()) {
    std::cout << "You have to finish the document (p1 and p2 commands) first."
              << std::endl;
    return false;
  }
  std::string file_name;
  std::cout << "Name of the file: " << std::endl;
  std::getline(std::cin, file_name);
  document_printer->print_document(file_name, *document);
  return true;
}
