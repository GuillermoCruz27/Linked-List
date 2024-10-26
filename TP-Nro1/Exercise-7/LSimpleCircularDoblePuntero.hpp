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

void CrearLista(TLista &lista) {
    lista.inicio = nullptr;
    lista.final = nullptr;
    lista.contador = 0;
}

void CrearNodo(PunteroNodo &nuevo, dato valor) {
    nuevo = new Nodo;
    nuevo->info = valor;
    nuevo->sig = nullptr;
}

void InsertarInicio(TLista &lista, dato valor) {
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

void InsertarFinal(TLista &lista, dato valor) {
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

void EliminarInicio(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else if (lista.inicio == lista.final) {
        delete lista.inicio;
        lista.inicio = nullptr;
        lista.final = nullptr;
    } else {
        PunteroNodo extraido = lista.inicio;
        lista.inicio = lista.inicio->sig;
        delete extraido;
        lista.final->sig = lista.inicio;
    }
    lista.contador--;
}

void EliminarFinal(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else if (lista.inicio == lista.final) {
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

void MostrarLista(TLista &lista) {
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

void LiberarMemoria(TLista &lista) {
    while (lista.inicio != nullptr) {
        EliminarInicio(lista);
    }
}

void MostrarOpciones() {
    cout << "Menu" << endl;
    cout << "1. Insertar al inicio." << endl;
    cout << "2. Insertar al final." << endl;
    cout << "3. Eliminar al inicio." << endl;
    cout << "4. Eliminar al final." << endl;
    cout << "5. Mostrar elementos." << endl;
    cout << "6. Salir." << endl;
    cout << endl;
    cout << "Ingrese una opción: ";
}