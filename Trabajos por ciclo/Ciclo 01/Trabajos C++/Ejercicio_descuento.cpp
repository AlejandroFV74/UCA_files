#include <iostream>
using namespace std;

//funciones
bool inicioSesion(string nombreUsuario, string contrasena);

int retiro (int montoRetiro);

//variables globales
int montoFinal, montoRetiro, saldoCuenta=1000;

int deposito (int montoDeposito);

//bool imprimirRecibo();

bool salir(string respuestaUsuario, string respuesta);


int main()
{
   //variables locales
    string nombreUsuario;
    string contrasena, respuesta;
    int montoRetiro, montoDeposito;
    int opcion;
    string respuestaUsuario;
    
    do{

    cout << "Ingrese su usuario" << endl;
    cin >> nombreUsuario;
    cout << "Ingrese su contraseña" << endl;
    cin >> contrasena;

    

    if (inicioSesion(nombreUsuario, contrasena))
    {
        cout << "Inicio de sesión exitoso." << endl;

        cout << "¿Qué desea hacer? 1-Retirar dinero, 2 Realizar depósito, 3 Salir."<<endl;
        cin>> opcion;

        switch (opcion){
            case 1:
            cout<< "Su selección fue: Retiro"<<endl;
            cout << "Ingrese la cantidad a retirar" << endl;
            cin>> montoRetiro;
            retiro (montoRetiro);

            break;

            case 2:
            cout<< "Su selección fue: Depósito"<<endl;
            cout << "Ingrese la cantidad a depositar" << endl;
            cin>> montoDeposito;
            deposito (montoDeposito);

            break;

            case 3:
            cout<< "¿Realmente quiere salir? si/no"<<endl;
            cin>> respuesta;

            break;

            default:
            cout<< "Opción inválida"<<endl;

            break;

        }
        
    }
    else
    {
        cout << "Credenciales inválidas. Inicio de sesión fallido." << endl;
    }
    } while (salir(respuestaUsuario, respuesta)!=true);

    return 0;
}

bool inicioSesion(string nombreUsuario, string contrasena)
{
    if (nombreUsuario == "pepe" && contrasena == "1234")
    {
    return true;
    } else {
    return false;
    }
}

int retiro (int montoRetiro)
{
    
    montoFinal= (saldoCuenta - montoRetiro);
   
    cout << "Su saldo actual es de: $" << montoFinal << endl;

    
return 0;

}

int deposito (int montoDeposito)
{
    
    montoFinal= (saldoCuenta + montoDeposito);
   
    cout << "Su saldo actual es de: $" << montoFinal << endl;

return 0;

}

bool salir(string respuestaUsuario, string respuesta)
{
if (respuestaUsuario==respuesta)
{
return true;

} else {
return false;
}

}