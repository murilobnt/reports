#include "section/task_section.hpp"

bool TaskSection::is_section_complete() const { return !tasks.empty(); }
