#pragma once

#include<iostream>
#include<vector>
#include<string>

class Usuario {
  public:
    Usuario(std::string nombre_usuario, std::string contrasena, std::string correo) : nombre_usuario_(nombre_usuario), contrasena_(contrasena), correo_(correo) { };
    std::string get_nombre_usuario_() { return nombre_usuario_; } //Devuelve el nombre de usuario
    std::string get_contrasena_() { return contrasena_; }
    std::string get_correo_() { return correo_; }
    void set_nombre_usuario_(std::string& nombre_usuario) { nombre_usuario_ = nombre_usuario; }
    void set_contrasena_(std::string& contrasena) { contrasena_ = contrasena; }
    void set_correo_(std::string& correo) { correo_ = correo; }
    //void BuscarLibro(std::string& libro) {     }HAce falta saber más sobre la organización general para hacer esta función :)
  private:
    std::string nombre_usuario_;
    std::string contrasena_;
    std::string correo_;

}; 