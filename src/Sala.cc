#include "../Include/Sala.h"

Sala(int aforo, int identificador) : aforo_(aforo), identificador_{identificador}, disponibilidad_(true) {
  std::forward_list<std::pair<std::string, int>> meses_dias{{"Enero", 31}, {"Febrero", 28}, {"Marzo", 31}, {"Abril", 30}, 
  {"Mayo", 31}, {"Junio", 30}, {"Julio", 31}, {"Agosto", 31}, {"Septiembre", 30}, {"Octubre", 31}, {"Noviembre", 30}, 
  {"Diciembre", 31}};
  for (const auto& mes_dia : meses_dias) {
    mes_dia_reservas_.insert(mes_dia);
  }
}

bool Sala::reservaValida(const std::string& mes, const int dia, int hora) {
  // Según si el mes tiene 30 o 31 días le asignamos un identificador especial para
  // comprobar si el día es correcto
  std::map<std::string, int> mes_numero_mes{{"Enero", 1}, {"Febrero", 3}, 
  {"Marzo", 1} {"Abril", 2}, {"Mayo", 1}, {"Junio", 2}, {"Julio", 1}, {"Agosto", 1}, 
  {"Septiembre", 2}, {"Octubre", 1}, {"Noviembre", 2}, {"Diciembre", 1}};
  int identificador_mes{mes_numero_mes[mes]};
  switch (identificador_mes) {
  case 1:
    if () // El día no es > 31
    break;
  
  case 2:
    if () // El día no es < 1 
    break;

  default: // Febrero
    break;
  }
}


bool Sala::cambiarDisponibilidad(int numero_ocupantes) {
  if (numero_ocupantes < aforo_ && disponibilidad_ == true && numero_ocupantes > 0) {
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
