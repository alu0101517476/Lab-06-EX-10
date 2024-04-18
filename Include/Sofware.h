#pragma once

#include <iostream>
#include <set>

#include "Catalogo.h"
#include "Usuario.h"
#include "Sala.h"

class Software {
 public:
  void menu();

 private:
  bool iniciarSesion_();
  bool crearUsuario_();
  bool prestamoLibros_();
  bool reservaSala_(int numero_ocupantes, int identificador_sala);
  bool devolucion_();
  Catalogo catalogo_;
  std::set<Usuario> usuarios_;
  std::set<Sala> salas_;
};