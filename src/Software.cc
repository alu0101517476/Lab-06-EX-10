#include "../Include/Sofware.h"
std::string Cifra(std::string palabra) {
  for (int i{0}; i < palabra.size(); ++i) {
    palabra[i] = palabra[i] + 3;
  }
  return palabra;
}

std::string DCifra(std::string palabra) {
  for(int i = 0; i < palabra.size(); i++) {
    palabra[i] = palabra[i] - 3;
  }
  return palabra; 
}
Software::Software(Catalogo catalogo, std::set<Usuario> usuarios, std::set<Sala> salas)
      : catalogo_{catalogo}, usuarios_{usuarios}, salas_{salas} { };

Software::Software(const std::string& nombre_fichero_usuarios, const std::string& nombre_fichero_catalogo) 
                : catalogo_(nombre_fichero_catalogo), nombre_fichero_base_datos_usuario_(nombre_fichero_usuarios) {
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

void Software::menu() {
  std::string press_enter;
  char press_enter_opcion1;
  std::string nombre_usuario, password, correo, titulo_libro;
  int id_libro;
  Usuario usuario;
  system("clear");
  std::cout << MAGENTA << "\n\n\n\n\n                                    BIENVENIDO A LA RED DE BIBLIOTECAS\n\n\n\n" << WHITE;
  std::cout << YELLOW << "-->" << WHITE <<" Inicia sesión en nuestra biblioteca para acceder a diferentes servicios o crea una cuenta propia." << std::endl;
  std::cout << YELLOW << "-->" << WHITE <<" Podrás acceder a nuestro cátalogo que ofrece una amplia variedad de árticulos, libros y revistas." << std::endl;
  std::cout << YELLOW << "-->" << WHITE <<" Reserva ya tu sala indicando número de personas, sala a reservar, día y hora.\n" << std::endl;
  std::cout << WHITE << "Cualquier duda se podrá comunicar con estos teléfonos de contacto:\n" << BLUE << " +34 677 77 77 77\n" << BLUE << " +34 622 22 22 22\n\n" << std::endl;
  std::cout << WHITE << "O bien enviar un correo a estos e-mails:\n" << BLUE << " alu0101547619@ull.edu.es\n" << BLUE << " alu0101567211@ull.edu.es\n\n" << std::endl; 
  while (true) {
    std::cout << GRAY <<  "         Pulsa Enter para acceder al sistema:" << RESET;
    if (std::getline(std::cin, press_enter) && press_enter.empty()) {
      system("clear");
      while (true) {
        std::cout << "\nPara poder acceder a los servicios de la biblioteca será necesario realizar el inicio de sesión con las credenciales correctas:\n\n";
        std::cout << YELLOW << " --> " << WHITE << "Ingrese " << BG_GREEN << "1" << RESET << " para dirigirte a la pantalla de" << RED << " iniciar sesión\n\n" << RESET;
        std::cout << "Si bien no tienes una cuenta de la bilioteca, deberás crearte una nueva cuenta:\n\n";
        std::cout << YELLOW <<" --> " << WHITE << "Ingrese " << BG_GREEN << "2" << RESET <<  " para dirigirte a la pantalla de "<< RED << "creación de cuenta\n\n" << RESET;
        std::cout << "Una vez realizada la acción deseada podrás salir de la biblioteca:\n\n";
        std::cout << YELLOW <<" --> " << WHITE << "Ingrese "<< BG_GREEN << "3" << RESET << " para " << RED << "salir de la pantalla de inicio de la biblioteca\n\n" << RESET;
        std::cout << BLUE << "Opción elegida: " << RESET ;
        int opcion_inicio, opcion_segunda;
        std::cin >> opcion_inicio;
        std::cout << RESET;
        switch (opcion_inicio) {
          case 1:
            system("clear");
            std::cout << CYAN <<"Iniciando sesión...\n" << RESET <<std::endl;
            std::cout << "Para poder llevar a cabo el inicio de sesión, es necesario ingresar las credenciales correctas\n" << ORANGE <<"(*)Campo obligatorio" << WHITE <<"\n\n" << YELLOW <<  " --> "<<WHITE << "Introduzca el nombre de usuario " << ORANGE <<"*" << WHITE": ";
            std::cin >> nombre_usuario;
            std::cout << YELLOW <<  "\n --> "<<WHITE <<"Introduzca la contraseña del usuario " << ORANGE <<"*" << WHITE <<": ";
            std::cin >> password;
            std::cout << std::endl;
            usuario.setCorreo(correo);
            usuario.setContrasena(password);
            usuario.setNombreUsuario(nombre_usuario);
            if (!iniciarSesion_(nombre_fichero_base_datos_usuario_, nombre_usuario, password)) { break; }
            while (true) {
              std::cout << GRAY <<"\n\nPulsa C (continuar): " << RESET;
              std::cin >> press_enter_opcion1;
              if (press_enter_opcion1 == 67 || press_enter_opcion1 == 99) {
                system("clear");
                std::cout << "Ofrecemos un servicio de préstamo de libros para realizar una reserva online y poder recoger el material precencialmente\n\n";
                std::cout << YELLOW << " --> " << RESET<< "Ingrese " << BG_GREEN << "1" << RESET << " para dirigirse a la pantalla de "<< RED << "préstamo de material\n\n"  << RESET;
                std::cout << "Una vez realizado el préstamo, se podrá realizar la devolución del manterial indicando el identificador del mismo\n\n";
                std::cout << YELLOW << " --> "  << RESET <<"Ingrese " << BG_GREEN << "2" << RESET << " para dirigirse a la pantalla de " << RED << "devolución de material\n\n"<< RESET;
                std::cout << "También dispondremos de una gran variedad de material que se podrá consultar para inspeccionar si hay en la biblioteca\n\n";
                std::cout << YELLOW << " -->" << RESET << " Ingrese " << BG_GREEN << "3" << RESET << " para dirigirse a la pantalla de " << RED <<"consultar catalogo\n\n" << RESET;
                std::cout << "Contamos con salas de estudio, grabaciones y ordenadores entre otros, donde habrá que reservalas con anterioridad en la web\n\n";
                std::cout << YELLOW << " -->" << RESET << " Ingrese " << BG_GREEN << "4" << RESET << " para dirigirse a la pantalla de " << RED << "reserva de sala\n\n" << RESET;
                std::cout << "Para salir del sistema de la biblioetca es necesario cerrar sesión\n\n";
                std::cout << YELLOW << " -->" << RESET << " Ingrese " << BG_GREEN << "5" << RESET <<" para " << RED <<"cerrar sesión\n\n" << RESET;
                std::cout << BLUE << "Opción elegida: " << RESET ;
                std::cin >> opcion_segunda;
                switch (opcion_segunda) {
                  case 1:
                    system("clear");
                    std::cout << BLUE <<"Cátalago disponible de la biblioteca\n\n" << RESET;
                    catalogo_.Mostrar();
                    std::cout << BLUE << "\nIndique el identificador del libro que desea reservar (Ej: 2 (La Celestina)): ";
                    std::cin >> id_libro;
                    if (prestamoLibros_(nombre_usuario, catalogo_.getLibro(id_libro))) {
                      std::cout << GREEN <<"\n✓" << RESET << " El libro está disponible para recogida presencial." << std::endl;
                    } 
                    else {
                      std::cout << RED <<"\nX" << RESET << "No se puede llevar a cabo el préstamo, pruebe en otro momento. Disculpe por las molestias." << std::endl;
                    }
                    // Esto evita el bucle infinito
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                  case 2:
                    system("clear");
                    std::cout << BLUE <<"\nCátalago disponible de la biblioteca\n\n" << RESET;
                    catalogo_.Mostrar();
                    std::cout << BLUE <<"\n¿Cuál es el título del libro que vas a devolver? Indique el identificador " << RESET;
                    std::cin >> id_libro;
                    if (devolucion_(nombre_usuario, catalogo_.getLibro(id_libro))) {
                      std::cout <<  GREEN <<"\n✓ " << RESET << "El libro se ha devuelto satisfactoriamente." << std::endl;
                    }
                    else {
                      std::cout << RED <<"\nX " << RESET << "Ha habido algún problema en la devolución. Inténtelo de nuevo más tarde." << std::endl;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                  case 3:
                    system("clear");
                    std::cout << BLUE <<"¿Cuál es el título del libro que quieres consultar? " << RESET;
                    std::cin >> titulo_libro;
                    if (buscarLibro_(titulo_libro)) {
                      std::cout << GREEN <<"\n✓ " << RESET << "El libro está disponible en el catálogo" << std::endl;
                    } else {
                      std::cout << RED <<"\nX " << RESET << "El libro no está disponible en el catálogo" << std::endl;
                    }
                    continue;
                  case 4: {
                    int numero_ocupantes, identificador_sala, dia_sala, hora_sala;
                    std::string mes;
                    system("clear");
                    std::cout << YELLOW << " --> " << RESET << "¿Cuántos van a reservar la sala? ";
                    std::cin >> numero_ocupantes;
                    std::cout << YELLOW << " --> " << RESET << "¿Qué sala quieres reservar? ";
                    std::cin >> identificador_sala;
                    std::cout << YELLOW << " --> " << RESET << "¿Mes de la reserva? ";
                    std::cin >> mes;
                    std::cout << YELLOW << " --> " << RESET << "¿Día de la reserva? ";
                    std::cin >> dia_sala; 
                    std::cout << YELLOW << " --> " << RESET << "¿Hora de la reserva? ";
                    std::cin >> hora_sala;
                    // if (hora_sala < 9 || hora_sala > 21) {
                      // std::cout << "Hora no accesible\n\nHorario de la biblioteca: 9:00-21:00" << std::endl;
                      // continue;
                    //}
                    if (reservaSala_(numero_ocupantes, mes, identificador_sala, hora_sala, dia_sala)) {
                      std::cout << GREEN << "\nReserva realizada con éxito" << std::endl;
                    }
                    else {
                      std::cout << RED <<"\nHa habido un problema con la reserva. Inténtelo de nuevo más tarde." << std::endl;
                    }
                    continue;
                  }
                  case 5:
                    system("clear");
                    std::cout << MAGENTA << "Cerrando sesión...\n" << RESET;
                    while (true) {
                      std::cout << GRAY << "\n\nPulsa C (continuar): " << RESET;
                      std::cin >> press_enter_opcion1;
                      if (press_enter_opcion1 == 67 ||
                          press_enter_opcion1 == 99) {
                        break;
                      } else {
                        system("clear");
                        std::cout << RED << "\nTecla incorrecta" << RESET;
                        continue;
                      }
                    }
                    system("clear");
                    break;
                  default:
                    system("clear");
                    std::cout << RED << "Exit Error\nLa opción introducida no existe\n\n" << RESET;
                    continue;
                }
                break;
              } else {
                system("clear");
                std::cout << RED << "Tecla incorrecta" << RESET;
                continue;
              }
            }
            break;
          case 2:
            system("clear");
            std::cout << "Para llevar a cabo la creación de una cuenta de usuario será necesario introducir las credenciales deseadas por el usuario" << ORANGE << "\n(*)Campo obligatorio" << WHITE << "\n\n" << YELLOW <<" --> " << RESET <<"Introduzca el nombre de usuario " << ORANGE << "*" << RESET <<": ";
            std::cin >> nombre_usuario;
            std::cout << YELLOW <<  "\n --> " << RESET <<"Introduzca la contraseña del usuario" << ORANGE << " *" << RESET <<  ": ";
            std::cin >> password;
            std::cout << YELLOW << "\n -->" << RESET << " Introduzca el correo del usuario" << ORANGE << " *" << RESET <<  ": ";
            std::cin >> correo;
            std::cout << "\nVerificando credenciales ingresadas";
            sleep(1);
            std::cout << CYAN << "\nCreando cuenta...\n" << RESET;
            sleep(1);
            crearUsuario_(nombre_fichero_base_datos_usuario_, nombre_usuario, password, correo);
            while (true) {
              std::cout << GRAY << "\n\nPulsa C (continuar): " << RESET;
              std::cin >> press_enter_opcion1;
              if (press_enter_opcion1 == 67 || press_enter_opcion1 == 99) {
                break;
              } else {
                system("clear");
                std::cout << RED << "Tecla incorrecta";
                continue;
              }
            }
            system("clear");
            break;
          case 3:
            system("clear");
            std::cout << MAGENTA << "\n\n               [        GRACIAS POR SU VISITA        ]        \n\n\n\n";
            exit(1);
          default:
            system("clear");
            std::cout << RED << "Exit Error\nLa opción introducida no existe\n\n" << RESET;
            break;
        }
      }
    } else {
      system("clear");
      std::cout << RED << "Tecla incorrecta\n\n" << RESET;
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
        std::cout << GREEN <<"Inicio de sesión satisfactorio" << WHITE << std::endl;
        fichero_usuario.close();
        return true;
      }
      else {
        std::cout << RED << "No se ha podido iniciar sesión. Contraseña incorrecta" << WHITE << std::endl;
        fichero_usuario.close();
        return false;
      }
    }
    std::getline(fichero_usuario, linea);
  }
  std::cout << RED <<"No se ha encontrado el usuario. No se ha iniciado sesión" << WHITE <<  std::endl;
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
      std::cout << RED << "\nEl correo que ha intrucido se encuentra en uso, prueba a introducir otro correo" << RESET <<std::endl;
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
  std::cout << GREEN << "\nCuenta creada satisfactoriamente."  << RESET << std::endl;
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
  {"Marzo", 1}, {"Abril", 2}, {"Mayo", 1}, {"Junio", 2}, {"Julio", 1}, {"Agosto", 1}, 
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
  if (reservaValida_(mes, dia_sala, hora_sala)) {
    std::cerr << RED <<"\nError, la fecha introducida no es válida para realizar una reserva " << RESET <<std::endl;
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

