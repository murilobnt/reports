#ifndef TASK_HPP
#define TASK_HPP

#include <string>

struct Task {
  std::string title;
  std::string description;
  int completion;
  std::string notes;
};

#endif
