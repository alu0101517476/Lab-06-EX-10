#include "../Include/Sala.h"

bool Sala::cambiarDisponibilidad(int numero_ocupantes) {
  if (numero_ocupantes < aforo_ && disponibilidad_ == true) {
    std::cout << "La sala se ha ocupado con " << numero_ocupantes << " personas" << std::endl;
    disponibilidad_ = false;
    return true;
  } 
  else {
    std::cout << "El aforo máximo para esa sala es de " << aforo_ << std::endl;
    return false;
  }
  if (disponibilidad_ == false) {
    std::cout << "La sala se encuentra ocupada" << std::endl;
    return false;
  }
}

bool Sala::operator<(const Sala& sala) const {
  return identificador_ < sala.getIdentificador();
}

bool Sala::operator>(const Sala& sala) const {
  return identificador_ > sala.getIdentificador();
}

bool Sala::operator>=(const Sala& sala) const {
  return identificador_ >= sala.getIdentificador();
}