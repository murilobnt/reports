#include "interpreter/document_command_interpreter.hpp"

DocumentCommandInterpreter::DocumentCommandInterpreter(Application *application,
                                                       Document *document)
    : CommandInterpreter(application, document) {}

DocumentCommand
DocumentCommandInterpreter::string_to_command(std::string m_string) {
  if (m_string == "p1")
    return P1;
  if (m_string == "p2")
    return P2;
  if (m_string == "title")
    return TITLE;
  if (m_string == "date")
    return DATE;
  if (m_string == "description")
    return DESCR;
  if (m_string == "addtask")
    return ADDTASK;
  if (m_string == "finish")
    return FINISH;
  if (m_string == "status")
    return STATUS;
  else
    return INVALID;
}

void DocumentCommandInterpreter::p1() {
  std::string title, date, description;
  std::cout << "Title: ";
  std::getline(std::cin, title);
  std::cout << "Date: ";
  std::getline(std::cin, date);
  std::cout << "Description: ";
  std::getline(std::cin, description);
  document->set_title(title);
  document->set_date(date);
  document->set_description(description);
}

bool DocumentCommandInterpreter::interpret(std::string command,
                                           std::string content) {
  switch (string_to_command(command)) {
  case P1:
    p1();
    break;
  case P2:
    return false;
    break;
  case TITLE:
    if (content == "")
      std::cout << "Title: " << document->get_title() << std::endl;
    else
      document->set_title(content);
    break;
  case DATE:
    if (content == "")
      std::cout << "Date: " << document->get_date() << std::endl;
    else
      document->set_date(content);
    break;
  case DESCR:
    if (content == "")
      std::cout << "Description: " << document->get_description() << std::endl;
    else
      document->set_description(content);
    break;
  case ADDTASK:
    return false;
    break;
  case FINISH:
    return false;
    break;
  case STATUS:
    std::cout << "Header status: "
              << (document->is_header_complete() ? "Complete." : "Incomplete.")
              << std::endl
              << "Task section status: "
              << (document->is_tasks_complete() ? "Complete." : "Incomplete.")
              << std::endl
              << "Document status: "
              << (document->is_complete() ? "Complete." : "Incomplete.")
              << std::endl;
    break;
  default:
    return false;
    break;
  }
  return true;
}

std::string DocumentCommandInterpreter::get_state_marker() { return "."; }
