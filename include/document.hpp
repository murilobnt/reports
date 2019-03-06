#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>
#include <vector>

#include "section/header.hpp"
#include "section/task.hpp"
#include "section/task_section.hpp"

class Document {
private:
  Header header;
  TaskSection task_section;

public:
  void set_title(std::string title);
  void set_date(std::string date);
  void set_description(std::string description);
  void add_task(Task task);

  Header get_header() const;
  TaskSection get_task_section() const;
  std::vector<Task> get_tasks() const;

  std::string get_title() const;
  std::string get_date() const;
  std::string get_description() const;

  bool is_complete() const;
  bool is_header_complete() const;
  bool is_tasks_complete() const;
};

#endif
