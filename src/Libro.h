#pragma once

#include <iostream>
#include <string>

class Libro {
 public:
  Libro(std::string titulo, int unidades, int codigo) : titulo_(titulo), unidades_(unidades), codigo_(codigo) {}
  // getters
  std::string getTitulo() const { return titulo_; }
  int getCodigo() const { return codigo_; }
  int getUnidades() const { return unidades_; }
 private:
  std::string titulo_;
  //int unidades_;
  int codigo_; // Se puede poner como int o como prefieran
};