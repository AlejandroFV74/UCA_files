#include <iostream>
#include <unordered_map> //Necesario para la memorización

using namespace std;

unordered_map<int, int> memo;

int Fibonacci(int n);

int main()
{

    int a;

    cout << "Ingrese un numero: " << endl;
    cin >> a;

    cout << "Su Fibonacci es: " << Fibonacci(a) << endl;

    return 0;
}

int Fibonacci(int n)
{

    if (memo.find(n) != memo.end())
    {
        return memo[n]; // Si ya calculamos este valor, devolvemos el resultado almacenado
    }

    if (n <= 1)
    {
        return n;
    }
    int fib = Fibonacci(n - 1) + Fibonacci(n - 2);
    memo[n] = fib; // Almacenamos el resultado antes de devolverlo
    return fib;
}
