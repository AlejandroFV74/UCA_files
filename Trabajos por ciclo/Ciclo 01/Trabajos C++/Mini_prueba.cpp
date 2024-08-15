// Crear función que muestre el tipo de triángulo según las 3 medidas ingresadas por
// el usuario, finalmente se deberá imprimir el tipo de triángulo.
#include <iostream>

using namespace std;

string tipoTriangulo(int a, int b, int c);

int main()
{

    int x, y, z;

    cout << "Ingrese el primer lado" << endl;
    cin >> x;
    cout << "Ingrese el segundo lado" << endl;
    cin >> y;
    cout << "Ingrese el tercer lado" << endl;
    cin >> z;

    cout << "El triángulo es: " << tipoTriangulo(x, y, z);

    return 0;
}

string tipoTriangulo(int a, int b, int c)
{
    if ((a == b and b == c) or (a == c and c == b))
    {
        return "equilatero";
    }
    else if (a == b or b == c or a == c)
    {
        return "isosceles";
    }
    else
    {
        return "escaleno";
    }
}