#include "../Include/Sofware.h"
std::string Cifra(std::string palabra) {
  for (int i{0}; i < palabra.size(); ++i) {
    palabra[i] = palabra[i] + 30;
  }
  return palabra;
}


std::string DCifra(std::string palabra) {
  for(int i = 0; i < palabra.size(); i++) {
    palabra[i] -= 30;
  }
  return palabra; 
}
Software::Software(Catalogo catalogo, std::set<Usuario> usuarios, std::set<Sala> salas)
      : catalogo_{catalogo}, usuarios_{usuarios}, salas_{salas} { };

Software::Software(const std::string& nombre_fichero_usuarios, const std::string& nombre_fichero_catalogo) 
                : catalogo_(nombre_fichero_catalogo) {
                std::cout << " 1) Solicitar préstamo\n";
                std::cout << " 2) Realizar devolución\n";
                std::cout << " 3) Consultar catálogo\n";
                std::cout << " 4) Reserva de sala\n";
                std::cout << " 5) Cerrar sesión\n\n";
                std::cout << "Opción: ";
                std::cin >> opcion_segunda;, nombre_fichero_base_datos_usuario_(nombre_fichero_usuarios) {
  for (int i{0}; i < 10; ++i) {
    Sala sala{7, i};
    salas_.insert(sala);
  }
  std::ifstream fichero_usuario{nombre_fichero_usuarios, std::ios::in};
  std::string linea, nombre_usuario_x, password_x, correo_x;
  while (fichero_usuario >> (nombre_usuario_x)) {
    fichero_usuario >>password_x;
    std::string password = DCifra(password_x);
    Usuario usuario(nombre_usuario_x, password, correo_x);
    usuarios_.insert(usuario);
    std::getline(fichero_usuario, linea);
  }
  std::cout << "No se ha encontrado el usuario. No se ha iniciado sesión" << std::endl;
  fichero_usuario.close();
  }
}

void Software::menu() {
  std::string press_enter;
  char press_enter_opcion1;
  std::string nombre_usuario, password, correo, titulo_libro;
  int numero_ocupantes, identificador_sala, dia_sala, hora_sala, id_libro;
  Usuario usuario;
  system("clear");
  std::cout << "\n\n\n\n\nBIENVENIDO A LA RED DE BIBLIOTECAS\n\n\n\n";
  std::cout << "--> Inicia sesión en nuestra biblioteca para acceder a diferentes servicios o crea por primera vez una cuenta propia" << std::endl;
  std::cout << "--> Podrás acceder a nuestro cátalogo que ofrece una amplia variedad de árticulos, libros y revista" << std::endl;
  std::cout << "Cualquier duda comunicarse con los diferentes teléfonos de contacto:\n  +34 677 77 77 77\n +34 622 22 22 22" << std::endl; 
  while (true) {
    std::cout << "         Pulsa Enter";
    if (std::getline(std::cin, press_enter) && press_enter.empty()) {
      system("clear");
      while (true) {
        std::cout << "\n¿Qué acción deseas realizar?\n\n";
        std::cout << " 1) Iniciar sesión\n";
        std::cout << " 2) Crear cuenta\n";
        std::cout << " 3) Salir\n";
        std::cout << "Opción: ";
        int opcion_inicio, opcion_segunda;
        std::cin >> opcion_inicio;
        switch (opcion_inicio) {
          case 1:
            system("clear");
            std::cout << "Iniciando sesión..." << std::endl;
            std::cout << "Para poder llevar a cabo el inicio de sesión, es necesario ingresar las credenciales correctamente\n\nIntroduzca el nombre de usuario: ";
            std::cin >> nombre_usuario;
            std::cout << "Introduzca la contraseña del usuario: ";
            std::cin >> password;
            std::cout << "Iniciando sesión..." << std::endl;
            usuario.setCorreo(correo);
            usuario.setContrasena(password);
            usuario.setNombreUsuario(nombre_usuario);
            if (!iniciarSesion_(nombre_fichero_base_datos_usuario_, Cifra(nombre_usuario), Cifra(password))) { break; }
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
                    catalogo_.Mostrar();
                    std::cout << "Indique el identificador del libro que desea reservar (Ej: 2 (La Celestina)): ";
                    std::cin >> id_libro;
                    if (prestamoLibros_(nombre_usuario, catalogo_.getLibro(id_libro))) {
                      std::cout << "El libro está disponible para recogida presencial." << std::endl;
                    } 
                    else {
                      std::cout << "No se puede llevar a cabo el préstamo, pruebe en otro momento. Disculpe por las molestias." << std::endl;
                    }
                    // Esto evita el bucle infinito
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                  case 2:
                    system("clear");
                    catalogo_.Mostrar();
                    std::cout << "¿Cuál es el título del libro que vas a devolver? Indique el identificador ";
                    std::cin >> id_libro;
                    if (devolucion_(nombre_usuario, catalogo_.getLibro(id_libro))) {
                      std::cout << "El libro se ha devuelto satisfactoriamente." << std::endl;
                    }
                    else {
                      std::cout << "Ha habido algún problema en la devolución. Inténtelo de nuevo más tarde." << std::endl;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                  case 3:
                    system("clear");
                    std::cout << "¿Cuál es el título del libro que quieres consultar? ";
                    std::cin >> titulo_libro;
                    if (buscarLibro_(titulo_libro)) {
                      std::cout << "El libro está disponible en el catálogo" << std::endl;
                    } else {
                      std::cout << "El libro no está disponible en el catálogo" << std::endl;
                    }
                    continue;
                  case 4:
                    system("clear");
                    std::cout << "¿Cuántos van a reservar la sala? ";
                    std::cin >> numero_ocupantes;
                    std::cout << "¿Qué sala quieres reservar? ";
                    std::cin >> identificador_sala;
                    std::cout << "¿Día de la reserva? ";
                    std::cin >> dia_sala; 
                    std::cout << "¿Hora de la reserva? ";
                    std::cin >> hora_sala;
                    // if (hora_sala < 9 || hora_sala > 21) {
                      // std::cout << "Hora no accesible\n\nHorario de la biblioteca: 9:00-21:00" << std::endl;
                      // continue;
                    //}
                    if (reservaSala_(numero_ocupantes, identificador_sala, hora_sala, dia_sala)) {
                      std::cout << "Reserva realizada con éxito" << std::endl;
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
            std::cout << "Para llevar a cabo la creación de una cuenta de usuario será necesario introducir las credenciales deseadas por el usuario\n\nIntroduzca el nombre de usuario: ";
            std::cin >> nombre_usuario;
            std::cout << "Introduzca la contraseña del usuario: ";
            std::cin >> password;
            std::cout << "Introduzca el correo del usuario: ";
            std::cin >> correo;
            std::cout << "\nVerificando credenciales ingresadas";
            system("sleep(2)");
            std::cout << "\nCreando cuenta...";
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
      if (DCifra(password_x) == password) {
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
    Usuario usuario(nombre_usuario, Cifra(password), correo);
    usuarios_.insert(usuario);
  }
  fichero_usuario.close();
  std::ofstream fichero_usuario_(nombre_fichero_usuarios, std::ios::app);
  fichero_usuario_ << nombre_usuario << " " << Cifra(password) << " " << correo << std::endl;
  fichero_usuario_.close();
  std::cout << "Cuenta creada satisfactoriamente." << std::endl;
  return true;
}

bool Software::prestamoLibros_(const std::string& nombre_usuario, const std::string& titulo_libro) {
  bool prestamo_realizado = false;
  for (const auto& libro : catalogo_.getLibros()) {
    if (libro.getTitulo() == titulo_libro && libro.estaDisponible()) {
      for (auto usuario : usuarios_) {
        if (usuario.getNombreUsuario() == nombre_usuario) {
          usuario.introducirLibro(libro);
          prestamo_realizado = true;
          break; // Salir del bucle porque el préstamo se ha realizado con éxito
        }
      }
    }
  }
  return prestamo_realizado;
}

bool Software::buscarLibro_(const std::string& titulo_libro) {
  for (const auto& libro : catalogo_.getLibros()) {
    // por alguna razón no entra a este if
    if (libro.getTitulo() == titulo_libro) {
      return true;
    }
  }
  return false;
}

bool Software::reservaValida_(const std::string& mes, const int dia, int hora) {
  // Según si el mes tiene 30 o 31 días le asignamos un identificador especial para
  // comprobar si el día es correcto
  std::map<std::string, int> mes_numero_mes{{"Enero", 1}, {"Febrero", 3}, 
  {"Marzo", 1} {"Abril", 2}, {"Mayo", 1}, {"Junio", 2}, {"Julio", 1}, {"Agosto", 1}, 
  {"Septiembre", 2}, {"Octubre", 1}, {"Noviembre", 2}, {"Diciembre", 1}};
  int identificador_mes{mes_numero_mes[mes]};
  switch (identificador_mes) {
  case 1:
    if (dia <= 31) return true; // El día no es > 31
    break;
  
  case 2:
    if (dia <= 30) return true; // El día no es < 1 
    break;

  default: // Febrero
    if (dia <= 28) return true;
    break;
  }
  return false;
}

bool Software::reservaSala_(int numero_ocupantes, const std::string& mes, int identificador_sala, int dia_sala, int hora_sala) {
  if (reservaValida_(mes, dia, hora)) {
    std::cerr << "Error, la fecha introducida no es válida para realizar una reserva " << std::endl;
    return false;
  }
  for (auto sala : salas_) {
    if (identificador_sala == sala.getIdentificador() && sala.estaDisponible()) {
      return sala.cambiarDisponibilidad(numero_ocupantes);
    }
  }
  return false;
}

bool Software::devolucion_(const std::string& nombre_usuario, const std::string& titulo_libro) {
  for (const auto& libro : catalogo_.getLibros()) {
    if (libro.getTitulo() == titulo_libro) {
      for (auto usuario : usuarios_) {
        if (usuario.getNombreUsuario() == nombre_usuario) {
          usuario.eliminarLibro(libro);
          return true;
        }
      }
    }
  }
  return false;
}

