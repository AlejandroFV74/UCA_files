//Crear arreglo unidimensional que almacene 5 edades, solicitar datos al usuario.
//Una función que calcule la cantidad de >=18 y retorne la cantidad
#include <iostream>

using namespace std;

int cantidadMayor18 (int arregloEdad[5]);
int totales;

int main(){

    int arregloEdad[5];
    
    for (int i = 0; i < 5; i++)
    {
        cout<< "Ingrese una edad: "<<endl;
        cin>> arregloEdad;
    }
    cantidadMayor18[5];


    return 0;
}

int cantidadMayor18 (int arregloEdad[5]){

    for (int i = 0; i < 5; i++)
    {
        if (arregloEdad[5]>=18){
            totales++;
            
        }
        return totales;
    }
    
    
}