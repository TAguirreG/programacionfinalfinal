#ifndef BANCO_H
#define BANCO_H

#include <vector>
#include <fstream>
#include "Cliente.h"
#include "Transaccion.h"

class Banco {
private:
  std::vector<Cliente*> clientes;
  std::vector<Transaccion*> transacciones;

public:
  Banco();
  ~Banco();

  void registrarCliente(Cliente* cliente);
  void darDeBajaCliente(const std::string& dni);
  void listarClientes() const;
  void registrarTransaccion(Transaccion* transaccion);
  void listarTransaccionesPorCliente(const std::string& dni_cliente) const;
  void generarInformeTransaccionesMes(int mes) const;
  void generarInformeTransaccionesAnio(int anio) const;
  void generarInformeTodasLasOperaciones() const;

  Cliente* buscarCliente(const std::string& dni) const;

  // Métodos para guardar y cargar desde archivo
  void guardarClientes() const;
  void cargarClientes();
};

#endif // BANCO_H
