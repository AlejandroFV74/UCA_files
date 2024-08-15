/*ejemplo que utiliza un Árbol Binario de Búsqueda (ABB)
para implementar un diccionario de palabras en C++*/
#include <iostream>
#include <string>

using namespace std;

// Estructura para representar una palabra y su significado
struct Palabra
{
    string palabra;
    string significado;
    Palabra *izquierda;
    Palabra *derecha;
};

// Función para crear un nuevo nodo de palabra
Palabra *CrearPalabra(string palabra, string significado)
{
    Palabra *nuevaPalabra = new Palabra;
    nuevaPalabra->palabra = palabra;
    nuevaPalabra->significado = significado;
    nuevaPalabra->izquierda = nullptr;
    nuevaPalabra->derecha = nullptr;
    return nuevaPalabra;
}

// Función para insertar una palabra en el ABB
Palabra *InsertarPalabra(Palabra *raiz, string palabra, string significado)
{
    if (raiz == nullptr)
    {
        return CrearPalabra(palabra, significado);
    }

    if (palabra < raiz->palabra)
    {
        raiz->izquierda = InsertarPalabra(raiz->izquierda, palabra, significado);
    }
    else if (palabra > raiz->palabra)
    {
        raiz->derecha = InsertarPalabra(raiz->derecha, palabra, significado);
    }

    return raiz;
}

// Función para buscar una palabra en el ABB
Palabra *BuscarPalabra(Palabra *raiz, string palabra)
{
    if (raiz == nullptr || raiz->palabra == palabra)
    {
        return raiz;
    }

    if (palabra < raiz->palabra)
    {
        return BuscarPalabra(raiz->izquierda, palabra);
    }

    return BuscarPalabra(raiz->derecha, palabra);
}

Palabra* EncontrarMinimo(Palabra* raiz) {
    while (raiz->izquierda != nullptr) {
        raiz = raiz->izquierda;
    }
    return raiz;
}


// Función para eliminar una palabra del ABB
Palabra *EliminarPalabra(Palabra *raiz, string palabra)
{
    if (raiz == nullptr)
    {
        return raiz;
    }

    if (palabra < raiz->palabra)
    {
        raiz->izquierda = EliminarPalabra(raiz->izquierda, palabra);
    }
    else if (palabra > raiz->palabra)
    {
        raiz->derecha = EliminarPalabra(raiz->derecha, palabra);
    }
    else
    {
        // Palabra encontrada, eliminarla

        if (raiz->izquierda == nullptr)
        {
            Palabra *temp = raiz->derecha;
            delete raiz;
            return temp;
        }
        else if (raiz->derecha == nullptr)
        {
            Palabra *temp = raiz->izquierda;
            delete raiz;
            return temp;
        }

        Palabra *temp = EncontrarMinimo(raiz->derecha);
        raiz->palabra = temp->palabra;
        raiz->significado = temp->significado;
        raiz->derecha = EliminarPalabra(raiz->derecha, temp->palabra);
    }

    return raiz;
}

// Función para realizar un recorrido en orden del ABB
void Inorden(Palabra *raiz)
{
    if (raiz == nullptr)
    {
        return;
    }

    Inorden(raiz->izquierda);
    cout << "Palabra: " << raiz->palabra << ", Significado: " << raiz->significado << endl;
    Inorden(raiz->derecha);
}

int main()
{
    Palabra *raiz = nullptr;

    while (true)
    {
        cout << "Menú de Diccionario:" << endl;
        cout << "1. Agregar palabra" << endl;
        cout << "2. Buscar palabra" << endl;
        cout << "3. Eliminar palabra" << endl;
        cout << "4. Mostrar diccionario (ordenado por palabra)" << endl;
        cout << "5. Salir" << endl;

        int opcion;
        cin >> opcion;

        if (opcion == 1)
        {
            string palabra, significado;
            cout << "Ingrese la palabra: ";
            cin >> palabra;
            cout << "Ingrese el significado: ";
            cin.ignore(); // Limpiar el buffer
            getline(cin, significado);
            raiz = InsertarPalabra(raiz, palabra, significado);
        }
        else if (opcion == 2)
        {
            string palabra;
            cout << "Ingrese la palabra a buscar: ";
            cin >> palabra;
            Palabra *encontrada = BuscarPalabra(raiz, palabra);
            if (encontrada)
            {
                cout << "Palabra: " << encontrada->palabra << ", Significado: " << encontrada->significado << endl;
            }
            else
            {
                cout << "Palabra no encontrada en el diccionario." << endl;
            }
        }
        else if (opcion == 3)
        {
            string palabra;
            cout << "Ingrese la palabra a eliminar: ";
            cin >> palabra;
            raiz = EliminarPalabra(raiz, palabra);
        }
        else if (opcion == 4)
        {
            cout << "Diccionario (ordenado por palabra):" << endl;
            Inorden(raiz);
        }
        else if (opcion == 5)
        {
            break;
        }
        else
        {
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        }
    }

    // Liberar memoria
    // (No se realiza la liberación en este ejemplo, pero en una aplicación real se debe hacer)
    return 0;
}
