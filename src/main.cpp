#include "application/application.hpp"
#include "printer/m_bnt_markdown_printer.hpp"

int main() {
  Application application;
  application.run(new MBNTMarkdownPrinter());
  return 0;
}
