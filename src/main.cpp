#include "preset/m_bnt_preset.hpp"

int main(int argc, char *argv[]) {
  if (argc > 1 && std::string(argv[1]) == "pt")
    MBNTPreset::run(PORTUGUESE);
  else
    MBNTPreset::run(ENGLISH);
  return 0;
}
