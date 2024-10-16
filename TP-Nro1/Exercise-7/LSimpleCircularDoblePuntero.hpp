#pragma once

#include <iostream>

#define endl '\n'

using namespace std;

typedef float dato;

struct Nodo {
    dato info;
    Nodo *sig;
};

typedef Nodo *PunteroNodo;

struct TLista {
    PunteroNodo inicio;
    PunteroNodo final;
    int contador;
};

inline void CrearLista(TLista &lista) {
    lista.inicio = nullptr;
    lista.final = nullptr;
    lista.contador = 0;
}

inline void CrearNodo(PunteroNodo &nuevo, dato valor) {
    nuevo = new Nodo;
    nuevo->info = valor;
    nuevo->sig = nullptr;
}

inline void InsertarInicio(TLista &lista, dato valor) {
    PunteroNodo nuevo;
    CrearNodo(nuevo, valor);
    if (lista.inicio == nullptr) {
        lista.inicio = nuevo;
        lista.final = nuevo;
        nuevo->sig = nuevo;
    } else {
        nuevo->sig = lista.inicio;
        lista.final->sig = nuevo;
        lista.inicio = nuevo;
    }
    lista.contador++;
}

inline void InsertarFinal(TLista &lista, dato valor) {
    PunteroNodo nuevo;
    CrearNodo(nuevo, valor);
    if (lista.inicio == nullptr) {
        lista.inicio = nuevo;
        lista.final = nuevo;
        nuevo->sig = nuevo;
    } else {
        lista.final->sig = nuevo;
        nuevo->sig = lista.inicio;
        lista.final = nuevo;
    }
    lista.contador++;
}

inline void EliminarInicio(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else {
        PunteroNodo extraido = lista.inicio;
        lista.inicio = lista.inicio->sig;
        delete extraido;
        lista.final->sig = lista.inicio;
    }
    lista.contador--;
}

inline void EliminarFinal(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else {
        PunteroNodo extraido = lista.final;
        PunteroNodo previoExtraido = lista.inicio;
        while (previoExtraido->sig != lista.final) {
            previoExtraido = previoExtraido->sig;
        }
        previoExtraido->sig = lista.inicio;
        delete extraido;
        lista.final = previoExtraido;
    }
    lista.contador--;
}

inline void MostrarLista(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "La lista esta vacia." << endl;
    } else {
        PunteroNodo actual = lista.inicio;
        do {
            cout << actual->info << " -> ";
            actual = actual->sig;
        } while (actual != lista.inicio);
    }
}

inline void LiberarMemoria(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else {
        while (lista.inicio != nullptr) {
            EliminarInicio(lista);
        }
        lista.final = nullptr;
        lista.contador = 0;
    }
}

inline void MostrarOpciones() {
    cout << "Menu" << endl;
    cout << "1. Insertar al inicio." << endl;
    cout << "2. Insertar al final." << endl;
    cout << "3. Eliminar al inicio." << endl;
    cout << "4. Eliminar al final." << endl;
    cout << "5. Mostrar elementos." << endl;
    cout << "6. Salir." << endl;
    cout << endl;
    cout << "Ingrese una opcion: ";
}

inline void Menu() {
    TLista lista;
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
                cout << "Opcion invalida." << endl;
                break;
        }
        system("pause");
        system("cls");
    } while (opcion != 6 && lista.contador <= 30);

}