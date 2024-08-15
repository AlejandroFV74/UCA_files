/* Ejercicio: Realizar una función que permitada almacenar la información de tres productos usando punteros*/
#include <iostream>

using namespace std;

struct Producto{
    string nombre;
    float precio;
    string categoria[2];
} producto[3],*ptr;

void almacenarDatos();
void imprimir();

int main(){
    struct Producto *ptr;

    ptr= &producto[3];

    almacenarDatos();
    imprimir();
    

    return 0;
}

void almacenarDatos(){
    for (int i = 0; i < 3; i++)
    {
      
    cout<< "Ingrese el nombre del producto: "<<endl;
    cin>>ptr[i].nombre;

    cout<< "Ingrese el precio del producto: "<<endl;
    cin>>ptr[i].precio;

    for (int j = 0; j < 2; j++)
    {
    cout<< "Ingrese la categoría del producto: "<<endl;
    cin>> ptr[i].categoria[j];
    }

    }

}

void imprimir(){
    for (int a = 0; a <= 3; a++)
    {
        cout<< ptr[a].nombre<<endl;
        cout<< ptr[a].precio<<endl;
        for (int b = 0; b < 2; b++)
        {
            cout<< ptr[a].categoria[b]<<endl;
        }
        cout<< " "<<endl;
    }
}

/* Ejercicio: Realizar una función que permitada almacenar la información de tres productos usando punteros*/
#include <iostream>
#include <ctime> // Necesario para time
#include <cstdlib> // Necesario para srand y rand
#include <windows.h> // Necesario para Sleep en Windows

using namespace std;

struct temperatura{
    float alta;
    float baja;
}temp;

void leerTemp(float &actual);
void registroTemp(struct temperatura &t);

int main(){

    //Inicializando la estructura
    temp.alta=0;
    temp.baja=100;
    while(true){
        registroTemp(temp);
        cout<<"Temperaturas: "<<temp.baja<< " - "<<temp.alta<< "\n";
        Sleep(2000);
    }

    return 0;
}

void leerTemp(float &actual){
    int t= time(nullptr);
    srand(t);
    cout<< "Tiempo: "<<t;
    actual= rand() % (48 + 1);
}

void registroTemp(struct temperatura &t){
    float actual=0;
    leerTemp(actual);
    cout<< "Lectura actual: "<<actual<< "\n";
    if (actual>t.alta){
        t.alta=actual;
    }
    if(actual<t.baja){
        t.baja=actual;
    }

}
