#include "../Include/Usuario.h"

void Usuario::introducirLibro(const Libro& libro) {
  libros_adquiridos_.insert(libro);
}

void Usuario::eliminarLibro(const Libro& libro) {
  libros_adquiridos_.erase(libro);
}

bool Usuario::operator<(const Usuario& usuario2) const {
  return nombre_usuario_ < usuario2.getNombreUsuario();
}

bool Usuario::operator>(const Usuario& usuario2) const {
  return nombre_usuario_ > usuario2.getNombreUsuario();
}
  
bool Usuario::operator>=(const Usuario& usuario2) const {    
  return nombre_usuario_ >= usuario2.getNombreUsuario();
}
