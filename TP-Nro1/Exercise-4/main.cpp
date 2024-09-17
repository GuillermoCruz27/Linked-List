/*
 * Autor: Guillermo Joaquin Cruz
 * Año: 2024
 * Asignatura: Estructura de datos
 * Tema: Listas Enlazadas
 */

// Importar librerias
#include <iostream>
#include <cmath>
#include "ListaEnlazadaSimple.hpp"

#define endl '\n'

/*
 * Dada una Lista Simple de valores enteros con una capacidad de 25 elementos,
 * realice los cambios necesarios (en la definicion de la estructura y/o en las
 * operaciones basicas de una lista simple) y que además realice las siguientes
 * operaciones:
 *
 * a. Agregar elementos a la lista, permitiendo al usuario elegir si se agrega por
 * el inicio o el final.
 * b. Indicar la cantidad de valores no primos que tiene la lista
 * c. Mostrar los valores primos de la lista
 * d. Mostrar y quitar el menor elemento de la lista
 * e. Calcular el promedio de los valores ingresados y mostrar los valores que lo
 * superan
 */


// Nombre de espacio
using namespace std;

void menu() {
    cout << "1. Agregar elementos en la lista" << endl;
    cout << "2. Mostrar cantidad de valores no primos en la lista" << endl;
    cout << "3. Mostrar los valores primos de la lista" << endl;
    cout << "4. Mostrar y eliminar el menor elemento de la lista" << endl;
    cout << "5. Calcular promedio y mostrar valores que lo superen" << endl;
    cout << "6. Salir" << endl;
}



int main() {
    TLista lista;
    crearLista(lista);
    int opcion, seleccion, dato;

    do {
        cout << "Bienvenido" << endl;
        cout << endl;
        menu();
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        fflush(stdin);
        system("cls");
        switch (opcion) {
            case 1:
                cout << "1. Agregar al inicio" << endl;
                cout << "2. Agregar al final" << endl;
                cout << endl;
                cout << "Ingrese una opcion: " << endl;
                cin >> seleccion;
                fflush(stdin);
                system("cls");

                if (seleccion == 1) {
                    cout << "Ingrese el valor: ";
                    cin >> dato;
                    system("cls");
                    insertarInicio(lista, dato);
                }

                if (seleccion == 2) {
                    cout << "Ingrese el valor: ";
                    cin >> dato;
                    system("cls");
                    insertarUltimo(lista, dato);
                }
                break;
            case 2:
                cantidadNoPrimos(lista);
                break;
            case 3:
                mostrarNPrimos(lista);
                break;
            case 4:
                eliminarMenor(lista);
                break;
            case 5:
                mostrarMayorQuePromedio(lista);
                break;
            case 6:
                liberarMemoria(lista);
                break;
            default:
                cout << "Opcion invalida.";
                break;
        }
    } while (opcion != 6 && lista.contador <= 25);
    return 0;
}