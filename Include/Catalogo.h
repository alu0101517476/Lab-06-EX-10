#pragma once

#include <iostream>
#include <set>

#include "Libro.h"

class Catalogo {
 public:
  Catalogo(std::string fichero_catalogo);
  std::set<Libro> getLibros() const { return libros_; }

 private:
  std::set<Libro> libros_;
};