#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Banco.h"
#include "Cliente.h"
#include "Transaccion.h"
#include "Excepciones.h"

void mostrarMenuBanco(Banco &banco) {
    int opcion;
    do {
        std::cout << "\n=== MENU DEL BANCO ===\n";
        std::cout << "1. Registrar cliente\n";
        std::cout << "2. Dar de baja cliente\n";
        std::cout << "3. Listar clientes\n";
        std::cout << "4. Registrar transaccion\n";
        std::cout << "5. Listar transacciones por cliente\n";
        std::cout << "6. Generar informe de transacciones por mes\n";
        std::cout << "7. Generar informe de transacciones por anio\n";
        std::cout << "8. Generar informe de todas las operaciones\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string dni, nombre, tipo_cliente;
                int ano_ingreso;
                bool activo = true;
                std::cout << "Ingrese DNI: ";
                std::cin >> dni;
                std::cout << "Ingrese nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Ingrese tipo de cliente (Plata, Oro, Platino): ";
                std::cin >> tipo_cliente;
                std::cout << "Ingrese anio de ingreso: ";
                std::cin >> ano_ingreso;

                Cliente *nuevo_cliente = new Cliente(dni, nombre, tipo_cliente, ano_ingreso, activo);
                banco.registrarCliente(nuevo_cliente);
                std::cout << "\nCliente registrado correctamente\n";
                break;
            }
            case 2: {
                std::string dni;
                std::cout << "Ingrese DNI del cliente a dar de baja: ";
                std::cin >> dni;
                banco.darDeBajaCliente(dni);
                std::cout << "Cliente dado de baja correctamente\n";
                break;
            }
            case 3:
                banco.listarClientes();
                break;
            case 4: {
                std::string tipo, dni_cliente;
                double monto;
                std::string fecha;
                std::cout << "Ingrese tipo de transaccion (Deposito o Extraccion): ";
                std::cin >> tipo;
                std::cout << "Ingrese Monto: ";
                std::cin >> monto;
                std::cout << "Ingrese Fecha (YYYY-MM-DD): ";
                std::cin >> fecha;
                std::cout << "Ingrese DNI del Cliente: ";
                std::cin >> dni_cliente;

                Transaccion *nueva_transaccion = new Transaccion(tipo, monto, fecha, dni_cliente);
                banco.registrarTransaccion(nueva_transaccion);
                std::cout << "Transaccion realizada correctamente\n";
                break;
            }
            case 5: {
                std::string dni_cliente;
                std::cout << "Ingrese DNI del cliente: ";
                std::cin >> dni_cliente;
                banco.listarTransaccionesPorCliente(dni_cliente);
                break;
            }
            case 6: {
                int mes;
                std::cout << "Ingrese Mes (1-12): ";
                std::cin >> mes;
                banco.generarInformeTransaccionesMes(mes);
                break;
            }
            case 7: {
                int anio;
                std::cout << "Ingrese Anio: ";
                std::cin >> anio;
                banco.generarInformeTransaccionesAnio(anio);
                break;
            }
            case 8:
                banco.generarInformeTodasLasOperaciones();
                break;
            case 0:
                std::cout << "Saliendo del menu banco\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 0);
}

void mostrarMenuCliente(Cliente &cliente, Banco &banco) {
    int opcion;
    std::string dni_cliente = cliente.getDni(); // Obtenemos el DNI del cliente

    do {
        std::cout << "\n=== MENU DEL CLIENTE ===\n";
        std::cout << "Cliente: " << cliente.getNombre() << " (" << dni_cliente << ")\n";
        std::cout << "1. Realizar deposito\n";
        std::cout << "2. Realizar extracción\n";
        std::cout << "3. Consultar mis transacciones\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                double monto;
                std::cout << "Ingrese monto a depositar: ";
                std::cin >> monto;

                Transaccion *nueva_transaccion = new Transaccion("Deposito", monto, "2024-06-16", dni_cliente);
                banco.registrarTransaccion(nueva_transaccion);
                std::cout << "Deposito realizado correctamente.\n";
                break;
            }
            case 2: {
                double monto;
                std::cout << "Ingrese monto a extraer: ";
                std::cin >> monto;

                Transaccion *nueva_transaccion = new Transaccion("Extraccion", monto, "2024-06-16", dni_cliente);
                banco.registrarTransaccion(nueva_transaccion);
                std::cout << "Extraccion realizada correctamente.\n";
                break;
            }
            case 3:
                banco.listarTransaccionesPorCliente(dni_cliente);
                break;
            case 0:
                std::cout << "Saliendo del mene cliente.\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 0);
}

int main() {
    Banco banco;
    int opcion, i = 1;
    std::string claveBanco; //Clave del banco: drakeucc24
    do {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Acceder como banco\n";
        std::cout << "2. Acceder como cliente\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                try {
                    for (i = 0; i < 3; ++i) {
                        std::cout << "Ingrese la clave de seguridad para acceder al menu del banco\n";
                        std::cin >> claveBanco;
                        if (claveBanco == "drakeucc24") {
                            mostrarMenuBanco(banco);
                            break;
                        } else {
                            std::cout << "Clave incorrecta, por favor, reintentar\n";
                            std::cout << "Intentos restantes: " << 2 - i << "\n";
                        }
                    }
                    if (i == 3) {
                        throw MaximoIntentosAlcanzado();
                    }
                } catch (const MaximoIntentosAlcanzado &e) {
                    std::cout << e.what() << std::endl;
                }

                return 0;

                break;
            case 2: {
                std::string dni;
                std::cout << "Ingrese su DNI: ";
                std::cin >> dni;

                Cliente *cliente = banco.buscarCliente(dni);
                if (cliente) {
                    mostrarMenuCliente(*cliente, banco);
                } else {
                    std::cout << "Cliente no encontrado.\n";
                }
                break;
            }
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}
