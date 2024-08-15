// Encontrar el máximo número y mínimo de un arreglo

#include <iostream>

using namespace std;

int main()
{

/*
    int arreglo[6] = {45, 50, 80, 5, 4, 100};
    int max = 100, min = 4;
    int dimension = sizeof(arreglo) / sizeof(int);

    for (int i = 0; i < dimension; i++)
    {
        if (min < arreglo[i])
        {
            max = arreglo[i];
        }
        else if (max > arreglo[i])
        {
            min = arreglo[i];
        }
    }
    cout << "Número menor: " << min << endl;
    cout << "Número mayor: " << max << endl;
    */

//Crear un arreglo que almacene 3 autores y otro arreglo 3 libros

    string arregloautor[3];
    string arreglolibro[3];

    for (int i = 0; i < 3; i++)
    {
        cout<<"ingrese autor: "<<endl;
        cin>>arregloautor[i];
        cout<<"ingrese libro: "<<endl;
        cin>>arreglolibro[i];
    }
    for (int i = 0; i <= 2; i++)
    {
    cout<< arregloautor[i]<<endl;
    cout<< arreglolibro [i]<<endl;
    }
    





    return 0;
}