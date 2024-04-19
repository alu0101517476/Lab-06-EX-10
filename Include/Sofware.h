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
  Software(const std::string& nombre_fichero_catalogo);
  void menu();

 private:
  bool iniciarSesion_(const std::string& nombre_o_correo_usuario, const std::string& password);
  bool crearUsuario_(const std::string& nombre_usuario, const std::string& password, const std::string& correo);
  bool prestamoLibros_(const std::string& nombre_usuario, const std::string& titulo_libro);
  bool reservaSala_(int numero_ocupantes, int identificador_sala);
  bool devolucion_(const std::string& nombre_usuario, const std::string& titulo_libro);
  // atributos
  Catalogo catalogo_;
  std::set<Usuario> usuarios_;
  std::set<Sala> salas_;
};