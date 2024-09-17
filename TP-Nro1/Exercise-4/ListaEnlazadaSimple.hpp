#include <cmath>
#include <iostream>
#include <list>
#include <valarray>

using namespace std;

typedef int dato;

struct Nodo {
    dato info;
    Nodo *sig;
};

typedef Nodo *punteroNodo;


struct TLista {
    punteroNodo inicio;
    dato contador;
};


void crearLista(TLista &lista) {
    lista.inicio = nullptr;
    lista.contador = 0;
}

void crearNodo(punteroNodo &nuevo, dato info) {
    nuevo = new Nodo;
    if (nuevo == nullptr) {
        cout << "La memoria esta llena" << endl;
    } else {
        nuevo -> info = info;
        nuevo -> sig = nullptr;
    }
}

void insertarInicio(TLista &lista, dato info) {
    punteroNodo nuevo;
    crearNodo(nuevo, info);
    nuevo -> sig = lista.inicio;
    lista.inicio = nuevo;
    lista.contador++;
}

void insertarUltimo(TLista &lista, dato info) {
    punteroNodo i, nuevo;
    crearNodo(nuevo, info);

    if (lista.inicio == nullptr) {
        lista.inicio = nuevo;
    } else {
        for (i = lista.inicio; i -> sig != nullptr; i = i -> sig);
        i -> sig = nuevo;
    }

    lista.contador++;
}

void eliminarInicio(TLista &lista) {
    punteroNodo extraido;
    if (lista.inicio == nullptr) {
        extraido = nullptr;
    } else {
        extraido = lista.inicio;
        lista.inicio = lista.inicio -> sig;
        extraido -> sig = nullptr;
        delete(extraido);
    }
}

bool esPrimo(int num) {
    if (num <= 1) {
        return false;
    }

    if (num == 2) {
        return true;
    }

    if (num % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void cantidadNoPrimos(TLista lista) {
    punteroNodo i;
    int contador = 0;

    if (lista.inicio == nullptr) {
        cout << "La lista esta vacia" << endl;
    } else {
        for (i = lista.inicio; i != nullptr; i = i -> sig) {

            int num = i -> info;

            if (!esPrimo(num)) {
                cout << "El numero: " << num << " no es primo" << endl;
                contador++;
            }
        }
    }

    cout << "Cantidad de numeros no primos: " << contador << endl;
}

void mostrarNPrimos(TLista lista) {
    punteroNodo i;

    if (lista.inicio == nullptr) {
        cout << "La lista esta vacia" << endl;
    } else {
        for (i = lista.inicio; i != nullptr; i = i -> sig) {
            int num = i -> info;

            if (esPrimo(num)) {
                cout << "El numero: " << num << " es primo" << endl;
            }
        }
    }
}

int mostrarMenor(TLista lista) {
    punteroNodo i;
    int acumalador = 999999;

    for (i = lista.inicio; i != nullptr; i = i -> sig) {

        if (i -> info < acumalador) {
            acumalador = i -> info;
        }
    }

    cout << "El valor menor de la lista es: " << acumalador << endl;
    return acumalador;
}

void eliminarMenor(TLista &lista) {
    int num = mostrarMenor(lista);

    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
        return;
    }

    punteroNodo actual = lista.inicio;
    punteroNodo anterior = nullptr;
    punteroNodo nodoMenor = lista.inicio;
    punteroNodo anteriorNodoMenor = nullptr;

    while (actual != nullptr) {
        if (actual -> info == num) {
            anteriorNodoMenor = anterior;
            nodoMenor = actual;
        }
        anterior = actual;
        actual = actual -> sig;
    }

    if (nodoMenor == lista.inicio) {
        lista.inicio = lista.inicio -> sig;
    } else {
        anteriorNodoMenor -> sig = nodoMenor -> sig;
    }

    cout << "Nodo con el menor valor eliminado " << nodoMenor -> info << endl;
    delete nodoMenor;
    lista.contador--;
}

int calcularPromedio(TLista lista){
    punteroNodo i;
    int promedio, acumulador = 0;

    if (lista.inicio == nullptr) {
        cout << "No exite ningun nodo" << endl;
    } else {
        for (i = lista.inicio; i != nullptr; i = i -> sig) {
            acumulador += i -> info;
        }
    }

    return promedio = acumulador / lista.contador;
}

void mostrarMayorQuePromedio(TLista lista) {
    punteroNodo i;
    int num = calcularPromedio(lista);

    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else {
        for (i = lista.inicio; i != nullptr; i = i -> sig) {
            if (num < i -> info) {
                cout << "El nodo con el valor " << i -> info << " es mayor al promedio" << endl;
            }
        }
    }
}

void recorrerLista(TLista lista) {
    punteroNodo i;
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    }

    for (i = lista.inicio; i != nullptr; i = i -> sig) {
        cout << i -> info << " -> ";
    }
}

void liberarMemoria(TLista &lista) {
    while (lista.inicio != nullptr) {
        eliminarInicio(lista);
    }
}
