#include "document.hpp"

std::string Document::get_title() { return header.title; }
void Document::set_title(std::string title) { header.title = title; }

std::string Document::get_date() { return header.date; }
void Document::set_date(std::string date) { header.date = date; }

std::string Document::get_description() { return header.description; }
void Document::set_description(std::string description) {
  header.description = description;
}

void Document::add_task(Task task) { task_section.tasks.push_back(task); }

bool Document::is_complete() {
  return (header.is_section_complete() && task_section.is_section_complete());
}

bool Document::is_header_complete() { return header.is_section_complete(); }

bool Document::is_tasks_complete() {
  return task_section.is_section_complete();
}
