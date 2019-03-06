#ifndef M_BNT_MARKDOWN_PRINTER_HPP
#define M_BNT_MARKDOWN_PRINTER_HPP

#include <algorithm>
#include <fstream>
#include <string>

#include "document.hpp"
#include "printer/document_printer.hpp"
#include "section/header.hpp"
#include "section/task_section.hpp"

class MBNTMarkdownPrinter : public DocumentPrinter {
private:
  std::ofstream ofstr;
  void print_markdown_line(std::string line, int spaces = 2);
  void replace(std::string &m_string, char what, char to);
  void print_header(const Header &header);
  void print_summary(const TaskSection &task_s);
  void print_tasks(const TaskSection &task_s);

public:
  void print_document(std::string file_name, const Document &document);
};

#endif
