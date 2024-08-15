//crear función que imprima los números pares desde el 2 hasta el seleccionado por el usuario
#include <iostream>

using namespace std;

void imprimirPares(int n);

int main(){
    int x;
    cout<< "Ingrese el número límite :"<<endl;
    cin>>x;
    
    imprimirPares(x);

    return 0;
}

void imprimirPares(int n){
    for (int i = 2; i <= n; i++)
    {
        if ((i>1) and (i % 2 ==0))
        cout<< i<<endl;
    }
    
}