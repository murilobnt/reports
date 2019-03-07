#include "application/application.hpp"

void Application::run(CommandInterpreter *command_interpreter) {
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
}
