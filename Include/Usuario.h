#pragma once

#include <iostream>
#include <set>

#include "Libro.h"

class Usuario {
 public:
  Usuario() { };
  Usuario(std::string nombre_usuario, std::string contrasena,
          std::string correo)
      : nombre_usuario_(nombre_usuario),
        contrasena_(contrasena),
        correo_(correo){};
  std::string getNombreUsuario() const { return nombre_usuario_; }
  std::string getContrasena() const { return contrasena_; }
  std::string getCorreo() const { return correo_; }
  void setNombreUsuario(std::string& nombre_usuario) {
    nombre_usuario_ = nombre_usuario;
  }
  void setContrasena(std::string& contrasena) { contrasena_ = contrasena; }
  void setCorreo(std::string& correo) { correo_ = correo; }
  void introducirLibro(const Libro& libro);
  void eliminarLibro(const Libro& libro);
  bool operator<(const Usuario& usuario2) const;
  bool operator>(const Usuario& usuario2) const;
  bool operator>=(const Usuario& usuario2) const;

 private:
  std::string nombre_usuario_;
  std::string contrasena_;
  std::string correo_;
  std::set<Libro> libros_adquiridos_;
};