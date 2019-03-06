#include "printer/m_bnt_markdown_printer.hpp"

void MBNTMarkdownPrinter::print_markdown_line(std::string line, int spaces) {
  ofstr << line;
  for (int i = 0; i < spaces; ++i)
    ofstr << std::endl;
}

void MBNTMarkdownPrinter::replace(std::string &m_string, char what, char to) {
  for (int i = 0; i < m_string.length(); ++i)
    if (m_string[i] == what)
      m_string[i] = to;
}

void MBNTMarkdownPrinter::print_header(const Header &header) {
  print_markdown_line("# " + header.title);
  print_markdown_line(header.date + ".");
  print_markdown_line(
      "*" + header.description +
      (header.description[header.description.length() - 1] == '.' ? "" : ".") +
      "*");
  print_markdown_line("---");
}

void MBNTMarkdownPrinter::print_summary(const TaskSection &task_s) {
  print_markdown_line("## Summary");
  for (std::vector<Task>::const_iterator it = task_s.tasks.begin();
       it != task_s.tasks.end(); ++it) {
    std::string index = (*it).title;
    std::transform(index.begin(), index.end(), index.begin(), ::tolower);
    replace(index, ' ', '-');
    if ((*it).completion == 100) {
      print_markdown_line("- [x] [" + (*it).title + ".](#" + index + ")", 1);
    } else {
      print_markdown_line("- [ ] [" + (*it).title + ".](#" + index + ")", 1);
    }
  }
  ofstr << std::endl;
  print_markdown_line("---");
}

void MBNTMarkdownPrinter::print_tasks(const TaskSection &task_s) {
  int i = 0;
  for (std::vector<Task>::const_iterator it = task_s.tasks.begin();
       it != task_s.tasks.end(); ++it) {
    print_markdown_line("### " + (*it).title);
    print_markdown_line(
        (*it).description +
        ((*it).description[(*it).description.length() - 1] == '.' ? "" : "."));
    print_markdown_line("**Completion:** ![task" + (std::to_string(i++)) +
                        "_completion](http://progressed.io/bar/" +
                        std::to_string((*it).completion) + ")");

    if ((*it).notes != "") {
      print_markdown_line(
          "Notes: " + (*it).notes +
          ((*it).notes[(*it).notes.length() - 1] == '.' ? "" : "."));
    }
    print_markdown_line("---");
  }
}

void MBNTMarkdownPrinter::print_document(std::string file_name,
                                         const Document &document) {
  ofstr.open(file_name);
  print_header(document.get_header());
  print_summary(document.get_task_section());
  print_tasks(document.get_task_section());
  ofstr.close();
}
