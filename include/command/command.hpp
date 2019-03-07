#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command {
public:
  virtual void run_command(std::string content) = 0;
};

#endif
