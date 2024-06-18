#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <fstream>

class Cliente {
private:
  std::string dni;
  std::string nombre;
  std::string tipoCliente;
  int anoIngreso;
  bool activo;  // Campo para indicar si el cliente está activo o no

public:
  Cliente(const std::string& dni, const std::string& nombre, const std::string& tipoCliente, int anoIngreso, bool activo);

  // Métodos getter
  std::string getDni() const;
  std::string getNombre() const;
  std::string getTipoCliente() const;
  int getAnoIngreso() const;
  bool isActivo() const;

  void setActivo(bool activo);

  void guardar(std::ofstream& archivo) const;
  void cargar(std::ifstream& archivo);
};

#endif // CLIENTE_H