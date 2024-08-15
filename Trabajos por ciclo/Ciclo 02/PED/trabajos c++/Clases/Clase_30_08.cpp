

// Ejercicio: Crear dos arreglos que almacenan nombres de lugares turísticos y su país
// haciendo uso de reserva de memoria

#include <iostream>

using namespace std;

int main()
{
    int numLugares;
    string *lugar, *pais; //apuntar a NULL para evitar problemas

    cout << "Cuantos lugares se registraran " << endl;
    cin >> numLugares;

    lugar = new string[numLugares];
    pais = new string[numLugares];

    for (int i = 0; i < numLugares; i++)
    {
        cout << "Ingrese el nombre del lugar: " << endl;
        cin >> lugar[i];
        cout << "Ingrese el nombre del pais: " << endl;
        cin >> pais[i];
    }

    

    if (lugar == NULL || pais == NULL)
    {
        cout << "Error de asignacion de memoria" << endl;
    }
    else
    {
        cout << "Direccion de memoria " << endl;
        cout << lugar << endl;
        cout << pais << endl;
    }

    delete[] lugar; //Como no son variables simples, llevan corchetes
    delete[] pais;
    lugar=nullptr; //Recomendado
    pais=nullptr;

    return 0;
}

//Variante con Matriz

#include <iostream>

using namespace std;

int main(){

int columnas=2;
int Tamanio=0;

string **destino;
string lugar, pais;

cout<<"Ingrese el numero de lugares a registrar: "<<endl;
cin>> Tamanio;

destino= new string *[Tamanio];

for (int i = 0; i < Tamanio; i++)
{
    destino[i]=new string[columnas];
    cout<<"pais: ";
    getline(cin, pais);
    cout<<"lugar: ";
    getline(cin, lugar);
    destino[i][0]=pais;
    destino[i][1]=lugar;

}

//Liberacion

for (int i = 0; i < Tamanio; i++)
{
    delete[] destino[i];
} delete[] destino;
destino=nullptr;

return 0;
}
