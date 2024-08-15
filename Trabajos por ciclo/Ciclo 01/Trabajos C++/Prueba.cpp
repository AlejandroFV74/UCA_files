#include <iostream>

using namespace std;

int main (){

int arreglo[6];
int mayor=0, menor=0;

for (int i=1; i<6; i++){
    cout<< "Ingrese un número: "<<endl;
    cin>>arreglo[i];
}

for (int i = 0; i < 6; i++)
{
    if(arreglo[i]>mayor){
    arreglo[i]=mayor;
    } 
    else if (arreglo[i]<menor){
    arreglo[i]=menor;
}
}
cout<< "mayor: "<<mayor<<endl;
cout<< "menor: "<<menor<<endl;

return 0;

}