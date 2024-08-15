// Introducción a Programación Orientada a Objetos
#include <iostream>
#include <windows.h>

using namespace std;

class Atleta
{

public:
    int calcularEdad(int anioNac);
    float indiceMasaCorporal(float altura, float peso);
    string nombre;
    int anioNac;
    float altura;
    float peso;
    int edad;
};

int Atleta ::  calcularEdad(int anioNac)
{
    return 2023 - anioNac;
}

float Atleta :: indiceMasaCorporal(float altura, float peso){
    return (peso/ altura*altura);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Atleta atleta1;
    atleta1.nombre = "Hola";
    atleta1.altura = 1.85;
    atleta1.peso = 60;
    atleta1.anioNac= 2004;


    atleta1.calcularEdad(atleta1.anioNac);
    atleta1.indiceMasaCorporal(atleta1.altura, atleta1.peso);
    

    cout << "Edad: " << atleta1.calcularEdad(atleta1.anioNac) << endl;
    cout << "Indice de masa corporal: " << atleta1.indiceMasaCorporal(atleta1.altura, atleta1.peso) << endl;


    return 0;
}