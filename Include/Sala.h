#pragma once

#include <iostream>

class Sala {
 public:
  Sala(int aforo) : aforo_(aforo), disponibilidad_(true) {}
  bool cambiarDisponibilidad(int numero_ocupantes); 
  // getters
  bool estaDisponible() const { return disponibilidad_; }
  int getIdentificador() const { return identificador_; }
 private:
  int aforo_;
  bool disponibilidad_;
  int identificador_;
};