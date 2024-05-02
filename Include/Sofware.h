#pragma once

#include <iostream>
#include <set>
#include <string>
#include <limits>
#include <map>
#include <unistd.h>
#include <stdio.h>

#include "colors.h"
#include "Catalogo.h"
#include "Sala.h"
#include "Usuario.h"

class Software {
 public:
  Software(Catalogo catalogo, std::set<Usuario> usuarios, std::set<Sala> salas);
  Software(const std::string& nombre_fichero_usuarios, const std::string& nombre_fichero_catalogo);
  void menu();

 private:
  bool iniciarSesion_(const std::string& nombre_fichero_usuarios, const std::string& nombre_usuario, const std::string& password);
  bool crearUsuario_(const std::string& nombre_fichero_usuarios, const std::string& nombre_usuario, const std::string& password, const std::string& correo);
  bool prestamoLibros_(const std::string& nombre_usuario, const std::string& titulo_libro);
  bool reservaSala_(int numero_ocupantes, const std::string& mes, int identificador_sala, int dia_sala, int hora_sala);
  bool devolucion_(const std::string& nombre_usuario, const std::string& titulo_libro);
  bool buscarLibro_(const std::string& titulo_libro);
  bool reservaValida_(const std::string& mes, const int dia, int hora);
  // atributos
  Catalogo catalogo_;
  std::string nombre_fichero_base_datos_usuario_;
  std::set<Usuario> usuarios_;
  std::set<Sala> salas_;
};