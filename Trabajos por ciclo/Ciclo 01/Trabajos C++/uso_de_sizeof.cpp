#include <iostream>

using namespace std;

int main (){

int a;

int MiPrimerArreglo[5];

int DimensionArreglo= sizeof(MiPrimerArreglo)/sizeof (int);
cout<<"The array dimension is: "<<DimensionArreglo<<endl;

for (int n = 0; n <DimensionArreglo; n++)
{
    cout<<"Ingrese un dato: ";
    cin>> a;
    MiPrimerArreglo[n]=a;
}


for (int i = 0; i < DimensionArreglo; i++)
{
    if ((MiPrimerArreglo[i] % 2) == 0)
    {
        cout<<"number: "<< MiPrimerArreglo[i]<<" position: "<<i<<endl;
    }
    
}


return 0;

}