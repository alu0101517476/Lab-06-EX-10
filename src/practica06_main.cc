#include <iostream>

#include "../Include/Sofware.h"

void ayuda() {
  std::cout << "Este programa implementa el funcionamiento de un software de "
               "gestión de red de bibliotecas\n Para ejecutar este programa "
               "debe incluir un .txt con un catálogo de libros y ejecutar "
               "./Software 'ruta y nombre fichero libros'"
            << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Error, el número de parámetros es incorrecto. \nPruebe a "
                 "ejecutar './Software --help para obtener más información"
              << std::endl;

    return 1;
  }
  if (static_cast<std::string>(argv[1]) == "--help") {
    ayuda();
    return 0;
  }
  Software software_red_bibliotecas{static_cast<std::string>(argv[1]), static_cast<std::string>(argv[2])};
  software_red_bibliotecas.menu();
  return 0;
}