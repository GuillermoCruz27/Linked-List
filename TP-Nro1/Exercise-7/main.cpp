#include <iostream>
#include "LSimpleCircularDoblePuntero.hpp"

#define endl '\n'

using namespace std;

/*
 * Modifique el programa del item 6 de modo tal que genere una Lista Simple Circular con un puntero de inicio y final
 * de valores reales, tenga en cuenta que la lista solo puede almacenar 30 elementos.
 */

int main() {
    TLista lista{};
    int opcion;
    float valor;
    CrearLista(lista);
    do {
        MostrarOpciones();
        cin >> opcion;
        fflush(stdin);
        system("cls");
        switch (opcion) {
            case 1:
                cout << "Ingrese un valor(real): ";
                cin >> valor;
                InsertarInicio(lista, valor);
                break;
            case 2:
                cout << "Ingrese un valor(real): ";
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
                cout << "Saliendo..." << endl;
                LiberarMemoria(lista);
                break;
            default:
                cout << "Opción invalida." << endl;
                break;
        }
        system("pause");
        system("cls");
    } while (opcion != 6 && lista.contador <= 30);
    return 0;
}
