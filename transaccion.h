#pragma once

#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>

class Transaccion {
private:
    std::string tipo;
    double monto;
    std::string fecha;
    std::string dni_cliente;

public:
    Transaccion(std::string _tipo, double _monto, std::string _fecha, std::string _dni_cliente);

    // Métodos getters
    std::string getTipo() const;
    double getMonto() const;
    std::string getFecha() const;
    std::string getDniCliente() const;
};

#endif // TRANSACCION_H