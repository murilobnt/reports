#include "command/command_finish.hpp"

CommandFinish::CommandFinish(Document *document,
                             DocumentPrinter *document_printer) {
  this->document = document;
  this->document_printer = document_printer;
}

void CommandFinish::run_command(std::string content) {
  std::string file_name;
  std::cout << "Name of the file: " << std::endl;
  std::getline(std::cin, file_name);
  document_printer->print_document(file_name, *document);
}
