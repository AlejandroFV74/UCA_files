#include <iostream>
#include <fstream>
using namespace std;

void escribir();

int main()
{
    escribir();
    system("pause");
    return 0;
}

void escribir()
{
    ofstream archivo;
    //ios para entrada y salida
    archivo.open("menu.txt", ios::out); // Abrir archivo

    if (archivo.fail())
    {
        cout << "No se puede abrir el archivo";
        exit(1);
    }
    archivo << "Menu diario";

    archivo.close(); // cierra el archivo
}