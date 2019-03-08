#include "command/command.hpp"

Command::Command(std::string description) { this->description = description; }

std::string Command::get_description() const { return description; }
