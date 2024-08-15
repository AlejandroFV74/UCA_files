
#include <iostream>

using namespace std;


void menu(int opcion);

float comprar(int cantidad, int tipo, int producto);
int total;


int main()
{
    int opcion;
    int producto, cantidad;
    int totalDescuento;
    string respuesta;

    
    do
    {
     
     
    cout << "Bienvenido"<<endl;
    cout << " ¿A que departamento desea acceder?" << endl;
    cout << "1-Departamento de construcción. " << endl;
    cout << "2-Departamento de electrodomésticos. " << endl;
    cout << "3-Departamento de Ingeniería. " << endl;
    cin >> opcion;

    
    menu(opcion);

    cout <<"De los tres productos, ¿Cuál desea?, seleccione 1, 2 o 3."<<endl;
    cin>>producto;
    cout <<"Selecione la cantidad de artículos deseados"<<endl;
    cin>>cantidad;

    cout<<"Su total es de: $"<<comprar(cantidad,opcion,producto)<<endl;

    if(comprar(cantidad,opcion,producto)>=100.00){
        totalDescuento= comprar(cantidad,opcion,producto)-(comprar(cantidad,opcion,producto)*0.10);
        cout<< "A su compra se le aplicará un descuento del 10 %"<<endl;
        cout<< "Su total a pagar sería: $ "<<totalDescuento<<endl;
    }
    
    cout<< "¿Desea salir del programa?, si/no "<<endl;
    cin>>respuesta;
    
    }while(respuesta!="si");
    

    return 0;

    
}
//Funcion 1: mostrar al usuario el menu y los articulos de cada depto con sus precios
void menu(int opcion){
    switch (opcion)
    {
    case 1:
        cout << "Depto construcción elegido" << endl;
        cout << "Tipos de herramientas disponibles: " << endl;
        cout << "1- Hierro, 2- láminas, 3-madera" << endl;
        break;

    case 2:
        cout << "Depto electrodomésticos elegido" << endl;
        cout << "Tipos de herramientas disponibles: " << endl;
        cout << "1- Licuadoras $45.99" << endl;
        cout << "2- Procesador de alimento $25.00" << endl;
        cout << "3- Horno $35.99" << endl;

        break;

    case 3:
        cout << "Depto tecnología elegido" << endl;
        cout << "Tipos de herramientas disponibles: " << endl;
        cout << "1- Audífonos $14.95" << endl;
        cout << "2- Cables de poder $9.99" << endl;
        cout << "3- Mouse $31.99" << endl;

        break;
    
    case 4:
        break;
    
    
    default:
        cout << "Opción no válida" << endl;
        break;
    }


}

//funcion 2: calcular el total del producto elegido por el usuario
float comprar(int cantidad, int tipo, int producto){
    if(tipo==1 and producto==1){
        total= cantidad * 15;
        return total;
    } else if(tipo==1 and producto==2){
        total= cantidad * 20;
        return total;
    } else if(tipo==1 and producto==3){
        total= cantidad * 30;
        return total;
    } else if(tipo==2 and producto==1){
        total= cantidad * 45.99;
        return total;
    }else if(tipo==2 and producto==2){
        total= cantidad * 25.00;
        return total;
    }else if(tipo==2 and producto==3){
        total= cantidad * 35.99;
        return total;
    }else if(tipo==3 and producto==1){
        total= cantidad * 14.95;
        return total;
    } else if(tipo==3 and producto==2){
        total= cantidad * 9.99;
        return total;
    } else if(tipo==3 and producto==3){
        total= cantidad * 31.99;
        return total;
    } else {
        return 0;
    }
}