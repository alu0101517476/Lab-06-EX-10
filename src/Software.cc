#include "../Include/Sofware.h"

void Software::menu() {
  std::string press_enter;
  char press_enter_opcion1;
  std::string nombre_usuario, contraseña;
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
            std::cout << "Creando cuenta...";
            // funcion crear_usuario()
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

bool Software::iniciarSesion_() {
  std::string nombre_o_correo_usuario, contraseña;
  std::cout << "Introduce tu nombre de usuario o correo: ";
  std::cin >> nombre_o_correo_usuario;
  std::cout << "Introduce tu contraseña: ";
  std::cin >> contraseña;
  for (const auto& usuario : usuarios_) {
    if ((usuario.getNombreUsuario() == nombre_o_correo_usuario || usuario.getCorreo() == nombre_o_correo_usuario) &&
        usuario.getContrasena() == contraseña) {
      return true;
    }
  }
  return false;
}

bool Software::crearUsuario_() {
  bool usuario_correo_existentes{false};
  std::string nombre_usuario, contraseña, correo;
  do {
    std::cout << "Introduce tu nombre de usuario: ";
    std::cin >> nombre_usuario;
    std::cout << "Introduce tu contraseña: ";
    std::cin >> contraseña;
    std::cout << "Introduce tu correo: ";
    std::cin >> correo;
    for (const auto& usuario : usuarios_) {
      if (usuario.getNombreUsuario() == nombre_usuario) {
        usuario_correo_existentes = true;
        std::cout << "El nombre de usuario se encuentra en uso, prueba a introducir otro nombre de usuario" << std::endl;
        break;
      }
      if (usuario.getCorreo() == correo) {
        usuario_correo_existentes = true;
        std::cout << "El correo que ha intrucido se encuentra en uso, prueba a introducir otro correo" << std::endl;
        break;
      }
    }
  } while(usuario_correo_existentes);
  Usuario usuario(nombre_usuario, contraseña, correo);
  usuarios_.insert(usuario);
  return true;
}

bool Software::prestamoLibros_() {
  std::string titulo_libro;
  std::cout << "Introduce el libro que deseas solicitar: ";
  std::cin >> titulo_libro;
  for (const auto& libro : catalogo_.getLibros()) {
    if (libro.getTitulo() == titulo_libro && libro.estaDisponible()) {
      return true;
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

bool Software::devolucion_() {
  
}