#include "../Include/Catalogo.h"

Catalogo::Catalogo(const std::string& nombre_fichero_catalogo) {
  std::ifstream fichero_catalogo{nombre_fichero_catalogo, std::ios::in};
  std::string linea;
  while (fichero_catalogo >> linea) {
    int numero = std::stoi(linea);
    std::getline(fichero_catalogo, linea);
    Libro libro_nuevo{linea, numero};
    libros_.insert(libro_nuevo); 
  }
  fichero_catalogo.close();
}

void Catalogo::Mostrar() const {
  int i{1};
  for (const auto& libro : libros_) {
    libro.Print();
    ++i;
  }
}
std::string Catalogo::getLibro(int id) {
  for (const auto& libro: libros_) {
    if (libro.getId() == id) {return libro.getTitulo();}
  }
 }
