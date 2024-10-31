#include <iostream>
#include "LSimple.hpp"

using namespace std;

/*
* Implementar Lista Simple con datos enteros ordenada de forma ascendente con las funciones básicas
* y agregar las siguientes operaciones:
*
* a. Agregar elementos en orden
* b. Determinar el mayor de los datos ingresados
* c. Eliminar el menor valor de la lista
* d. Contar la cantidad de datos positivos ingresados en la lista
*
* */

int main() {
    TLista lista{};
    CrearLista(lista);
    InsertarInicio(lista, 8);
    InsertarInicio(lista, 9);
    InsertarFinal(lista, 7);
    EliminarFinal(lista);
    EliminarFinal(lista);
    EliminarFinal(lista);
    return 0;
}