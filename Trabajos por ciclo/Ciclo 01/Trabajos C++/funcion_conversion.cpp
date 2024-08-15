// Crear función para convertir dolares a euros, tomando valores pares

#include <iostream>

using namespace std;

int convertion(int cantidadDolares);
int cantidadEuros;

int main()
{

    int cantidadDolares;

    cout << "Ingrese la cantidad de dólares a convertir: " << endl;
    cin >> cantidadDolares;
    cout << "La cantidad en euros son:" << convertion(cantidadDolares) << endl;

    return 0;
}

int convertion(int cantidadDolares)
{

    if ((cantidadDolares % 2) == 0)
    {
        return cantidadDolares * 0.93;
    }
    else
    {
        return 0;
    }
}