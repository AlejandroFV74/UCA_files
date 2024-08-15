#include <iostream>

using namespace std;

void informacionUsuario();
void calculoAntiguedad(struct album[]);
void imprimirInfo(struct album[]);
void buscarCantante(struct album[], string nomCantante);

struct Disquera
{
    string nombre;
    string pais;
    int aniofundacion;
};

struct AlbumMusica
{
    string nombreCantante;
    string tituloCancion;
    int numPista;
    float duracion;
    int anioPublicacion;
    int antiguedad;
    //variable para anidar
    struct Disquera disquera;

} album[3];



int main()
{

informacionUsuario();
calculoAntiguedad(album[]);
imprimirInfo
    
    
    return 0;
}

void informacionUsuario()
{
   

    for (int i = 0; i < 3; i++)
    {
      
    cout << "Ingrese el nombre del cantante: " << endl;
    cin >> album[i].nombreCantante;
    cout << "Ingrese el título de la canción: " << endl;
    cin >> album[i].tituloCancion;
    cout << "Ingrese el número de pista: " << endl;
    cin >> album[i].numPista;
    cout << "Ingrese la duración de la canción: " << endl;
    cin >> album[i].duracion;
    cout << "Ingrese el año de publicación: " << endl;
    cin >> album[i].anioPublicacion;
  
    cout << "Ingrese el nombre de la disquera: " << endl;
    cin>>album[i].disquera.nombre;
    cout << "Ingrese el país de la disquera: " << endl;
    cin>>album[i].disquera.pais;
    cout << "Ingrese el año de fundación de la disquera: " << endl;
    cin>>album[i].disquera.aniofundacion;

    }

    
}

void calculoAntiguedad(struct album[]){

    for (int i = 0; i <3 ; i++)
    {
    album[i].antiguedad=2023-album[i].anioPublicacion;
    }
    

}

void imprimirInfo(struct album[]){
    for (int i = 0; i < 3; i++)
    {
        cout<<"Nombre del cantante: "<<album[i].nombreCantante<<endl;
        cout<<"Titulo de la cancion "<<album[i].tituloCancion<<endl;
        cout<<"Numero de pista: "<<album[i].numPista<<endl;
        cout<<"Titulo de la cancion: "<<album[i].tituloCancion<<endl;
        cout<<"Anio de publicacion: "<<album[i].anioPublicacion<<endl;
        cout<<"Antiguedad del album: "<<album[i].antiguedad<<endl;
        cout<<"Nombre de la disquera: "<<album[i].disquera.nombre<<endl;
        cout<<"Nombre del pais de la disquera: "<<album[i].disquera.pais<<endl;
        cout<<"Anio de fundacion de la disquera: "<<album[i].disquera.aniofundacion<<endl;
    }
    
}

void buscarCantante(struct album[], string nomCantante){
    if (nomCantante==album->nombreCantante){
        cout<<album->nombreCantante<<endl;
        cout<<album->tituloCancion<<endl;
        cout<<album->numPista<<endl;
        cout<<album->tituloCancion<<endl;
        cout<<album->anioPublicacion<<endl;
        cout<<album->antiguedad<<endl;
        cout<<album->disquera.nombre<<endl;
        cout<<album->disquera.pais<<endl;
    }
}