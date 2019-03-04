#include "document.hpp"

void Document::set_title(std::string title) { header.title = title; }

void Document::set_date(std::string date) { header.date = date; }

void Document::set_description(std::string description) {
  header.description = description;
}

void Document::add_task(Task task) { task_section.tasks.push_back(task); }

bool Document::is_complete() {
  return (header.is_section_complete() && task_section.is_section_complete());
}
