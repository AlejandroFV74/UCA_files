//Crear función que calcule el promedio de los datos de un arreglo
//tomando como parametro el tamaño y los número del arreglo
#include <iostream>

using namespace std;

float promedio(int arreglo[], int tamaño);
int total;

int main(){
    int cantidad, suma, total;
    int arreglo[cantidad];

    cout<< "Ingrese la cantidad de numero del arreglo"<<endl;
    cin>> cantidad;

   
    for (int i = 0; i < cantidad; i++)
    {
        cout<< "Ingrese valor: "<<endl;
        cin>> arreglo[i];
    }
    
    cout << "El promedio del arreglo es: "<< promedio(arreglo,cantidad)<<endl;

   

    return 0;
}

float promedio (int arreglo[], int tamaño){
    int suma
    for (int j = 0; j < tamaño; j++)
    {
        suma += arreglo[j];
    }
    return suma/tamaño;
    
}