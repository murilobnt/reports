#ifndef TASK_SECTION_HPP
#define TASK_SECTION_HPP

#include <vector>

#include "document_section.hpp"
#include "task.hpp"

struct TaskSection : DocumentSection {
  std::vector<Task> tasks;

  bool is_section_complete();
};

#endif
