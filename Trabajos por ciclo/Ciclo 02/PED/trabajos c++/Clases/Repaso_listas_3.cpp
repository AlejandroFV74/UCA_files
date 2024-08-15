#include <iostream>
#include <string>

using namespace std;

// estructura de la contacto
struct Contacto
{
    string numero;
    string nombre;
};

// estructura del nodo
struct Nodo
{
    Contacto contacto;
    Nodo *siguiente;
    Nodo *anterior;
};

// prototipos de funciones
void menu();
void insertarLista(Nodo *&, Contacto);
void mostrarLista(Nodo *);
void mostrarContacto(Nodo *&);

// Inicializando la lista
Nodo *lista = NULL;

int main()
{
    menu();
    return 0;
}

// funcion para mostrar el menu
void menu()
{
    int opcion;
    Contacto contacto;
    do
    {
        cout << "\t.:MENU:." << endl;
        cout << "1. Agregar nuevo contacto" << endl;
        cout << "2. Mostrar todos los contactos" << endl;
        cout << "3. Mostrar contactos individuales" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            cout << "\nNombre de la persona: ";
            getline(cin, contacto.nombre);
            cout << "\nNumero telefonico:";
            getline(cin, contacto.numero);
            insertarLista(lista, contacto);
            cout << "\n";
            system("pause");
            break;
        case 2:
            mostrarLista(lista);
            cout << "\n";
            system("pause");
            break;
        case 3:
            mostrarContacto(lista);
            cout << "\n";
            system("pause");
            break;
        case 4:
            break;
        }
        system("cls");
    } while (opcion != 4);
}

// funcion para insertar elementos a la lista
void insertarLista(Nodo *&lista, Contacto contacto)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->contacto = contacto;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->contacto.nombre < contacto.nombre))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    cout << "\nElemento " << contacto.nombre << " insertado a la lista correctamente" << endl;
}

// funcion para mostrar los elementos de la lista
void mostrarLista(Nodo *lista)
{
    Nodo *actual = new Nodo();
    actual = lista;

    while (actual != NULL)
    {
        cout << "______________________________________________________" << endl;
        cout << "Nombre: " << actual->contacto.nombre << endl;
        cout << "Numero: " << actual->contacto.numero << endl;
        cout << "______________________________________________________" << endl;
        cout << "\n";
        actual = actual->siguiente;
    }
}

// funcion que muestra la primera cancion de la lista y pregunta si desea avanzar a la siguiente cancion o retroceder a la anterior
void mostrarContacto(Nodo *&lista)
{
    Nodo *actual = new Nodo();
    Nodo *aux = new Nodo();
    actual = lista;
    int opcion;

    do
    {
        cout << "______________________________________________________" << endl;
        cout << "\nNombre: " << actual->contacto.nombre << endl;
        cout << "Numero: " << actual->contacto.numero << endl;
        cout << "\n1. Siguiente contacto \n2. Contacto anterior \n3. Salir" << endl;

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // verifica si el contacto siguiente es nulo
            if (actual->siguiente == NULL)
            {
                cout << "\nNo hay mas contactos en tu lista" << endl;
            }
            else
            {
                // hace los cambios y evita que se pierda la lista
                //  aux = actual;
                //  actual->anterior = aux;
                //  actual = actual->siguiente;

                aux = actual;
                actual = actual->siguiente;
                actual->anterior = aux;
            }
            break;
        case 2:
            // verifica si la cancion anterior es nula
            if (actual->anterior == NULL)
            {
                cout << "\nNo hay mas contactos en tu lista" << endl;
            }
            else
            {
                // realiza los cambios y evita que la lista cambie y cree un bucle
                aux = actual;
                actual = actual->anterior;
                actual->siguiente = aux;
            }
            break;
        case 3:
            break;
        }
    } while (opcion != 3);
}

