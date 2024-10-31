#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *sig;
};

typedef Nodo *PunteroNodo;

struct TLista {
    PunteroNodo inicio;
    int contador;
};

void CrearLista(TLista &lista) {
    lista.inicio = NULL;
    lista.contador = 0;
}

void CrearNodo(PunteroNodo &nodo, int dato) {
    nodo = new Nodo;
    nodo -> dato = dato;
    nodo -> sig = NULL;
}

void InsertarInicio(TLista &lista, int dato) {
    PunteroNodo nodo;
    CrearNodo(nodo, dato);

    if (lista.inicio == NULL) {
        lista.inicio = nodo;
    } else {
        nodo -> sig = lista.inicio;
        lista.inicio = nodo;
    }
    lista.contador++;
}

void InsertarFinal(TLista &lista, int dato) {
    PunteroNodo nodo;
    CrearNodo(nodo, dato);

    if (lista.inicio == NULL) {
        lista.inicio = nodo;
    } else {
        PunteroNodo i;
        for (i = lista.inicio; i -> sig != NULL; i = i -> sig) {}
        i -> sig = nodo;
    }
    lista.contador++;
}

void EliminarInicio(TLista &lista) {
    if (lista.inicio == NULL) {
        cout << "No existe ningún nodo" << endl;
    } else if (lista.contador == 1) {
        delete lista.inicio;
        lista.inicio = NULL;
    } else {
        PunteroNodo extraido = lista.inicio;
        lista.inicio = lista.inicio -> sig;
        extraido -> sig = NULL;
        delete extraido;
    }
    lista.contador--;
}

void EliminarFinal(TLista &lista) {
    if (lista.inicio == NULL) {
        cout << "No existe ningún nodo" << endl;
    } else if (lista.contador == 1) {
        delete lista.inicio;
        lista.inicio = NULL;
    } else {
        PunteroNodo previo = NULL;
        PunteroNodo actual = lista.inicio;

        while (actual -> sig != NULL) {
            previo = actual;
            actual = actual -> sig;
        }
        previo -> sig = NULL;
        delete actual;
    }
    lista.contador--;
}

void MostrarLista(TLista lista) {
    if (lista.inicio == NULL) {
        cout << "No existe ningún nodo" << endl;
    } else {
        for (PunteroNodo i = lista.inicio; i != NULL; i = i -> sig) {
            cout << i -> dato << " -> ";
        }
    }
}

void LiberarMemoria(TLista &lista) {
    while (lista.inicio != NULL) {
        EliminarInicio(lista);
    }
}