#include "command/command_p2.hpp"

CommandP2::CommandP2(std::string description, Document *document)
    : MBNTCommand(description) {
  this->document = document;
}

bool CommandP2::run_command(std::string content) {
  std::string choice = "n";
  std::cout << "Submit a task." << std::endl;
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
  return true;
}
