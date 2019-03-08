#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command {
private:
  std::string description;

public:
  Command(std::string description);
  std::string get_description() const;
  virtual bool run_command(std::string content) = 0;
};

#endif
