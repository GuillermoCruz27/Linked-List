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

void AgregarElemento(TLista &lista, int dato) {
    if (lista.inicio == NULL) {
        InsertarInicio(lista, dato);
    } else if (lista.contador == 1) {
        if (dato < lista.inicio -> dato) {
            InsertarInicio(lista, dato);
        } else if (dato > lista.inicio -> dato) {
            InsertarFinal(lista, dato);
        }
    } else {
        PunteroNodo previo = NULL;
        PunteroNodo actual = lista.inicio;

        while (actual != NULL && dato > actual -> dato) {
            previo = actual;
            actual = actual -> sig;
        }

        if (previo == NULL) {
            InsertarInicio(lista, dato);
        } else if (actual == NULL) {
            InsertarFinal(lista, dato);
        } else {
            PunteroNodo nodo;
            CrearNodo(nodo, dato);
            previo -> sig = nodo;
            nodo -> sig = actual;
            lista.contador++;
        }
    }
}

void MostrarMayor(TLista &lista) {
    if (lista.inicio == NULL) {
        cout << "No existe ningún nodo" << endl;
    } else {
        PunteroNodo i;
        for (i = lista.inicio; i -> sig != NULL; i = i -> sig) {}
        cout << "El mayor de los datos ingresados es: " << i -> dato << endl;
    }
}

void ContarPositivos(TLista lista) {
    if (lista.inicio == NULL) {
        cout << "No existe ningún nodo" << endl;
    } else {
        int contador = 0;
        for (PunteroNodo i = lista.inicio; i != NULL; i = i -> sig) {
            if (i -> dato > 0) {
                contador++;
            }
        }
        cout << "La cantidad de datos positivos ingresados es: " << contador << endl;
    }
}

void Menu() {
    cout << "Menú" << endl;
    cout << endl;
    cout << "1. Agregar elemento" << endl;
    cout << "2. Mostrar el mayor de los datos ingresados" << endl;
    cout << "3. Eliminar el menor valor de la lista" << endl;
    cout << "4. Cantidad de datos positivos ingresados" << endl;
    cout << "5. Salir" << endl;
}