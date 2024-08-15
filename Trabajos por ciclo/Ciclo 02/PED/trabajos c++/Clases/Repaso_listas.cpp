#include <iostream>

using namespace std;

// Estructura de un elemento de la lista
struct Persona{
    int id;
    string nombre;
    int edad;
};

// Estructura de un nodo de la lista circular
struct Nodo{
    Persona persona;
    Nodo *siguiente;
    Nodo *anterior;
} *primero, *ultimo; // Punteros para el primer y último elemento de la lista

int id = 0; // Variable global para asignar el id a cada persona

// Prototipos de funciones
void insertarNodo();
void mostrarPrimeroAlUltimo();
void mostrarUltimoAlPrimero();

int main(){
    // Inicializamos los punteros
    primero = NULL;
    ultimo = NULL;

    // Insertamos 3 personas
    for (int i = 0; i < 3; i++)
    {
        insertarNodo();
    }

    // Mostramos la lista del primero al último
    cout<<"-------------------------------------------------\n";
    cout << "Lista del primero al ultimo" << endl;
    mostrarPrimeroAlUltimo();


    // Mostramos la lista del último al primero
    cout<<"-------------------------------------------------\n";
    cout << "Lista del ultimo al primero" << endl;
    mostrarUltimoAlPrimero();
    
    return 0;
}

// Función para insertar un nodo en la lista
void insertarNodo(){
    // Creamos un nuevo nodo
    Nodo *nuevo = new Nodo();
    // Asignamos los valores
    nuevo->persona.id = id++;
    cout << "Nombre: ";
    cin >> nuevo->persona.nombre;
    cout << "Edad: ";
    cin >> nuevo->persona.edad;

    // Si la lista está vacía
    if(primero == NULL){
        // El nuevo nodo será el primero y el último
        primero = nuevo;
        ultimo = nuevo;
        // El siguiente del nuevo nodo será el primero
        nuevo->siguiente = primero;
        // El anterior del nuevo nodo será el último
        nuevo->anterior = ultimo;
    }
    else{
        // El siguiente del nuevo nodo será el primero
        nuevo->siguiente = primero;
        // El anterior del nuevo nodo será el último
        nuevo->anterior = ultimo;
        // El siguiente del último nodo será el nuevo
        ultimo->siguiente = nuevo;
        // El anterior del primero nodo será el nuevo
        primero->anterior = nuevo;
        // El nuevo nodo será el último
        ultimo = nuevo;
    }
}

// Función para mostrar la lista del primero al último
void mostrarPrimeroAlUltimo(){
    // Creamos un nodo auxiliar para recorrer la lista
    Nodo *aux = primero;
    // Si la lista no está vacía
    if(primero != NULL){
        // Mientras no lleguemos al último nodo
        do{
            // Mostramos los datos del nodo
            cout << "ID: " << aux->persona.id << endl;
            cout << "Nombre: " << aux->persona.nombre << endl;
            cout << "Edad: " << aux->persona.edad << endl;
            // Avanzamos al siguiente nodo
            aux = aux->siguiente;
        }while(aux != primero);
    }
    else{
        cout << "La lista está vacía" << endl;
    }
}

// Función para mostrar la lista del último al primero
void mostrarUltimoAlPrimero(){
    // Creamos un nodo auxiliar para recorrer la lista
    Nodo *aux = ultimo;
    // Si la lista no está vacía
    if(ultimo != NULL){
        // Mientras no lleguemos al primer nodo
        do{
            // Mostramos los datos del nodo
            cout << "ID: " << aux->persona.id << endl;
            cout << "Nombre: " << aux->persona.nombre << endl;
            cout << "Edad: " << aux->persona.edad << endl;
            // Avanzamos al anterior nodo
            aux = aux->anterior;
        }while(aux != ultimo);
    }
    else{
        cout << "La lista está vacía" << endl;
    }
}


