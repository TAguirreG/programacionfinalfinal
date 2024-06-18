#include "Banco.h"
#include <iostream>

Banco::Banco() {
    cargarClientes();  // Cargar clientes al iniciar el banco
}

Banco::~Banco() {
    // Liberar memoria de clientes y transacciones
    for (auto cliente : clientes) {
        delete cliente;
    }
    clientes.clear();

    for (auto transaccion : transacciones) {
        delete transaccion;
    }
    transacciones.clear();
}

void Banco::registrarCliente(Cliente* cliente) {
    clientes.push_back(cliente);
    guardarClientes();  // Guardar clientes después de registrar uno nuevo
}

void Banco::darDeBajaCliente(const std::string& dni) {
    for (auto cliente : clientes) {
        if (cliente->getDni() == dni) {
            cliente->setActivo(false);  // Desactivar cliente
            guardarClientes();  // Guardar clientes después de dar de baja
            std::cout << "Cliente dado de baja correctamente.\n";
            return;
        }
    }
    std::cout << "Cliente no encontrado.\n";
}

void Banco::listarClientes() const {
    std::cout << "\n=== LISTADO DE CLIENTES ===\n";
    for (const auto& cliente : clientes) {
        std::cout << "DNI: " << cliente->getDni() << ", Nombre: " << cliente->getNombre() << ", Tipo: " << cliente->getTipoCliente() << "\n";
    }
}

void Banco::registrarTransaccion(Transaccion* transaccion) {
    transacciones.push_back(transaccion);
}

void Banco::listarTransaccionesPorCliente(const std::string& dni_cliente) const {
    std::cout << "\n=== LISTADO DE TRANSACCIONES PARA EL CLIENTE " << dni_cliente << " ===\n";
    for (const auto& transaccion : transacciones) {
        if (transaccion->getDniCliente() == dni_cliente) {
            std::cout << "Tipo: " << transaccion->getTipo() << ", Monto: " << transaccion->getMonto() << ", Fecha: " << transaccion->getFecha() << "\n";
        }
    }
}

void Banco::generarInformeTransaccionesMes(int mes) const {
    std::cout << "\n=== INFORME DE TRANSACCIONES PARA EL MES " << mes << " ===\n";
    for (const auto& transaccion : transacciones) {
        if (std::stoi(transaccion->getFecha().substr(5, 2)) == mes) {
            std::cout << "Cliente: " << transaccion->getDniCliente() << ", Tipo: " << transaccion->getTipo() << ", Monto: " << transaccion->getMonto() << "\n";
        }
    }
}

void Banco::generarInformeTransaccionesAnio(int anio) const {
    std::cout << "\n=== INFORME DE TRANSACCIONES PARA EL ANIO " << anio << " ===\n";
    for (const auto& transaccion : transacciones) {
        if (std::stoi(transaccion->getFecha().substr(0, 4)) == anio) {
            std::cout << "Cliente: " << transaccion->getDniCliente() << ", Tipo: " << transaccion->getTipo() << ", Monto: " << transaccion->getMonto() << "\n";
        }
    }
}

void Banco::generarInformeTodasLasOperaciones() const {
    std::cout << "\n=== INFORME DE TODAS LAS OPERACIONES ===\n";
    for (const auto& transaccion : transacciones) {
        std::cout << "Cliente: " << transaccion->getDniCliente() << ", Tipo: " << transaccion->getTipo() << ", Monto: " << transaccion->getMonto() << ", Fecha: " << transaccion->getFecha() << "\n";
    }
}

Cliente* Banco::buscarCliente(const std::string& dni) const {
    for (auto cliente : clientes) {
        if (cliente->getDni() == dni && cliente->isActivo()) {
            return cliente;
        }
    }
    return nullptr;
}

void Banco::guardarClientes() const {
    std::ofstream archivo("clientes.txt");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo clientes.txt\n";
        return;
    }

    for (const auto& cliente : clientes) {
        cliente->guardar(archivo);
    }

    archivo.close();
}

void Banco::cargarClientes() {
  std::ifstream archivo("clientes.txt");
  if (!archivo) {
    std::cerr << "No se encontró el archivo clientes.txt\n";
    return;
  }

  while (!archivo.eof()) {
    Cliente* cliente = new Cliente("", "", "", 0, false);  // Crear cliente temporal
    cliente->cargar(archivo);  // Cargar datos desde el archivo
    if (cliente->getDni() != "") {  // Evitar cargar datos vacíos al final del archivo
      clientes.push_back(cliente);
    } else {
      delete cliente;  // Eliminar cliente temporal si está vacío
    }
  }

  archivo.close();
}
