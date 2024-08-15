#include <iostream>

using namespace std;

int mcd(int, int);
int mcm(int, int);
int potencia(int, int);
void cuentaRegresiva(int);

int main()
{
    int a, b, c, d, e, f, g;

    cout << "Ingrese un numero" << endl;
    cin >> a;
    cout << "Ingrese otro numero" << endl;
    cin >> b;

    cout << mcd(a, b) << endl;

    cout << "Ingrese un numero" << endl;
    cin >> c;
    cout << "Ingrese otro numero" << endl;
    cin >> d;

    cout << mcm(c, d) << endl;

    cout << "Ingrese la base: " << endl;
    cin >> e;
    cout << "Ingrese el exponente" << endl;
    cin >> f;

    cout << potencia(e, f) << endl;

    cout << "Escriba el numero del cual quiere cuenta regresiva: "<<endl;
    cin>> g;

    cuentaRegresiva(g);

    return 0;
}

int mcd(int a, int b)
{

    if (b == 0)
    {
        return a;
    }
    else
    {
        return mcd(b, a % b);
    }
}

int mcm(int c, int d)
{

    if (c == 0 || d == 0)
    {
        return 0;
    }
    else
    {
        // llamado indirecto a la función
        return c * d / (mcd(c, d));
    }
}

int potencia(int base, int exp)
{

    int total = 1;

    if (exp == 0)
    {
        return 1;
    }
    else if (exp == 1)
    {
        return base;
    }
    else
    {
        return base*potencia(base, exp-1);
    }
}

void cuentaRegresiva(int g){

    if(g==0){
        cout<< " "<<endl;
    } 
        cout<< g<< " "<<endl;
        cuentaRegresiva(g-1);

}
