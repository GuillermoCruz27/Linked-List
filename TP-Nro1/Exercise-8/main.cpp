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
    setlocale(LC_ALL, "es_ES.UTF-8");
    TLista lista{};
    CrearLista(lista);
    int opcion;
    do
    {
        Menu();
        cout << "Ingrese una opción: ";
        cin >> opcion;
        fflush(stdin);
        system("cls");
        switch (opcion) {
        case 1:
            int valor;
            cout << "Ingrese un valor: ";
            cin >> valor;
            AgregarElemento(lista, valor);
            break;
        case 2:
            MostrarMayor(lista);
            break;
        case 3:
            EliminarInicio(lista);
            break;
        case 4:
            ContarPositivos(lista);
            break;
        case 5:
            cout << "Saliendo..." << endl;
            LiberarMemoria(lista);
            break;
        default:
            cout << "Opción invalida" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
    while (opcion != 5);
    return 0;
}