#pragma once

#include <iostream>
#include <string>

class Libro {
 public:
  Libro(std::string titulo, bool disponibilidad = true) : titulo_(titulo), disponibilidad_{disponibilidad} {}
  // getters
  std::string getTitulo() const { return titulo_; }
  bool estaDisponible() const { return disponibilidad_; }
  bool operator<(const Libro& libro2) const;
  bool operator>(const Libro& libro2) const;
  bool operator>=(const Libro& libro2) const;

 private:
  std::string titulo_;
  bool disponibilidad_;
};