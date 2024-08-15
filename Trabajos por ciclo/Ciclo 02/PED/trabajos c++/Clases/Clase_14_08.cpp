#include <iostream>

using namespace std;

int total = 0;
int total2 = 0;
int a = 0;
int mult = 1;

int arregloNumeros[10];

// Realizar una función que me permita sumar 10 números

void suma(int arregloNumeros[]);

//Realizar una función que me permita calcular el factorial de un número

int calcularFactorial(int);

int main()
{

    int a;

    suma(arregloNumeros);

    for (int i = 0; i < 10; i++)
    {

        total += arregloNumeros[i];
    }

    cout << "El total es de: " << total << endl;

    cout << "ingrese el numero del cual desea su factorial: " << endl;
    cin >> a;

    cout << "El factorial de " << a << " es " << calcularFactorial(a);

    return 0;
}

void suma(int arregloNumeros[])
{

    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese un numero" << endl;
        cin >> arregloNumeros[i];
    }
}

int calcularFactorial(int a)
{

    for (int i = a; i >= 2; i--)
    {
        mult *= i;
    }
    return mult;
}
