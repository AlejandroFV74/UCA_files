//Ejercicio: Calcular total a pagar con función, plantas en un vivero.
#include <iostream>

using namespace std;

float totalPagar(int cantidad, int tipo);
int total=0;

int main(){

    int tipo=0, cantidad=0;

cout<< "Ingrese el tipo de planta: 1-Ornamental $15.00, 2-Medicinal $25.00"<<endl;
cin>> tipo;

cout<< "Ingrese la cantidad de plantas que desea: "<<endl;
cin>> cantidad;

cout<< "El total es de: $ "<< totalPagar(cantidad, tipo);
   

    return 0;
}

float totalPagar(int cantidad, int tipo){
if (tipo == 1){
    total= cantidad * 15.00;
    return total;
    
} else{
    total= cantidad * 25.00;
    return total;
}
}