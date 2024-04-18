#pragma once

#include<iostream>
#include<vector>
#include<string>

class Usuario {
  public:
    Usuario(std::string nombre_usuario, std::string contrasena, std::string correo) : nombre_usuario_(nombre_usuario), contrasena_(contrasena), correo_(correo) { };
    std::string getNombreUsuario() const { return nombre_usuario_; } 
    std::string getContrasena() const { return contrasena_; }
    std::string getCorreo() const { return correo_; }
    void setNombreUsuario(std::string& nombre_usuario) { nombre_usuario_ = nombre_usuario; }
    void setContrasena(std::string& contrasena) { contrasena_ = contrasena; }
    void setCorreo(std::string& correo) { correo_ = correo; }
    //void BuscarLibro(std::string& libro) {     }HAce falta saber más sobre la organización general para hacer esta función :)
  private:
    std::string nombre_usuario_;
    std::string contrasena_;
    std::string correo_;
}; 