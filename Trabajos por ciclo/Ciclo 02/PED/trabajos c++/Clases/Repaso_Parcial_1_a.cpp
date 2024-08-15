// Solicitar al usuario la selección de triángulo o rectángulo y basado en la decisión mostrará
// los resultados. Escribir función parametrizada con uso de referencia o parámetros que devuelva
// varios resultados.
#include <iostream>

using namespace std;

void area(float b, float h, float &areaT, float &areaR);

int main()
{

    float base = 0;
    float altura = 0;
    float areaTriangulo = 0;
    float areaRectangulo = 0;
    int guardarOpcion = 0;

    cout << "Que area desea calcular. 1-Triangulo, 2-Rectangulo" << endl;
    cin >> guardarOpcion;

    switch (guardarOpcion)
    {
    case 1:
        cout << "Ingrese la base: " << endl;
        cin >> base;
        cout << "Ingrese la altura:" << endl;
        cin >> altura;
        area(base, altura, areaTriangulo, areaRectangulo);
        cout << "El area del triangulo es: " << areaTriangulo;
        break;
    case 2:
        cout << "Ingrese la base: " << endl;
        cin >> base;
        cout << "Ingrese la altura:" << endl;
        cin >> altura;
        area(base, altura, areaTriangulo, areaRectangulo);
        cout << "El area del rectangulo es: " << areaRectangulo;
        break;

    default:
        cout<< "Opcion no valida."<<endl;
        break;
    }

    return 0;
}

void area(float b, float h, float &areaT, float &areaR)
{

    float areaTriangulo = (b * h) / 2;
    areaT = areaTriangulo;

    float areaRectangulo = (b * h);
    areaR = areaRectangulo;
}