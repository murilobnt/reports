#ifndef DOCUMENT_SECTION_HPP
#define DOCUMENT_SECTION_HPP

struct DocumentSection {
  virtual bool is_section_complete() const = 0;
};

#endif
