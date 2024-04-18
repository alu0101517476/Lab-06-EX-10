#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    std::string press_enter;
    char press_enter_opcion1;
    std::string nombre_usuario, contraseña;
    system("clear");
    std::cout << "\n\n\n\n\nBIENVENIDO A LA RED DE BIBLITECA\n\n\n\n";
    while (true) {
        std::cout << "         Pulsa Enter";
        if (std::getline(std::cin, press_enter) && press_enter.empty()) {
            system("clear");
            while(true) {
                std::cout << "\n¿Qué acción deseas realizar?\n\n";
                std::cout << " 1) Iniciar sesión\n";
                std::cout << " 2) Crear cuenta\n";
                std::cout << " 3) Salir\n\n";
                std::cout << "Opción: ";
    //            Usuario usuario;
                int opcion_inicio,opcion_segunda;
                std::cin >> opcion_inicio;
                switch (opcion_inicio) {
                    case 1:
                        system ("clear");
                        std::cout << "Iniciando sesión...";
                        // funcion iniciar_sesion()
                        while (true) {
                            std::cout << "\n\nPulsa C (continuar): ";
                            std::cin >> press_enter_opcion1;
                            if (press_enter_opcion1 == 67 || press_enter_opcion1 == 99) {
                                system ("clear");
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
                                        system ("clear");
                                        // funcion prestamoLibros()
                                        continue;
                                    case 2:
                                        system ("clear");
                                        //funcion devolucion()
                                        continue;
                                    case 3:
                                        system ("clear");
                                        //funcion buscarLibro()
                                        continue;
                                    case 4:
                                        system ("clear");
                                        // funcion reservaSala()
                                        continue;
                                    case 5:
                                        system ("clear");
                                        std::cout << "Cerrando sesión...\n";
                                        while (true) {
                                            std::cout << "\n\nPulsa C (continuar): ";
                                            std::cin >> press_enter_opcion1;
                                            if (press_enter_opcion1 == 67 || press_enter_opcion1 == 99) {
                                                break;
                                            } else {
                                                system ("clear");
                                                std::cout << "Tecla incorrecta";
                                                continue;
                                            }
                                        }
                                        system ("clear");
                                        break;
                                    default:
                                        system ("clear");
                                        std::cout << "Error: Opción incorrecta\n\n";
                                        break;
                                }
                                break;
                            } else {
                                system ("clear");
                                std::cout << "Tecla incorrecta";
                                continue;
                            }
                        }
                        break;
                    case 2:
                        system ("clear");
                        std::cout << "Creando cuenta...";
                        // funcion crear_usuario()
                        while (true) {
                            std::cout << "\n\nPulsa C (continuar): ";
                            std::cin >> press_enter_opcion1;
                            if (press_enter_opcion1 == 67 || press_enter_opcion1 == 99) {
                                break;
                            } else {
                                system ("clear");
                                std::cout << "Tecla incorrecta";
                                continue;
                            }
                        }
                        system ("clear");
                        break;
                    case 3:
                        system ("clear");
                        std::cout << "Termina el programa\n\n";
                        return 0;
                    default:
                        system ("clear");
                        std::cout << "Error: Opción incorrecta\n\n";
                        break;
                }
            }
        } else {
            system ("clear");
            std::cout << "Tecla incorrecta\n\n";
            continue;
        }
    }
    return 0;
}