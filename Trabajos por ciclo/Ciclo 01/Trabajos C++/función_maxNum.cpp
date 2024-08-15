#include <iostream>

using namespace std;

int numMax(int a, int b);
int mayor;

int main()
{
    int num1, num2;

    cout << "ingrese un número" << endl;
    cin >> num1;
    cout << "ingrese otro número" << endl;
    cin >> num2;

    cout << "el número mayor es: " << numMax(num1, num2);

    return 0;
}

int numMax(int a, int b)
{
    if (a > b)
    {
        mayor = a;
        return a;
    }
    else if (b > a)
    {
        mayor = b;
        return b;
    }
    else
    {
        return 0;
    }
}