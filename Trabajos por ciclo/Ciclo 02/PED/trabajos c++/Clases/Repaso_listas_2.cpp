#include <iostream>
#include <string> // Necesaria para manejar nombres de contactos

using namespace std;

// Definición de la estructura nodo para los contactos
struct Contacto {
    string nombre;
    string numero;
    int edad;
    Contacto* siguiente;
};

// Definición de la estructura lista para los contactos
struct ListaContactos {
    Contacto* inicio;
    Contacto* fin;
};

// Prototipos de funciones
void inicializar(ListaContactos& l);
void agregarContacto(ListaContactos& l, string nombre, string numero, int edad);
void eliminarContacto(ListaContactos& l, string nombre);
void mostrarContactos(ListaContactos l);
float calcularPromedioEdades(ListaContactos l);
void mostrarContactoMenorEdad(ListaContactos l);
void mostrarMayoresDe18(ListaContactos l);

int main() {
    ListaContactos lista;
    inicializar(lista);

    while (true) {
        cout << "Menu de Contactos:" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Eliminar contacto" << endl;
        cout << "3. Mostrar contactos" << endl;
        cout << "4. Calcular promedio de edades" << endl;
        cout << "5. Mostrar contacto con menor edad" << endl;
        cout << "6. Mostrar contactos mayores de 18 anios" << endl;
        cout << "7. Salir" << endl;

        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            string nombre, numero;
            int edad;
            cout << "Ingrese el nombre del contacto: ";
            cin >> nombre;
            cout << "Ingrese el numero de telefono: ";
            cin >> numero;
            cout << "Ingrese la edad del contacto: ";
            cin >> edad;
            agregarContacto(lista, nombre, numero, edad);
        } else if (opcion == 2) {
            string nombre;
            cout << "Ingrese el nombre del contacto a eliminar: ";
            cin >> nombre;
            eliminarContacto(lista, nombre);
        } else if (opcion == 3) {
            mostrarContactos(lista);
        } else if (opcion == 4) {
            float promedio = calcularPromedioEdades(lista);
            cout << "El promedio de edades de los contactos es: " << promedio << endl;
        } else if (opcion == 5) {
            mostrarContactoMenorEdad(lista);
        } else if (opcion == 6) {
            mostrarMayoresDe18(lista);
        }else if (opcion == 7) {
            break;
        } else {
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        }
    }

    return 0;
}

// Función que inicializa la lista de contactos
void inicializar(ListaContactos& l) {
    l.inicio = nullptr;
    l.fin = nullptr;
}

// Función que agrega un contacto a la lista
void agregarContacto(ListaContactos& l, string nombre, string numero, int edad) {
    Contacto* nuevo = new Contacto;
    nuevo->nombre = nombre;
    nuevo->numero = numero;
    nuevo->edad = edad;
    nuevo->siguiente = nullptr;

    if (l.inicio == nullptr) {
        l.inicio = nuevo;
        l.fin = nuevo;
    } else {
        l.fin->siguiente = nuevo;
        l.fin = nuevo;
    }
}

// Función que elimina un contacto de la lista por nombre
void eliminarContacto(ListaContactos& l, string nombre) {
    if (l.inicio == nullptr) {
        cout << "La lista de contactos está vacía." << endl;
        return;
    }

    Contacto* actual = l.inicio;
    Contacto* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->nombre == nombre) {
            if (actual == l.inicio) {
                l.inicio = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }

            delete actual;
            cout << "Contacto '" << nombre << "' eliminado correctamente." << endl;
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    }

    cout << "Contacto '" << nombre << "' no encontrado en la lista." << endl;
}

// Función que muestra todos los contactos
void mostrarContactos(ListaContactos l) {
    if (l.inicio == nullptr) {
        cout << "La lista de contactos está vacía." << endl;
        return;
    }

    Contacto* actual = l.inicio;

    while (actual != nullptr) {
        cout << "Nombre: " << actual->nombre << ", Número: " << actual->numero << ", Edad: " << actual->edad << endl;
        actual = actual->siguiente;
    }
}

// Función que calcula el promedio de edades de los contactos
float calcularPromedioEdades(ListaContactos l) {
    if (l.inicio == nullptr) {
        return 0.0; // Si la lista está vacía, el promedio es 0.
    }

    int sumaEdades = 0;
    int contador = 0;
    Contacto* actual = l.inicio;

    while (actual != nullptr) {
        sumaEdades += actual->edad;
        contador++;
        actual = actual->siguiente;
    }

    return static_cast<float>(sumaEdades) / contador;
}

// Función que muestra el contacto con la menor edad
void mostrarContactoMenorEdad(ListaContactos l) {
    if (l.inicio == nullptr) {
        cout << "La lista de contactos está vacía." << endl;
        return;
    }

    Contacto* actual = l.inicio;
    Contacto* contactoMenorEdad = actual;

    while (actual != nullptr) {
        if (actual->edad < contactoMenorEdad->edad) {
            contactoMenorEdad = actual;
        }
        actual = actual->siguiente;
    }

    cout << "Contacto con menor edad: " << contactoMenorEdad->nombre << ", Edad: " << contactoMenorEdad->edad << endl;
}

void mostrarMayoresDe18(ListaContactos l) {
    if (l.inicio == nullptr) {
        cout << "La lista de contactos está vacía." << endl;
        return;
    }

    Contacto* actual = l.inicio;

    while (actual != nullptr) {
        if (actual->edad > 18) {
            cout << "Nombre: " << actual->nombre << ", Número: " << actual->numero << ", Edad: " << actual->edad << endl;
        }
        actual = actual->siguiente;
    }
}