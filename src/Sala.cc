#include "../Include/Sala.h"

bool Sala::cambiarDisponibilidad(int numero_ocupantes) {
  if (!disponibilidad_ || numero_ocupantes > aforo_ || numero_ocupantes < 0) {
    std::cout << "Ha ocurrido un error al reservar la sala, intentelo de nuevo" << std::endl;
    return false;
  } 
  std::cout << "La sala se ha ocupado con " << numero_ocupantes << " personas" << std::endl;
  disponibilidad_ = false;
  return true;  
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
