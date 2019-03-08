#ifndef COMMAND_FINISH_HPP
#define COMMAND_FINISH_HPP

#include "command/m_bnt_command.hpp"

class CommandFinish : public MBNTCommand {
public:
  CommandFinish(std::string description, Document *document,
                DocumentPrinter *document_printer);
  bool run_command(std::string content = "");
};

#endif
