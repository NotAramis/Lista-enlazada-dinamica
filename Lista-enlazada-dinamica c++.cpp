#include <iostream>

using namespace std;

// primero se crear la estructura del nodo 
struct Nodo {
    int dato;
    Nodo* sig;
};

int main() {
    // luego se coloca el puntero inicial de la lista
    Nodo* lista = nullptr;
    char respuesta;

    // se implementa un menú interactivo
    do {
        cout << "Desea ingresar un nuevo valor ? (S / N) : ";
        cin >> respuesta;
            
        if (respuesta == 'S' || respuesta == 's') {
            int valor;
            cout << "Ingrese el valor: ";
            cin >> valor;

            // se crean los nodos dinámicos
            Nodo* nuevoNodo = new Nodo(); // se reserva memoria con 'new'
            nuevoNodo->dato = valor;      // se almacena el valor
            nuevoNodo->sig = nullptr;

            // se enlaza el nodo 
            if (lista == nullptr) {
                lista = nuevoNodo;
            }
            else {
                Nodo* auxiliar = lista;
                while (auxiliar->sig != nullptr) {
                    auxiliar = auxiliar->sig;
                }
                auxiliar->sig = nuevoNodo;
            }
            cout << "Nodo agregado correctamente.\n\n";
        }

    } while (respuesta == 'S' || respuesta == 's');

    // se muestra la lista completa
    cout << "\nContenido de la lista:" << endl;
    Nodo* actual = lista;
    while (actual != nullptr) {
        cout << "[ " << actual->dato << " | * ] -> ";
        actual = actual->sig;
    }
    cout << "NULL" << endl;

    while (lista != nullptr) {
        Nodo* temporal = lista;
        lista = lista->sig;
        delete temporal; // se libera la memoria 
    }

    cout << "\nMemoria liberada. Programa finalizado." << endl;

    return 0;
}
