#include <iostream>

using namespace std;

void Imprimir (struct Alumno a[]);
int NumeroEsctructuras ();

struct Alumno
{
    string nombre;
    int anioNac;
    float notas[3];

struct Residencias residencias;

}alumno[4];

struct Residencias {
    string departamento;
    string municipio;
    int numeroCasa;
}


int main(){

    

    for (int i = 0; i < 5; i++)
    {
        cout<<"Ingrese nombre"<<endl;
        cin>> alumno[i].nombre;
    }
    
    


    return 0;
}

void Imprimir (struct Alumno a[]){
    for (int i = 0; i < NumeroEstructuras; i++)
    {
        cout<<"Nombre: "<<a[i].nombre<<endl;
        cout<<"Año nacimiento: "<<a[i].anioNac<<endl;
        cout<<"Edad: "<<a[i].
    }
    
}

int NumeroEstructuras(){


}