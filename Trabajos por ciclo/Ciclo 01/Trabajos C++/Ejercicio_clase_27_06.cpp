#include <iostream>

using namespace std;

//paso de parámetro por valor
void funcion1(int a);
// por dirección
void funcion2(int *a);
// por referencia
void funcion3(int &a);

int main(){
    
    
    int i=45;
    
    cout<<i<<endl; //45
    funcion1(i); //55
    cout<<i<<endl; //45
    funcion2(&i); //20
    cout<<i<<endl; //20
    funcion3(i); //15
    cout<<i<<endl; //15


    return 0;
}
void funcion1(int a){
    cout<<a+10<<endl;
}
void funcion2(int *a){
    *a=20;
    cout<<*a<<endl;
}
void funcion3(int &a){
    a=15;
    cout<<a<<endl;
}