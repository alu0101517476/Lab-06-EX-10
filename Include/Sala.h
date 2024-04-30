#pragma once

#include <iostream>

class Sala {
 public:
  Sala(int aforo, int identificador) : aforo_(aforo), identificador_{identificador}, disponibilidad_(true) {};
  bool cambiarDisponibilidad(int numero_ocupantes); 
  // getters
  bool estaDisponible() const { return disponibilidad_; }
  int getIdentificador() const { return identificador_; }
  bool operator<(const Sala& sala) const;
  bool operator>(const Sala& sala) const;
  bool operator>=(const Sala& sala) const;
 private:
  int aforo_;
  bool disponibilidad_;
  int identificador_;
};
