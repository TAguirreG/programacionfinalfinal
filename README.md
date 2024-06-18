[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/MyAlb3Pe)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=15200848)
# Trabajo Final Programacion II

Miembros

- 2315421, Aguirre Tomás

Tema: Sistema de Gestión Bancaria

Como se compila

```
g++ -o trabajo_final -std=c++20 main.cpp
```

**Instrucciones de uso**

Se utilizarán dos archivos de texto para almacenar los datos del sistema:

- clientes.txt: Este archivo almacenará la información de los clientes.
- transacciones.txt: Este archivo almacenará las transacciones realizadas por los clientes.

Datos de cada archivo

- clientes.txt

  Atributo: DNI, Nombre, TipoCliente, etc...

  Descripción: Número de identificación único para cada cliente, Nombre completo del cliente, Categoría del cliente (Plata, Oro, Platino), etc...

  Ejemplo: 12345678, Juan Pérez, Oro, etc...

- transacciones.txt

  Atributo: Tipo, Monto, Fecha, etc...

  Descripción: Tipo de transacción, Monto de la transacción, Fecha en la que se realizó la transacción, etc...

  Ejemplo: Deposito, 5000, 24-07-2024, etc...

Asociación entre archivos

- La asociación entre los archivos clientes.txt y transacciones.txt se realiza mediante el atributo DNI del cliente en el archivo transacciones.txt. Esto nos permite asociar el DNI de un cliente a la transacción registrada. Al realizar una consulta o generar un informe, se busca al cliente en el archivo clientes.txt a partir de su DNI y se recuperarán las transacciones asociadas a ese DNI del archivo transacciones.txt.

Formato para guardar los datos

- Se utilizará un formato separado por comas para guardar los datos en ambos archivos. Cada línea del archivo representa un registro de datos. Los atributos se separarán por comas.

- Ejemplo de registro en clientes.txt: 12345678, Juan Pérez, Oro, 2020, ACTIVO, 1000.00, 200.00
- Ejemplo de registro en transacciones.txt: 12345678, Deposito, Pesos, 500.00, 2024-06-03

De haber mas tiempo, que hubiesen mejorado

- ...
- ...
- ...

# Criterio de aceptacion

- La implementacion es de produccion propia y han contribuido todos miembros del
  equipo
- El codigo compila sin errores (sino compila la calificacion es 0)
- El codigo sigue los lineamientos aprendidos en clase
- El codigo tiene comentarios y documentacion adecuada

# Checklist para cada ejercicio

- calidad de la logica
- programacion modular con funciones (sin mezclar logica con IO `cin`/`cout`)
- seleccion de tipos adecuandos para
  - funciones: parametros y valores de retorno
  - clases: datos miembro y metodos (idem funciones)
- validaciones con `assert` (`#include <cassert>`) en funciones y metodos de
  clase
- nombres descriptivos para variables, funciones, clases, datos miembro,
  metodos, etc.
- uso de `cin`/`cout` (`#include <iostream>`) solo para mostrar y pedir datos
- separar en `.h` archivo cabecera (o header) y `.cpp` archivo de implementacion
- conocer como compilar por linea de comando los archivos del ejercicio
- reconocer y probar los limites de la funcion/clase
- (opcional) implementar casos de prueba con `assert`
