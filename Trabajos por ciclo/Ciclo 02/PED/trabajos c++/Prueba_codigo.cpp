#include <iostream>
#include <string>
using namespace std;

struct Mascota {
    string nombre;
    int edad;
    bool vacunada;
};

void agregarMascota(Mascota* mascotas, int& contador);
void mostrarMascotas(const Mascota* mascotas, int contador);
void marcarVacunada(Mascota* mascotas, int contador);

int main() {
    const int capacidadMaxima = 100;
    Mascota mascotas[capacidadMaxima];
    int contadorMascotas = 0;
    int opcion;

    do {
        cout << "\n--- Menú ---" << endl;
        cout << "1. Agregar una mascota" << endl;
        cout << "2. Mostrar todas las mascotas" << endl;
        cout << "3. Marcar una mascota como vacunada" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarMascota(mascotas, contadorMascotas);
                break;
            case 2:
                mostrarMascotas(mascotas, contadorMascotas);
                break;
            case 3:
                marcarVacunada(mascotas, contadorMascotas);
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}

void agregarMascota(Mascota* mascotas, int& contador) {
    if (contador < 100) { // Evitamos desbordamiento
        Mascota nuevaMascota;
        cout << "Ingrese el nombre de la mascota: ";
        cin >> nuevaMascota.nombre;
        cout << "Ingrese la edad de la mascota: ";
        cin >> nuevaMascota.edad;
        cout << "¿La mascota ha sido vacunada? (1 para Sí, 0 para No): ";
        cin >> nuevaMascota.vacunada;

        mascotas[contador] = nuevaMascota;
        contador++;
    } else {
        cout << "No se pueden agregar más mascotas. Capacidad máxima alcanzada." << endl;
    }
}

void mostrarMascotas(const Mascota* mascotas, int contador) {
    if (contador == 0) {
        cout << "No hay mascotas registradas." << endl;
    } else {
        cout << "\n--- Lista de Mascotas ---" << endl;
        for (int i = 0; i < contador; i++) {
            cout << "Mascota " << i + 1 << ":" << endl;
            cout << "Nombre: " << mascotas[i].nombre << endl;
            cout << "Edad: " << mascotas[i].edad << " años" << endl;
            cout << "Vacunada: " << (mascotas[i].vacunada ? "Sí" : "No") << endl;
            cout << endl;
        }
    }
}

void marcarVacunada(Mascota* mascotas, int contador) {
    if (contador == 0) {
        cout << "No hay mascotas registradas." << endl;
    } else {
        int numeroMascota;
        cout << "Ingrese el número de la mascota que desea marcar como vacunada: ";
        cin >> numeroMascota;

        if (numeroMascota >= 1 && numeroMascota <= contador) {
            mascotas[numeroMascota - 1].vacunada = true;
            cout << "La mascota ha sido marcada como vacunada." << endl;
        } else {
            cout << "Número de mascota no válido." << endl;
        }
    }
}


void Eliminar(int pos){
    struct Nodo *aux =lista;
    int i=1;
    while (aux !=nullptr && i<pos)
    {
        aux= aux->siguiente;
        i++;
    }

    if(aux !=nullptr){
        aux->anterior->siguiente=aux->siguiente;
        aux->siguiente->anterior=aux->anterior;
    } else {
        cout<< "No se encontro"<<endl;
    }
    
}