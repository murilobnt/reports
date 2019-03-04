#include "header.hpp"

bool Header::is_section_complete() {
  return ((title == "" || date == "" || description == "") ? false : true);
}
