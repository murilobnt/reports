#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>

#include "section/header.hpp"
#include "section/task.hpp"
#include "section/task_section.hpp"

class Document {
private:
  Header header;
  TaskSection task_section;

public:
  std::string get_title();
  void set_title(std::string title);
  std::string get_date();
  void set_date(std::string date);
  std::string get_description();
  void set_description(std::string description);

  void add_task(Task task);

  bool is_complete();
  bool is_header_complete();
  bool is_tasks_complete();
};

#endif
