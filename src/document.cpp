#include "document.hpp"

void Document::set_title(std::string title) { header.title = title; }
void Document::set_date(std::string date) { header.date = date; }
void Document::set_description(std::string description) {
  header.description = description;
}
void Document::add_task(Task task) { task_section.tasks.push_back(task); }

Header Document::get_header() const { return header; }
TaskSection Document::get_task_section() const { return task_section; }
std::vector<Task> Document::get_tasks() const { return task_section.tasks; }
std::string Document::get_title() const { return header.title; }
std::string Document::get_date() const { return header.date; }
std::string Document::get_description() const { return header.description; }
bool Document::is_complete() const {
  return (header.is_section_complete() && task_section.is_section_complete());
}

bool Document::is_header_complete() const {
  return header.is_section_complete();
}

bool Document::is_tasks_complete() const {
  return task_section.is_section_complete();
}
