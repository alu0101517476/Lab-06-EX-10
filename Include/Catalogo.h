#pragma once

#include <iostream>
#include <set>
#include <fstream>

#include "Libro.h"

class Catalogo {
 public:
  Catalogo(const std::string& nombre_fichero_catalogo);
  std::set<Libro> getLibros() const { return libros_; }

 private:
  std::set<Libro> libros_;
};