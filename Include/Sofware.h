#pragma once

#include <iostream>
#include <set>

#include "Catalogo.h"
#include "Sala.h"
#include "Usuario.h"

class Software {
 public:
  Software(Catalogo catalogo, std::set<Usuario> usuarios, std::set<Sala> salas)
      : catalogo_{catalogo}, usuarios_{usuarios}, salas_{salas} {}
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