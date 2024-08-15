#include <iostream>
#include <fstream>

using namespace std;

void CrearFichero();
void LeerFichero();
string nombre;


int main(){
    
CrearFichero();

    return 0;
}
void CrearFichero(){

    ofstream fichero;
    fichero.open("Prueba.txt", ios::out | ios::app);
    fichero<<"Hola";
    cout<<"Ingrese un nombre";
    cin>>nombre;

    

    fichero.close();
}

void LeerFichero(){

    string texto;

    ifstream fichero;
    fichero.open("Prueba.txt", ios::in);

    while(getline((fichero, texto))){
        cout<<texto;
    }

    fichero.close();
}