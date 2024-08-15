#include <iostream>

using namespace std;

void calcularPrecioTotal(int tipo, int cantidadNoches, double precioNoche, double total, double &totalImpuesto);

int main()
{

    int tipo, cantidadNoches, respuesta;
    double precioNoche = 0, total, totalIpuesto;
    

    do
    {

        cout << "Bienvenido al hotel" << endl;
        cout << "Ingrese la habitación en la que se hospedará: " << endl;
        cout << "1-basica: $50 la noche." << endl;
        cout << "2-normal: $100 la noche." << endl;
        cout << "3-normal: $150 la noche." << endl;
        cin >> tipo;

        cout << "Ingrese la cantidad de noches a quedarse: " << endl;
        cin >> cantidadNoches;

        calcularPrecioTotal(tipo, cantidadNoches, precioNoche, total, totalIpuesto);

        cout<<"Desea salir del sistema: 1.si - 2.no"<<endl;
        cin>>respuesta;

    
    } while (respuesta==2);

        cout<< "Saliendo del sistema..."<<endl;
    
    
        return 0;
    
}
    void calcularPrecioTotal(int tipo, int cantidadNoches, double precioNoche, double total, double &totalImpuesto)
    {

        switch (tipo)
        {
        case 1:
            precioNoche = 50.00;
            break;
        case 2:
            precioNoche = 100.00;
            break;
        case 3:
            precioNoche = 150.00;
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
        }

        total = precioNoche * cantidadNoches;
        totalImpuesto = (total * 0.18) + total;

        cout << "Precio por noche: $" << precioNoche << endl;
        cout << "Precio total de estadia: $" << total << endl;
        cout << "Impuestos a pagar: $ " << totalImpuesto - total << endl;
        cout << "Total con impuesto: $" << totalImpuesto << endl;
    }
