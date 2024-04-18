#include "../Include/Sala.h"

bool Sala::cambiarDisponibilidad(int numero_ocupantes) {
  if (numero_ocupantes < aforo_ && disponibilidad_) {
    std::cout << "La sala se ha ocupado con " << numero_ocupantes << " personas" << std::endl;
    disponibilidad_ = false;
    return true;
  }
  if (disponibilidad_ == false) {
    std::cout << "La sala se encuentra ocupada" << std::endl;
    return false;
  }
  std::cout << "No se puede ocupar la sala con más personas de las permitidas" << std::endl;
  disponibilidad_ = false;
}
