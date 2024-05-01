#include <iostream>

#include "../Include/Sofware.h"

void ayuda() {
  std::cout << "Este programa implementa el funcionamiento de un software de "
               << "gestión de red de bibliotecas\n Para ejecutar este programa "
               << "debe incluir un .txt con un catálogo de libros, un fichero con los usuarios "
               << "y ejecutar " <<
               "./Software 'ruta y nombre fichero libros' 'ruta y nombre fichero usuarios"
            << std::endl;
}

int main(int argc, char* argv[]) {
  if (static_cast<std::string>(argv[1]) == "--help") {
    ayuda();
    return 0;
  }
  if (argc != 3) {
    std::cerr << "Error, el número de parámetros es incorrecto. \nPruebe a "
              <<   "ejecutar './Software --help para obtener más información"
              << std::endl;

    return 1;
  }
  std::string nombre_fichero_catalogo{argv[1]}, nombre_fichero_usuarios{argv[2]};
  std::cout << nombre_fichero_catalogo << ' ' << nombre_fichero_usuarios << std::endl;
  Software software_red_bibliotecas{nombre_fichero_catalogo, nombre_fichero_usuarios};
  /*
  software_red_bibliotecas.menu();
  */
  return 0;
}
