#ifndef COMMAND_P2_HPP
#define COMMAND_P2_HPP

#include "command/m_bnt_command.hpp"

class CommandP2 : public MBNTCommand {
public:
  CommandP2(std::string description, Document *document);
  bool run_command(std::string content = "");
};

#endif
