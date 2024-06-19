#include "Excepciones.h"
#include <iostream>

const char* MaximoIntentosAlcanzado::what() const noexcept {
    std::cout <<"Intentos maximos alcanzados.\n";
    std::cout << "Bloqueando acceso...\n";
}

void mostrarMenuBanco() {
    std::cout << "Mostrando el menu del banco..." << std::endl;
}
