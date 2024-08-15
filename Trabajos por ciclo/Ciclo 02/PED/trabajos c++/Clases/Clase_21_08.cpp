// Tema: Punteros

#include <iostream>

using namespace std;

int arregloEnteros[4]={0,1,2,3};

int *ptr3;

void direction(int arregloEnteros[4], int valor);

int main()
{

    int a = 15;
    int *ptr; // puntero no se debe inicializar
    int *ptr2;

    ptr = &a;
    ptr2 = ptr;
    

    /*cout << ptr;
    cout << *ptr; // con asterisco imprime el valor de la variabale
    cout << ptr2;
    */

    // ejercicio 1

    /*int n = 33;
    int &r = n;

    cout << "&n =" << &n << ", &r=" << &r << endl; */

    // ejercicio 2

   /* int n = 35;
    int *p = &n;
    int &r = *p;
    cout << "r= " << r << endl; */

    // ejercicio 3

    int n = 35;
    int *p = &n;
    cout << "*p=" << *p << endl;

    //ejercicio 4

    if (&ptr == &ptr2){
        cout<< "Son iguales"<<endl;
    } else {
        cout<< "Son diferentes"<<endl; //cada uno apunta a lo mismo pero con diferente dirección
    }


    int vector [5]= {4,5,8,1,9};


    cout<< vector;
    cout<< *(vector + 1); //sintaxis usando vectores

    // int *ptr =vector; //asignación

    for (int i = 0; i < 5; i++)
    {
        cout<<*(vector+i)<<" "<<ptr++<<endl;
    }


    //Ejercicio: Escribir una función que utilice punteros para buscar la dirección de un entero dado en un arrey dado
    // la función devuelve su dirección, en caso contrario, devuelve Null.

    int valor=0;

    cout<<"Ingrese el entero que desea buscar: "<<endl;
    cin>> valor;

    cout<< direction(arregloEnteros[4], valor)<<endl;


    
    

    return 0;
}

void direction(int arregloEnteros[4], int valor){

    for (int i = 0; i < 4; i++)
    {
        if (valor== arregloEnteros[i])
        {
            ptr3=&valor;
            cout<< ptr3++<<endl;
        } 
        
    } if (ptr3==nullptr){
        cout<< "Null";
    }
    

    


}

#include <iostream>

using namespace std;

int arregloEnteros[4] = {0, 1, 2, 3};

int *ptr3;

void diretion(int arregloEnteros[], int valor);

int main()
{

    // Ejercicio: Escribir una función que utilice punteros para buscar la dirección de un entero dado en un arrey, dado
    //  la función devuelve su dirección, en caso contrario, devuelve Null.

    int valor = 0;

    cout << "Ingrese el entero que desea buscar: " << endl;
    cin >> valor;

    diretion(arregloEnteros, valor);

    return 0;
}

void diretion(int arregloEnteros[], int valor)
{

    ptr3 = nullptr;

    for (int i = 0; i < 4; i++)
    {
        if (valor == arregloEnteros[i])
        {
            ptr3 = &arregloEnteros[i];
            cout << i << " - "<< ptr3 << endl;
            break;
        }
    }

    if (ptr3 == nullptr)
    {
        cout << "Null";
    }
}