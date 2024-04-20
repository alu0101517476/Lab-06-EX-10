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
  std::string nombre_usuario, password, correo, titulo_libro;
  int numero_ocupantes, identificador_sala;
  Usuario usuario;
  system("clear");
  std::cout << "\n\n\n\n\nBIENVENIDO A LA RED DE BIBLIOTECAS\n\n\n\n";
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
            std::cout << "Iniciando sesión..." << std::endl;
            std::cout << "Introduzca el nombre de usuario: ";
            std::cin >> nombre_usuario;
            std::cout << "Introduzca la contraseña del usuario: ";
            std::cin >> password;
            std::cout << "Iniciando sesión..." << std::endl;
            usuario.setCorreo(correo);
            usuario.setContrasena(password);
            usuario.setNombreUsuario(nombre_usuario);
            if (!iniciarSesion_(nombre_fichero_base_datos_usuario_, nombre_usuario, password)) { break; }
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
                    std::cout << "Indique el nombre del libro que desea reservar: ";
                    std::cin >> titulo_libro;
                    if (prestamoLibros_(nombre_usuario, titulo_libro)) {
                      std::cout << "El libro está disponible para recogida presencial." << std::endl;
                    } else {
                      std::cout << "No se puede llevar a cabo el préstamos, pruebe en otro momento. Disculpe por las molestias." << std::endl;
                    }
                    continue;
                  case 2:
                    system("clear");
                    std::cout << "¿Cuál es el título del libro que vas a devolver? ";
                    std::cin >> titulo_libro;
                    if (devolucion_(nombre_usuario, titulo_libro)) {
                      std::cout << "El libro se ha devuelto satisfactoriamente" << std::endl;
                    }
                    else {
                      std::cout << "Ha habido algún problema en la devolución. Inténtelo de nuevo más tarde." << std::endl;
                    }
                    continue;
                  case 3:
                    system("clear");
                     // buscarLibro()  ¿¿¿¿¿¿¿¿¿¿¿¿¿Y la función???????????????????
                    continue;
                  case 4:
                    system("clear");
                    std::cout << "¿Cuántos van a reservar la sala? ";
                    std::cin >> numero_ocupantes;
                    std::cout << "¿Qué sala quieres reservar?" << std::endl;
                    std::cin >> identificador_sala;
                    if (reservaSala_(numero_ocupantes, identificador_sala)) {          //¿¿¿¿¿¿¿¿Y el día???????    ¿Y la hora?
                      std::cout << "Reserva confirmada." << std::endl;
                    }
                    else {
                      std::cout << "Ha habido un problema con la reserva. Inténtelo de nuevo más tarde." << std::endl;
                    }
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