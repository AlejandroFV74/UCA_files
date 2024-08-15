#include <iostream>
#include <fstream>
#include "pruebacodigo.hpp"

using namespace std;

void recibo();
string comida;
float Total();

int main()
{
    cout << "Ingrese su comida" << endl;
    cin >> comida;
    cout << "ingrese el precio de "<< comida << endl;
    cout << "$";
    cin >> precio;
    cout << "ingrese la cantidad de " << comida << " que desee" << endl;
    cin >> cantidad;
    recibo();
}

void recibo()
{
    ofstream tiquete;

    tiquete.open("tiquete.txt", ios::out | ios::app);
    if (tiquete.fail() == true)
    {
        cout << "No se pudo crear el archivo";
    }
    else // imprimira estos datos en el archivo txt
    {
        tiquete << "============================" << "\n";
        tiquete << endl;
        tiquete << "* Comida         " << comida << "(" << cantidad << ")" << "\n"; // El parentesis demuestra la cantidad de producto que se ha seleccionado
        tiquete << endl;
        tiquete << "* Precio unidad  $" << precio << "\n";
        tiquete << endl;
        tiquete << "* Total          $" << Total()  << "\n";
        tiquete << endl;
        tiquete << "============================" << "\n";
    }
}