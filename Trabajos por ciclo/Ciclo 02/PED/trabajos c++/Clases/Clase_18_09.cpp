#include <iostream>

using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;

} 
struct Nodo *frenteCola = nullptr;
struct Nodo *finalCola = nullptr;

void insertar(int);
bool Vacia();
void imprimirFrente();
void eliminar();
void imprimir();



int main()
{
    int valor;

    for (int i = 0; i < 5; i++)
    {
        cout<<"Ingrese un valor: "<<endl; 
        cin>>valor;
    }
    insertar(valor);
    cout<< "-------------------------"<<endl;

    eliminar();
    imprimir();
    


    return 0;
}

void insertar(int n)
{
    // reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    if (Vacia())
    {
        // No hay nadie en el frente de cola, elemento queda al frente
        frenteCola = nuevoNodo;
    }
    else
    {
        // si habian elementos en la cola y por lo tanto se posiciona
        // despues del elemento que estan en la cola
        finalCola->nuevoNodo;
    }
}

bool Vacia()
    struct Nodo *nuevoNodo = new Nodo();
{
    if (frenteCola == nullptr)
    {
        return true;
    }
    else
    {
        finalCola->siguiente = nuevoNodo;
    }
    // se establece el final de la cola en el nuevo nodo agregado
    finalCola = nuevoNodo;
}

void imprimirFrente(){
     struct Nodo *temporal =frenteCola;
     if(temporal==nullptr){
        cout<<"La cola esta vacia. No hay elemento al frente"<<endl;
     }
}

void eliminar(){
    struct Nodo *temporal=frenteCola;
    if(frenteCola==finalCola){
        frenteCola=nullptr;
        finalCola=nullptr;
    }
    else{
        frenteCola=frenteCola->siguiente;
    }
    delete temporal;
}

void imprimir()
{
    struct Nodo *temporal = frenteCola;
    while (temporal != nullptr)
    {
        cout << "Elementos de la cola" << temporal->elemento << endl;
        temporal = temporal->siguiente;
    }
}