//Ejercicio 1: Crear una función que cambien el valor de dos variables entre ellas

//Ejercicio 2: Crear una función que devuelva varios valores a través del uso de referencia
//la función deverá realizar el cálculo del descuento de 20% aplicado al costo de un producto,
// tomando en cuenta la cantidad de producto y devolver el &descuento y la &cantidad a pagar. 
#include <iostream>

using namespace std;

int ref1, ref2, alm1, alm2;

void cambioVariable(int *a, int *b);

float calculadora (int, int, int &, int &, int &);

void calcularTiquet (float cant, float precio, float &descuento, float & totalPagar);

int main(){

    int var1, var2;

    cout<<"Ingrese el valor de la primer variable: "<<endl;
    cin>>var1;

    cout<<"Ingrese el valor de la segunda variable"<<endl;
    cin>>var2;

    cambioVariable(&var1 , &var2);

    cout<< "Variable 1: "<< var1<< endl;
    cout<< "Variable 2: "<< var2<< endl;


    int suma=0;
    int resta=0;
    int multiplicacion=0;

    calculadora(3,5, suma, resta, multiplicacion);

    cout<<"suma: "<<suma<<endl;
    cout<<"resta : "<<resta<<endl;


    float cant=0;
    float precio=0;
    float descuento=0;
    float totalPagar=0;

    cout<<"Ingrese la cantidad del producto: "<<endl;
    cin>>cant;
    cout<<"Ingrese el precio del producto: "<<endl;
    cin>>precio;

    calcularTiquet(cant, precio, descuento, totalPagar);

    cout<< "----------------------------"<<endl;
    cout<< "           tiquet           "<<endl;
    cout<< " Cantidad producto: "<<cant<<endl;
    cout<< " Precio unitario: $ "<<precio<<endl;
    cout<< " Total descuento: $ "<<descuento<<endl;
    cout<< " Total a pagar: $ "<<totalPagar<<endl;
    cout<< "----------------------------"<<endl;



    return 0;
}

void cambioVariable(int *a, int *b){

    int temp= *a;
    *a=*b;
    *b= temp;
}

float calculadora (int n, int m, int &suma, int &resta, int &multiplicacion){

    suma= n+m;
    resta= n-m;
    multiplicacion = n*m;

}

void calcularTiquet (float cant, float precio, float &descuento, float & totalPagar){
    descuento=(cant*precio)*0.20;
    totalPagar=(cant*precio)-descuento;
}