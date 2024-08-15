/*Crear un programa que almacene N mascotas, cada registro de mascota deberá
contener: nombre, edad y un indicador de si ha sido o no vacunada. El programa
deberá de ser capaz de mostrar todos los registros ingresados y además ha medida
sea necesario se deberá de poder editar los registros ya existentes para indicar que
mascotas ya han sido vacunadas. Considere usar punteros siempre que lo crea
conveniente y obligatoriamente en la función que se encarga de modificar el estado
de vacunado de una mascota.*/

#include <iostream>

using namespace std;

struct Mascota{
    string nombre;
    int edad;
    bool vacunado;
}mascota;

void modificarEstado(bool nuevoEstado, struct Mascota &m);



int main(){

    int numMascotas, posMascota;
    string respuesta;

    cout<< "Ingrese el número de mascotas a almacenar: "<<endl;
    cin>>numMascotas;

    Mascota mascota [numMascotas];

    for (int i = 0; i < numMascotas; i++)
    {
        cout<<"Ingrese el nombre de la mascota: "<<endl;
        cin>> mascota[i].nombre;
        cout<< "Ingrese la edad de la mascota: "<<endl;
        cin>> mascota[i].edad;
        cout<< "Está vacunado: (s/n)"<<endl;
        cin>>respuesta;
        if(respuesta == "s"|| respuesta== "S"){
            mascota[i].vacunado=true;
        } else {
            mascota[i].vacunado=false;
        }
    }

    cout<<"Seleccione la mascota a modificar"<<endl;
    cin>> posMascota;
    



    return 0;
}

void modificarEstado(bool nuevoEstado, struct Mascota &m){
    if(nuevoEstado==false){
        mascota->vacunado=false;
    } else{
        mascota->vacunado=true;
    }
}