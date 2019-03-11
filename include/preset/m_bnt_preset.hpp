#ifndef M_BNT_PRESET_HPP
#define M_BNT_PRESET_HPP

#include "application/application.hpp"
#include "interpreter/m_bnt_command_interpreter.hpp"
#include "printer/m_bnt_markdown_printer.hpp"

class MBNTPreset {
public:
  static void run(Language language);
};

#endif
