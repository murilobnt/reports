#include "application/application.hpp"
#include "interpreter/m_bnt_command_interpreter.hpp"
#include "printer/m_bnt_markdown_printer.hpp"

int main() {
  Application application;
  Document document;
  DocumentPrinter *document_printer = new MBNTMarkdownPrinter();
  MBNTCommandInterpreter command_interpreter(&application, &document,
                                             document_printer);
  application.run(&command_interpreter);
  delete document_printer;
  return 0;
}
