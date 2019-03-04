#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>

#include "header.hpp"
#include "task.hpp"
#include "task_section.hpp"

class Document {
private:
  Header header;
  TaskSection task_section;

public:
  void set_title(std::string title);
  void set_date(std::string date);
  void set_description(std::string description);
  void add_task(Task task);
  bool is_complete();
};

#endif
