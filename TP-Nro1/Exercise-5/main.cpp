/*
 * Autor: Guillermo Joaquin Cruz
 * Año: 2024
 * Asignatura: Estructura de datos
 * Tema: Listas Enlazadas
 */

//Importar librerias
#include <iostream>
#include "../Exercise-5/ListaEnlazaSimple.hpp"

#define endl '\n'

/*
 * Dada una lista de caracteres, adaptar la estructura y operaciones básicas de una lista simple. Además, incluya las
 * siguientes operaciones mediante un menú de opciones.
 *
 * a. Agregar letras a la lista
 * b. Buscar un elemento y de encontrarse mostrar el valor siguiente de ser posible.
 * c. Mostrar los elementos de la lista de manera recursiva
 * d. Determinar la cantidad de minúsculas, mayúsculas y dígitos que posee la lista
 * e. Eliminar un elemento determinado indicado por el usuario
 *
 * NOTA: cada operación debe realizarse en un módulo y se administrará desde el programa principal mediante un menú
 * de opciones.
 */

using namespace std;


void menu() {
    cout << "a. Agregar letra a la lista" << endl;
    cout << "b. Buscar un elemento" << endl;
    cout << "c. Mostrar todos los elementos de la lista" << endl;
    cout << "d. Mostrar cantidad de minusculas, mayusculas y digitos" << endl;
    cout << "e. Eliminar un elemento" << endl;
    cout << "f. Salir" << endl;
}

int main() {
    TLista lista;
    char opcion, seleccion;
    crearLista(lista);

    do {
        cout << "---- BIENVENIDO ----" << endl;
        cout << endl;
        menu();
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        fflush(stdin);
        system("cls");
        switch (opcion) {
            case 'a':
                cout << "Ingrese valor: ";
                cin >> seleccion;
                system("cls");
                insertarUltimo(lista, seleccion);
                break;
            case 'b':
                cout << "Ingrese valor: ";
                cin >> seleccion;
                system("cls");
                buscarYMostrar(lista, seleccion);
                break;
            case 'c':
                mostrarListaRecursivo(lista);
                break;
            case 'd':
                mostrarCantidadTotal(lista);
                break;
            case 'e':
                cout << "Ingrese valor: ";
                cin >> seleccion;
                system("cls");
                eliminarElemento(lista, seleccion);
                break;
            case 'f':
                liberarMemoria(lista);
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
        system("pause");
    } while (opcion != 'f');
    return 0;
}
