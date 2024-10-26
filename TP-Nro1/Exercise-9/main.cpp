#include <iostream>
#include "Auxiliar.hpp"

#define endl '\n'

using namespace std;

/*
 * Dado una cadena con longitud mayor o igual a 5, realizar un programa que con ayuda de las operaciones de una LS
 * permita:
 *
 *  a. Generar una lista con las letras de la cadena ingresada ejemplo frase = "hola mundo" la lista tendra:
 *  'h' -> 'o' -> 'l' -> 'a' -> 'm' -> 'u' -> 'n' -> 'd' -> 'o'
 *  b. Determinar si la cadena ingresada es palindroma o no, una cadena es palindroma si puede leerse de igual forma
 *  tanto de izquierda a derecha o viceversa por ejemplo: "reconocer"
 *  c. Calcular cuantas vocales se ingresaron
 *  d. Determinar la mayor de las letras ingresadas
 *  e. Al salir del programa debera liberar la memoria ocupada por las listas.
 *
 *  NOTA: Cada operacion debe realizarse en un modulo y se administrara desde el programa principal mediante un menu de
 *  opciones.
 */

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    Menu();
    return 0;
}
