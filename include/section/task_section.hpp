#ifndef TASK_SECTION_HPP
#define TASK_SECTION_HPP

#include <vector>

#include "section/document_section.hpp"
#include "section/task.hpp"

struct TaskSection : DocumentSection {
  std::vector<Task> tasks;

  bool is_section_complete() const;
};

#endif
