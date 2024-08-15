// Pilas
#include <iostream>
#include <stack>

using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};

struct Nodo *pila = nullptr;

void Insertar(int);
void EliminarUltimo();
void Imprimir();
void Vacia();
void UltimoElemento();

int main()
{

    int valor;

    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese un valor:" << endl;
        cin >> valor;
        Insertar(valor);
    }
        EliminarUltimo();
        Imprimir();
        Vacia();
        UltimoElemento();
    

    return 0;
}

// operacion push
void Insertar(int n)
{
    // reserva de momoria
    struct Nodo *nuevoNodo = new Nodo();
    // asignar el valor
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

// Imprimir la pila
void Imprimir()
{
    struct Nodo *temporal = pila;
    while (temporal != nullptr)
    {
        cout << "Elemento de la pila: " << temporal->elemento << " - Direccion: "<< temporal->siguiente<< endl;
        temporal = temporal->siguiente;
    }
}

// Operación pop
void EliminarUltimo()

{
    int n;
    if (pila != nullptr)

    {
        struct Nodo *temporal = pila;
        // valor a eliminar
        n = temporal->elemento;
        cout << n << "\n";
        pila = temporal->siguiente;
        delete temporal;
    }
}

void Vacia()
{
    if (pila == NULL)
    {
        cout << "Pila vacia" << endl;
    }
    else
    {
        cout << "Pila llena" << endl;
    }
}

// Opepraciónn top
void UltimoElemento()
{
    cout<< pila->elemento<< " - "<< pila<<endl;
}