#include <iostream>
#include <cctype>

#define endl '\n'

using namespace std;

struct Nodo {
    char info;
    Nodo *sig;
};

typedef Nodo *PunteroNodo;

struct TLista {
    PunteroNodo inicio;
    int contador;
};

inline void CrearLista(TLista &lista) {
    lista.inicio = nullptr;
    lista.contador = 0;
}

inline void CrearNodo(PunteroNodo &nuevo, char info) {
    nuevo = new Nodo;
    if (nuevo == nullptr) {
        cout << "La memoria esta llena" << endl;
    } else {
        nuevo->info = info;
        nuevo->sig = nullptr;
    }
}

inline void InsertarInicio(TLista &lista, char info) {
    PunteroNodo nuevo;
    CrearNodo(nuevo, info);
    nuevo->sig = lista.inicio;
    lista.inicio = nuevo;
    lista.contador++;
}

inline void InsertarFinal(TLista &lista, char info) {
    PunteroNodo nuevo;
    CrearNodo(nuevo, info);
    if (lista.inicio == nullptr) {
        lista.inicio = nuevo;
    } else {
        PunteroNodo i;
        for (i = lista.inicio; i->sig != nullptr; i = i->sig) {
        }
        i->sig = nuevo;
    }
    lista.contador++;
}

inline void EliminarInicio(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningun nodo" << endl;
    } else {
        PunteroNodo extraido = lista.inicio;
        lista.inicio = lista.inicio->sig;
        extraido->sig = nullptr;
        delete extraido;
    }
}

inline void EliminarFinal(TLista &lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningún nodo" << endl;
    } else {
        PunteroNodo extraido = nullptr;
        PunteroNodo actual = lista.inicio;
        PunteroNodo previo = nullptr;

        for (PunteroNodo i = lista.inicio; i != nullptr; i = i->sig) {
            extraido = i;
        }

        while (actual != extraido) {
            previo = actual;
            actual = actual->sig;
        }
        previo->sig = nullptr;
        delete extraido;
    }
}

inline void MostrarLista(TLista lista) {
    if (lista.inicio == nullptr) {
        cout << "No existe ningún nodo" << endl;
    } else {
        for (PunteroNodo i = lista.inicio; i != nullptr; i = i->sig) {
            cout << i->info << " -> ";
        }
        cout << endl;
    }
}

inline void LiberarMemoria(TLista &lista) {
    while (lista.inicio != nullptr) {
        EliminarInicio(lista);
    }
}

inline char ConvertirMinuscula(char letra) {
    if (letra >= 'A' && letra <= 'Z') {
        return tolower(letra);
    }
    return letra;
}

inline bool EsPalindromo(TLista lista) {
    if (lista.inicio == nullptr) {
        return true;
    }

    int longitud = 0;
    PunteroNodo temp = lista.inicio;
    while (temp != nullptr) {
        longitud++;
        temp = temp->sig;
    }

    char *arr = new char[longitud];
    temp = lista.inicio;
    for (int i = 0; i < longitud; i++) {
        arr[i] = ConvertirMinuscula(temp->info);
        temp = temp->sig;
    }

    for (int i = 0; i < longitud / 2; i++) {
        if (arr[i] != arr[longitud - i - 1]) {
            delete[] arr;
            return false;
        }
    }

    delete []arr;
    return true;
}

inline int ContarVocales(TLista lista) {
    int contador = 0;
    PunteroNodo temp = lista.inicio;
    while (temp != nullptr) {
        char c = ConvertirMinuscula(temp->info);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c ==
            'I' || c == 'O' || c == 'U') {
            contador++;
        }
        temp = temp->sig;
    }
    return contador;
}

inline char MayorLetra(TLista lista) {
    if (lista.inicio == nullptr) {
        return '\0';
    }

    char mayor = lista.inicio->info;
    PunteroNodo temp = lista.inicio->sig;
    while (temp != nullptr) {
        if (ConvertirMinuscula(temp->info) > ConvertirMinuscula(mayor)) {
            mayor = temp->info;
        }
        temp = temp->sig;
    }
    return mayor;
}

inline void MostrarOpciones() {
    cout << "Menú de opciones" << endl;
    cout << "1. Mostrar lista" << endl;
    cout << "2. Verificar si es palíndromo" << endl;
    cout << "3. Contar vocales" << endl;
    cout << "4. Encontrar la mayor letra" << endl;
    cout << "5. Salir" << endl;
    cout << "Elija una opción: ";
}

inline void Menu() {
    TLista lista{};
    char cadena[100];
    int opcion;
    CrearLista(lista);

    cout << "Ingrese cadena: ";
    cin.getline(cadena, 100);

    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }

    if (longitud < 5) {
        cout << "La cadena debe tener una longitud mayor o igual a 5" << endl;
    } else {
        for (int i = 0; i < longitud; i++) {
            InsertarFinal(lista, cadena[i]);
        }
        do {
            MostrarOpciones();
            cin >> opcion;
            fflush(stdin);
            system("cls");

            switch (opcion) {
                case 1:
                    MostrarLista(lista);
                    break;
                case 2:
                    cout << (EsPalindromo(lista) ? "Es palíndromo" : "No es palíndromo") << endl;
                    break;
                case 3:
                    cout << "Cantidad de vocales: " << ContarVocales(lista) << endl;
                    break;
                case 4:
                    cout << "La mayor letra es: " << MayorLetra(lista) << endl;
                    break;
                case 5:
                    LiberarMemoria(lista);
                    cout << "Saliendo..." << endl;
                    break;
                default:
                    cout << "Opción invalida" << endl;
                    break;
            }
            system("pause");
            system("cls");
        } while (opcion != 5);
    }
}
