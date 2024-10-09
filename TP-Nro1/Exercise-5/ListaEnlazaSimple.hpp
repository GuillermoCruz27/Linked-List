#pragma once

#include <iostream>

#define endl '\n'

using namespace std;

struct nodo {
    char info;
    nodo *sig;
};

typedef nodo *pnodo;

struct TLista {
    pnodo inicio;
    int contador;
};

inline void crearLista(TLista &lista) {
    lista.inicio = nullptr;
    lista.contador = 0;
}

inline void crearNodo(pnodo &nuevo, const char valor) {
    nuevo = new nodo;
    nuevo->info = valor;
    nuevo->sig = nullptr;
}

inline void insertarInicio(TLista &lista, const char valor) {
    pnodo nuevo;
    crearNodo(nuevo, valor);
    if (lista.inicio == nullptr) {
        lista.inicio = nuevo;
    } else {
        nuevo->sig = lista.inicio;
        lista.inicio = nuevo;
    }
    lista.contador++;
}

inline void insertarUltimo(TLista &lista, const char valor) {
    pnodo nuevo;
    crearNodo(nuevo, valor);
    if (lista.inicio == nullptr) {
        lista.inicio = nuevo;
    } else {
        pnodo i;
        for (i = lista.inicio; i->sig != nullptr; i = i->sig);
        i->sig = nuevo;
    }
    lista.contador++;
}

inline void eliminarInicio(TLista &lista) {
    pnodo nodo;
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
        nodo = nullptr;
    } else {
        nodo = lista.inicio;
        lista.inicio = lista.inicio->sig;
        nodo->sig = nullptr;
        delete(nodo);
    }
    lista.contador--;
}

inline void liberarMemoria(TLista &lista) {
    while (lista.inicio != nullptr) {
        eliminarInicio(lista);
    }
}

inline void buscarYMostrar(const TLista lista, const char valor) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else {
        for (pnodo i = lista.inicio; i != nullptr; i = i->sig) {
            if (i->info == valor) {
                cout << "El valor " << valor << " fue encontrado" << endl;
                if (i->sig != nullptr) {
                    cout << "Valor siguiente de " << valor << " es " << (i->sig)->info;
                } else {
                    cout << "Es el ultimo valor de la lista" << endl;
                }
            } else {
                cout << "El valor ingresado no se encuentra en la lista" << endl;
            }
        }
    }
}

inline void mostrarRecursivo(const pnodo nodo) {
    if (nodo == nullptr) {
        return;
    }

    cout << nodo->info << " -> ";
    mostrarRecursivo(nodo->sig);
}

inline void mostrarListaRecursivo(const TLista lista) {
    mostrarRecursivo(lista.inicio);
}


inline void mostrarCantidadTotal(const TLista lista) {
    int contadorMinus = 0;
    int contadorMayus = 0;
    int contadorDigit = 0;

    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
        return;
    }

    for (pnodo i = lista.inicio; i != nullptr; i = i->sig) {
        if (std::islower(i->info)) {
            contadorMinus++;
        } else if (std::isupper(i->info)) {
            contadorMayus++;
        } else if (std::isdigit(i->info)) {
            contadorDigit++;
        }
    }

    cout << "Minusculas: " << contadorMinus << endl;
    cout << "Mayusculas: " << contadorMayus << endl;
    cout << "Digitos: " << contadorDigit << endl;
}

inline void eliminarElemento(TLista &lista, char valor) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
        return;
    }

    pnodo previo = nullptr;
    pnodo previoValor = nullptr;
    pnodo extraido = nullptr;

    for (pnodo i = lista.inicio; i != nullptr; i = i->sig) {
        if (i->info == valor) {
            previoValor = previo;
            extraido = i;
        }
        previo = i;
    }

    if (extraido == lista.inicio) {
        lista.inicio = lista.inicio->sig;
    } else {
        previoValor->sig = extraido->sig;
    }

    cout << "Nodo con el valor " << extraido->info << " eliminado" << endl;
    delete extraido;
    lista.contador--;
}
