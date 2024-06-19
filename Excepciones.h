
#pragma once

#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <exception>


class MaximoIntentosAlcanzado : public std::exception {
public:
    const char* what() const noexcept override;
};

void mostrarMenuBanco();


#endif //EXCEPCIONES_H
