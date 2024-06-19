#include "Transaccion.h"

Transaccion::Transaccion(std::string _tipo, double _monto, std::string _fecha, std::string _dni_cliente)
    : tipo(_tipo), monto(_monto), fecha(_fecha), dni_cliente(_dni_cliente) {}

std::string Transaccion::getTipo() const {
    return tipo;
}

double Transaccion::getMonto() const {
    return monto;
}

std::string Transaccion::getFecha() const {
    return fecha;
}

std::string Transaccion::getDniCliente() const {
    return dni_cliente;
}