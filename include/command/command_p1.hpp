#ifndef COMMAND_P1_HPP
#define COMMAND_P1_HPP

#include "command/m_bnt_command.hpp"

class CommandP1 : public MBNTCommand {
public:
  CommandP1(Document *document);
  void run_command(std::string content = "");
};

#endif
