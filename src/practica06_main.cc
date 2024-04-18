#include <iostream>
#include 'Usuario.h'

int main(int argc, char* argv[] ) {
    std::cout << "\n\nBienvenido a al red de bibliotecas\n\n";
    std::cout << "¿Qué acción deseas realizar?\n";
    std::cout << "1) Iniciar sesión\n";
    std::cout << "2) Crear cuenta\n";
    std::cout << "3) Salir\n";
    int opcion_inicio{0};
    std::cin >> opcion_inicio;
    switch (opcion_inicio) {
        case 1:
            std::cout << "Ingresar nombre de usuario :";
            std::cin >> Usuario.get_nombre_usuario_();
            std::cout << "\nIngresar contraseña:";
            std::cin >> Usuario.get_contrasena_();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            std::cout << "Error: opción Incorrecta\n"
            continue;

    }
    return 0;
}