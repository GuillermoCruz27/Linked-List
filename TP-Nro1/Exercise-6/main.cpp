#include <iostream>
#include "LSSimpleDoblePuntero.hpp"

#define endl '\n'

/*
 * Modificar la definición de la estructura de Listas Simples y las operaciones básicas, considerando que la nueva
 * representación tiene un puntero inicio y un puntero final, donde el puntero inicio apunta al primer elemento de la
 * lista, mientras que puntero final apunta al último elemento de la lista.
 */

using namespace std;

inline void Menu() {
    cout << "1. Insertar al inicio" << endl;
    cout << "2. Insertar al final" << endl;
    cout << "3. Eliminar al inicio" << endl;
    cout << "4. Eliminar al final" << endl;
    cout << "5. Mostrar lista" << endl;
    cout << "6. Limpiar lista" << endl;
    cout << "7. Salir" << endl;
}

int main() {
    int option, valor;
    TLista lista{};
    CrearLista(lista);
    do {
        Menu();
        cout << "Ingrese una opción: ";
        cin >> option;
        fflush(stdin);
        system("cls");
        switch (option) {
            case 1:
                cout << "Ingrese un valor: ";
                cin >> valor;
                InsertarInicio(lista, valor);
                break;
            case 2:
                cout << "Ingrese un valor: ";
                cin >> valor;
                InsertarFinal(lista, valor);
                break;
            case 3:
                EliminarInicio(lista);
                break;
            case 4:
                EliminarFinal(lista);
                break;
            case 5:
                MostrarLista(lista);
                break;
            case 6:
                LimpiarLista(lista);
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
        system("pause");
        system("cls");
    } while (option != 7);
    return 0;
}