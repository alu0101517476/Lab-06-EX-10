#pragma once

#include <iostream>
#include <string>

class Libro {
 public:
  Libro(std::string titulo, int id, bool disponibilidad = true) : titulo_(titulo), id_(id), disponibilidad_{disponibilidad} {}
  // getters
  std::string getTitulo() const { return titulo_; }
  int getId() const { return id_; }
  bool estaDisponible() const { return disponibilidad_; }
  bool operator<(const Libro& libro2) const;
  bool operator>(const Libro& libro2) const;
  bool operator>=(const Libro& libro2) const;
  void Print() const;
 private:
  std::string titulo_;
  int id_;
  bool disponibilidad_;
};