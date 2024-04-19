#include "../Include/Catalogo.h"

Catalogo::Catalogo(const std::string& nombre_fichero_catalogo) {
  std::ifstream fichero_catalogo{nombre_fichero_catalogo, std::ios::in};
  std::string linea;
  while (std::getline(fichero_catalogo, linea)) {
    Libro libro_nuevo{linea};
    libros_.insert(libro_nuevo); 
  }
  fichero_catalogo.close();
}
