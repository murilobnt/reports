#include "section/header.hpp"

bool Header::is_section_complete() const {
  return ((title == "" || date == "" || description == "") ? false : true);
}
