#include "command/command_p1.hpp"

CommandP1::CommandP1(std::string description, Document *document)
    : MBNTCommand(description) {
  this->document = document;
}

bool CommandP1::run_command(std::string content) {
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
  return true;
}
