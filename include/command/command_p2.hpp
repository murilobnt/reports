#ifndef COMMAND_P2_HPP
#define COMMAND_P2_HPP

#include "command/m_bnt_command.hpp"

class CommandP2 : public MBNTCommand {
public:
  CommandP2(Document *document);
  void run_command(std::string content = "");
};

#endif
