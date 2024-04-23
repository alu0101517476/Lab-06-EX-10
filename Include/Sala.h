#pragma once

#include <iostream>
#include <unordered_map>
#include <forward_list>

class Sala {
 public:
  Sala(int aforo, int identificador);
  bool cambiarDisponibilidad(int numero_ocupantes); 
  bool reservaValida(const std::string& mes, const dia, int hora);
  // getters
  bool estaDisponible() const { return disponibilidad_; }
  int getIdentificador() const { return identificador_; }
  bool operator<(const Sala& sala) const;
  bool operator>(const Sala& sala) const;
  bool operator>=(const Sala& sala) const;
 private:
  std::unordered_map<std::string, int> mes_dia_reservas_;
  int aforo_;
  bool disponibilidad_;
  int identificador_;
};
