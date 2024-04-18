#pragma once

#include <iostream>
#include <string>

class Libro {
 public:
  Libro(std::string titulo, int unidades, int codigo) : titulo_(titulo) {}
  // getters
  std::string getTitulo() const { return titulo_; }
  bool estaDisponible() const { return disponibilidad_; }

 private:
  std::string titulo_;
  bool disponibilidad_;
};