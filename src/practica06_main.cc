#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    std::string press_enter, press_enter_error;
    std::string nombre_usuario, contraseña;
    std::cout << "\n\n\n\n\nBIENVENIDO A LA RED DE BIBLITECA\n\n\n\n";
    std::cout << "         Pulsa Enter";
    if (std::getline(std::cin, press_enter) && press_enter.empty()) {
        system("clear");
        while(true) {
            std::cout << "\n¿Qué acción deseas realizar?\n\n";
            std::cout << " 1) Iniciar sesión\n";
            std::cout << " 2) Crear cuenta\n";
            std::cout << " 3) Salir\n";
//            Usuario usuario;
            int opcion_inicio;
            std::cin >> opcion_inicio;
            switch (opcion_inicio) {
                case 1:
                    system ("clear");
                    // funcion iniciar_sesion()
                    
                    break;
                case 2:
                    system ("clear");
                    // funcion crear_usuario()
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
    }
    return 0;
}