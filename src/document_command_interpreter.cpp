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

void DocumentCommandInterpreter::p2() {
  std::string choice = "n";
  do {
    Task task;

    std::cout << "Title: ";
    std::getline(std::cin, task.title);
    if (task.title == "cancel")
      break;
    std::cout << "Description: ";
    std::getline(std::cin, task.description);
    if (task.description == "cancel")
      break;
    std::cout << "Completion % (number only): ";
    std::cin >> task.completion;
    std::cin.ignore();
    std::cout << "Notes: ";
    std::getline(std::cin, task.notes);
    if (task.notes == "cancel")
      break;
    document->add_task(task);
    std::cout << "Add more? (y/N): ";
    std::getline(std::cin, choice);
  } while (choice == "y");
}

void DocumentCommandInterpreter::finish() {
  std::string file_name;
  std::cout << "Name of the file: " << std::endl;
  std::getline(std::cin, file_name);
  document_printer->print_document(file_name, *document);
}

bool DocumentCommandInterpreter::interpret(std::string command,
                                           std::string content) {
  switch (string_to_command(command)) {
  case P1:
    p1();
    break;
  case P2:
    p2();
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
    finish();
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
