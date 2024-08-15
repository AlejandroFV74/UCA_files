#include <iostream>

using namespace std;

//Función 1:
float almacenarTem(float arregloTem[]);

//Función 2:


int main(){

    float arregloTem[10];

    for (int i = 0; i < 10; i++)
    {
        cout<<"Ingrese numero para el arreglo"<<endl;
        cin>> arregloTem[i];
    }

    cout<<"Cantidades mayores a 40: "<<endl;
    cout<<almacenarTem(arregloTem)<<endl;
    
    



    


    


    return 0;
}

float almacenarTem(float arregloTem[]){
    float cantidad=0;
    for (int i = 0; i < 10; i++)
    {
        if(arregloTem[i]>40){
            cantidad += 1;
        }
        return cantidad;
        
    }
    return 0;

}