#include "../Include/Sofware.h"

Software::Software(Catalogo catalogo, std::set<Usuario> usuarios, std::set<Sala> salas)
      : catalogo_{catalogo}, usuarios_{usuarios}, salas_{salas} { };

Software::Software(const std::string& nombre_fichero_usuarios, const std::string& nombre_fichero_catalogo) 
                : catalogo_(nombre_fichero_catalogo), nombre_fichero_base_datos_usuario_(nombre_fichero_usuarios) {
  for (int i{0}; i < 10; ++i) {
    Sala sala{7, i};
    salas_.insert(sala);
  }
}

void Software::menu() {
  std::string press_enter;
  char press_enter_opcion1;
  std::string nombre_usuario, password, correo;
  system("clear");
  std::cout << "\n\n\n\n\nBIENVENIDO A LA RED DE BIBLITECA\n\n\n\n";
  while (true) {
    std::cout << "         Pulsa Enter";
    if (std::getline(std::cin, press_enter) && press_enter.empty()) {
      system("clear");
      while (true) {
        std::cout << "\n¿Qué acción deseas realizar?\n\n";
        std::cout << " 1) Iniciar sesión\n";
        std::cout << " 2) Crear cuenta\n";
        std::cout << " 3) Salir\n\n";
        std::cout << "Opción: ";
        //            Usuario usuario;
        int opcion_inicio, opcion_segunda;
        std::cin >> opcion_inicio;
        switch (opcion_inicio) {
          case 1:
            system("clear");
            std::cout << "Iniciando sesión...";
            // funcion iniciar_sesion()
            while (true) {
              std::cout << "\n\nPulsa C (continuar): ";
              std::cin >> press_enter_opcion1;
              if (press_enter_opcion1 == 67 || press_enter_opcion1 == 99) {
                system("clear");
                std::cout << "¿Qué acción deseas realizar?\n\n";
                std::cout << " 1) Solicitar préstamo\n";
                std::cout << " 2) Realizar devolución\n";
                std::cout << " 3) Consultar catálogo\n";
                std::cout << " 4) Reserva de sala\n";
                std::cout << " 5) Cerrar sesión\n\n";
                std::cout << "Opción: ";
                std::cin >> opcion_segunda;
                switch (opcion_segunda) {
                  case 1:
                    system("clear");
                    // funcion prestamoLibros()
                    continue;
                  case 2:
                    system("clear");
                    // funcion devolucion()
                    continue;
                  case 3:
                    system("clear");
                    // funcion buscarLibro()
                    continue;
                  case 4:
                    system("clear");
                    // funcion reservaSala()
                    continue;
                  case 5:
                    system("clear");
                    std::cout << "Cerrando sesión...\n";
                    while (true) {
                      std::cout << "\n\nPulsa C (continuar): ";
                      std::cin >> press_enter_opcion1;
                      if (press_enter_opcion1 == 67 ||
                          press_enter_opcion1 == 99) {
                        break;
                      } else {
                        system("clear");
                        std::cout << "Tecla incorrecta";
                        continue;
                      }
                    }
                    system("clear");
                    break;
                  default:
                    system("clear");
                    std::cout << "Error: Opción incorrecta\n\n";
                    break;
                }
                break;
              } else {
                system("clear");
                std::cout << "Tecla incorrecta";
                continue;
              }
            }
            break;
          case 2:
            system("clear");
            std::cout << "Introduzca el nombre de usuario: ";
            std::cin >> nombre_usuario;
            std::cout << "Introduzca la contraseña del usuario: ";
            std::cin >> password;
            std::cout << "Introduzca el correo del usuario: ";
            std::cin >> correo;
            std::cout << "Creando cuenta...";
            crearUsuario_(nombre_fichero_base_datos_usuario_, nombre_usuario, password, correo);
            while (true) {
              std::cout << "\n\nPulsa C (continuar): ";
              std::cin >> press_enter_opcion1;
              if (press_enter_opcion1 == 67 || press_enter_opcion1 == 99) {
                break;
              } else {
                system("clear");
                std::cout << "Tecla incorrecta";
                continue;
              }
            }
            system("clear");
            break;
          case 3:
            system("clear");
            std::cout << "Termina el programa\n\n";
            exit(1);
          default:
            system("clear");
            std::cout << "Error: Opción incorrecta\n\n";
            break;
        }
      }
    } else {
      system("clear");
      std::cout << "Tecla incorrecta\n\n";
      continue;
    }
  }
}

bool Software::iniciarSesion_(const std::string& nombre_fichero_usuarios, const std::string& nombre_usuario, const std::string& password) {
  std::ifstream fichero_usuario{nombre_fichero_usuarios, std::ios::in};
  std::string linea, nombre_usuario_x;
  while (fichero_usuario >> nombre_usuario_x) {
    if (nombre_usuario == nombre_usuario_x) {
      std::string password_x;
      fichero_usuario >> password_x;
      if (password_x == password) {
        std::cout << "Inicio de sesión satisfactorio" << std::endl;
        fichero_usuario.close();
        return true;
      }
      else {
        std::cout << "No se ha podido iniciar sesión. Contraseña incorrecta" << std::endl;
        fichero_usuario.close();
        return false;
      }
    }
    std::getline(fichero_usuario, linea);
  }
  std::cout << "No se ha encontrado el usuario. No se ha iniciado sesión" << std::endl;
  fichero_usuario.close();
  return false;
}

bool Software::crearUsuario_(const std::string& nombre_fichero_usuarios, const std::string& nombre_usuario, const std::string& password, const std::string& correo) {
  bool usuario_correo_existentes{false};
  std::ifstream fichero_usuario{nombre_fichero_usuarios, std::ios::in};
  std::string linea, nombre_usuario_x;
  while (fichero_usuario >> nombre_usuario_x) {
    std::getline(fichero_usuario, linea);
    if (nombre_usuario == nombre_usuario_x) {
      usuario_correo_existentes = true;
      std::cout << "El correo que ha intrucido se encuentra en uso, prueba a introducir otro correo" << std::endl;
      return false;
    }
  }
  if (!usuario_correo_existentes) {
    Usuario usuario(nombre_usuario, password, correo);
    usuarios_.insert(usuario);
  }
  fichero_usuario.close();
  std::ofstream fichero_usuario_(nombre_fichero_usuarios, std::ios::app);
  fichero_usuario_ << nombre_usuario << " " << password << " " << correo << std::endl;
  fichero_usuario_.close();
  std::cout << "Cuenta creada satisfactoriamente." << std::endl;
  return true;
}

bool Software::prestamoLibros_(const std::string& nombre_usuario, const std::string& titulo_libro) {
  for (const auto& libro : catalogo_.getLibros()) {
    if (libro.getTitulo() == titulo_libro && libro.estaDisponible()) {
      for (auto usuario : usuarios_) {
        if (usuario.getNombreUsuario() == nombre_usuario) {
          usuario.introducirLibro(libro);
          return true;  
        }
      }
    }
  }
  return false;
}

bool Software::reservaSala_(int numero_ocupantes, int identificador_sala) {
  for (auto sala : salas_) {
    if (identificador_sala == sala.getIdentificador() && sala.estaDisponible()) {
      return sala.cambiarDisponibilidad(numero_ocupantes);
    }
  }
  return false;
}

bool Software::devolucion_(const std::string& nombre_usuario, const std::string& titulo_libro) {
  for (const auto& libro : catalogo_.getLibros()) {
    for (auto usuario : usuarios_) {
      if (usuario.getNombreUsuario() == nombre_usuario) {
        usuario.eliminarLibro(libro);
        return true;
      }
    }
  }
  return false;
}