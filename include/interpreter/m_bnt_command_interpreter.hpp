#ifndef M_BNT_COMMAND_INTERPRETER_HPP
#define M_BNT_COMMAND_INTERPRETER_HPP

#include "command/command_finish.hpp"
#include "command/command_p1.hpp"
#include "command/command_p2.hpp"
#include "interpreter/command_interpreter.hpp"

class MBNTCommandInterpreter : public CommandInterpreter {
public:
  MBNTCommandInterpreter(Application *application, Document *document,
                         DocumentPrinter *document_printer);
  ~MBNTCommandInterpreter();
};

#endif
