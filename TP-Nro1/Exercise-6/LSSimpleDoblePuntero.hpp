#include <iostream>

#define endl '\n'

using namespace std;

typedef int dato;

struct Nodo {
    dato info;
    Nodo *sig;
};

typedef Nodo *Puntero;

struct TLista {
    Puntero inicio;
    Puntero final;
    dato contador;
};

inline void CrearLista(TLista &lista) {
    lista.inicio = nullptr;
    lista.final = nullptr;
    lista.contador = 0;
}

inline void CrearNodo(Puntero &nodo, dato valor) {
    nodo = new Nodo;
    nodo->info = valor;
    nodo->sig = nullptr;
}

inline void InsertarInicio(TLista &lista, dato valor) {
    Puntero nodo;
    CrearNodo(nodo, valor);
    if (lista.inicio == nullptr) {
        nodo->sig = lista.inicio;
        lista.inicio = nodo;
    } else {
        Puntero i;
        nodo->sig = lista.inicio;
        lista.inicio = nodo;
        for (i = lista.inicio; i->sig != nullptr; i = i->sig);
        i->sig = lista.final;
        lista.final = i;
    }
    lista.contador++;
}

inline void InsertarFinal(TLista &lista, dato valor) {
    Puntero nodo;
    CrearNodo(nodo, valor);
    if (lista.inicio == nullptr) {
        nodo->sig = lista.inicio;
        lista.inicio = nodo;
    } else {
        Puntero i;
        for (i = lista.inicio; i->sig != nullptr; i = i->sig);
        i->sig = nodo;
        lista.final = nodo;
    }
    lista.contador++;
}

inline void EliminarInicio(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else {
        Puntero nodo;
        nodo = lista.inicio;
        lista.inicio = lista.inicio->sig;
        nodo->sig = nullptr;
        delete(nodo);
    }
    lista.contador--;
}

inline void EliminarFinal(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else {
        Puntero nodo = nullptr;
        Puntero actual = lista.inicio;
        Puntero anterior = nullptr;

        while (actual->sig != nullptr) {
            anterior = actual;
            actual = actual->sig;
        }
        nodo = actual;
        if (anterior != nullptr) {
            anterior->sig = nullptr;
            lista.final = anterior;
        } else {
            lista.final = nullptr;
        }
        delete(nodo);
    }
    lista.contador--;
}

inline void MostrarLista(const TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else {
        for (Puntero i = lista.inicio; i != nullptr; i = i->sig) {
            cout << i->info << " ";
        }
    }
}

inline void LimpiarLista(TLista &lista) {
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