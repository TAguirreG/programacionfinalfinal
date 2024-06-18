#include "Cliente.h"
#include <algorithm>  // Incluir la biblioteca <algorithm> para usar all_of
#include <cctype>     // Incluir la biblioteca <cctype> para usar std::isdigit
#include <iostream>

Cliente::Cliente(const std::string& dni, const std::string& nombre, const std::string& tipoCliente, int anoIngreso, bool activo)
    : dni(dni), nombre(nombre), tipoCliente(tipoCliente), anoIngreso(anoIngreso), activo(activo) {}

std::string Cliente::getDni() const {
  return dni;
}

std::string Cliente::getNombre() const {
  return nombre;
}

std::string Cliente::getTipoCliente() const {
  return tipoCliente;
}

int Cliente::getAnoIngreso() const {
  return anoIngreso;
}

bool Cliente::isActivo() const {
  return activo;
}

void Cliente::setActivo(bool activo) {
  this->activo = activo;
}

void Cliente::guardar(std::ofstream& archivo) const {
  archivo << dni << "," << nombre << "," << tipoCliente << "," << anoIngreso << "," << activo << "\n";
}

void Cliente::cargar(std::ifstream& archivo) {
  std::getline(archivo, dni, ',');
  std::getline(archivo, nombre, ',');
  std::getline(archivo, tipoCliente, ',');
  std::string anoIngresoStr;
  std::getline(archivo, anoIngresoStr, ',');
  if (!anoIngresoStr.empty() && std::all_of(anoIngresoStr.begin(), anoIngresoStr.end(), ::isdigit)) {
    anoIngreso = std::stoi(anoIngresoStr);
  } else {
    // Manejar error o establecer un valor predeterminado si la conversión falla
    anoIngreso = 0; // Otra opción: lanzar una excepción o manejar el error según corresponda
  }
  std::string activoStr;
  std::getline(archivo, activoStr);
  activo = (activoStr == "1");  // Convierte de string "1" o "0" a bool
}