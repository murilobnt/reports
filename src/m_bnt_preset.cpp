#include "preset/m_bnt_preset.hpp"

void MBNTPreset::run() {
  Application application;
  Document document;
  MBNTMarkdownPrinter document_printer;
  MBNTCommandInterpreter command_interpreter(&application, &document,
                                             &document_printer);
  application.run(&command_interpreter);
}
