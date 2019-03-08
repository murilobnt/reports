#ifndef COMMAND_INTERPRETER_HPP
#define COMMAND_INTERPRETER_HPP

#include <map>
#include <string>

#include "command/command.hpp"

class Application;

class CommandInterpreter {
protected:
  std::map<std::string, Command *> commands;
  std::string state_marker;

public:
  bool interpret(std::string command, std::string content);
  void set_state_marker(std::string state_marker);
  std::string get_state_marker() const;
  std::map<std::string, Command *> get_commands() const;
};

#endif
