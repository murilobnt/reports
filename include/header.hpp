#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>

#include "document_section.hpp"

struct Header : DocumentSection {
  std::string title;
  std::string date;
  std::string description;

  bool is_section_complete();
};

#endif
