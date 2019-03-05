#include "application/application.hpp"

Application::Application() {
  command_interpreter = new DocumentCommandInterpreter(this, &document);
}

void Application::run() {
  while (true) {
    std::string input;
    char delimiter = ' ';
    std::cout << command_interpreter->get_state_marker();
    std::getline(std::cin, input);
    if (input == "exit")
      break;

    std::string command = "";
    std::string content = "";

    if (input.find(delimiter) != std::string::npos) {
      command = input.substr(0, input.find(delimiter));
      content = input.substr(input.find(delimiter) + 1, input.length());
    } else {
      command = input;
    }

    std::cout << (command_interpreter->interpret(command, content) ? "OK."
                                                                   : "Error.")
              << std::endl;
  }
  finish();
}

void Application::set_command_interpreter(
    CommandInterpreter *command_interpreter) {
  this->command_interpreter = command_interpreter;
}

void Application::finish() { delete command_interpreter; }
