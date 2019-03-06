#ifndef DOCUMENT_PRINTER_HPP
#define DOCUMENT_PRINTER_HPP

#include <string>

#include "document.hpp"

class DocumentPrinter {
public:
  virtual void print_document(std::string file_name,
                              const Document &document) = 0;
};

#endif
