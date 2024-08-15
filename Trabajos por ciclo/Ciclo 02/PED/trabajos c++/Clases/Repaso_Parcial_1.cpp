// Ejercicio: Escribir función parametrizada por referencia o punteros un valor aleatorio que representa la
// cantidad de gasolina que se está transfiriendo.
// Escribir una función que actualice un struct sobre la cantidad de gasolina y diesel que tiene la bomba.
// Cada 5 segundos se debe visualizar los cambios de gasolina y diesel que están transferidos en la bomba.
//La bomba se llenará hasta los 100 galones.
#include <iostream>
#include <ctime> // Necesario para time
#include <cstdlib> // Necesario para srand y rand
#include <windows.h> // Necesario para Sleep en Windows

struct Gasolinera
{
    int cantGasolina;
    int cantDiesel;
} gasolinera;

void valorTransferido( struct Gasolinera &g);
void actualizarCant(float &actual, float &actual2);

using namespace std;

int main()
{

    gasolinera.cantGasolina = 0;
    gasolinera.cantDiesel = 0;

    while(true){
        valorTransferido(gasolinera);
        cout<<"Cantidad gasolina: "<< gasolinera.cantGasolina<< " - "<<"Cantidad diesel: "<<gasolinera.cantDiesel<<"\n";
        Sleep(5000);
    }


    return 0;
}

void actualizarCant(float &actual, float &actual2)
{
    int v = time(nullptr);
    int v2 = time(nullptr);
    srand(v);
    srand(v2);
    //cout << "Cantidad gasolina: " << v;
    //cout << "Cantidad Diesel: " << v2;
    actual = rand() % (5 + 1);
    actual2 = rand() % (5 + 1);
}

void valorTransferido( struct Gasolinera &g)
{
    float actual = 0;
    float actual2= 0;
    actualizarCant(actual, actual2);
     cout<< "Lectura actual: "<< "\n";
    if (gasolinera.cantGasolina<100){
        gasolinera.cantGasolina+=actual;
    }
    if(actual2<100){
      gasolinera.cantGasolina+=actual2;
    }
}
