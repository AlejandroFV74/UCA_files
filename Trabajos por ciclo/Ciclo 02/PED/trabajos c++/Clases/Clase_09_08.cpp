#include <iostream>

using namespace std;

int main()
{

    int numMes;

    cout << "Introduzca el numero del mes" << endl;
    cin >> numMes;

    cout << "Su numero es: " << numMes<<endl;

    if (numMes == 1 || numMes == 3 || numMes == 5 || numMes == 7 || numMes == 8 || numMes == 10 || numMes == 12)
    {
        cout << "El mes seleccionado tiene 31 dias" << endl;
    }
    else if (numMes == 4 || numMes == 6 || numMes == 9 || numMes == 11)
    {
        cout << "El mes seleccionado tiene 30 dias" << endl;
    }
    else if (numMes == 2)
    {
        cout << "El mes seleccionado tiene 28/29 dias" << endl;
    }
    else
    {
        cout<< "El numero es invalido"<<endl;
    }

    return 0;
}