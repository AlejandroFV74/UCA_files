#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

struct BolsaValores {
    string empresa;
    float precioCompra;
    float precioVenta;
};

void generarValores(BolsaValores &bolsa);
void mostrarInfo(const BolsaValores &bolsa);

int main() {
    
    BolsaValores bolsa;

    while (true) {
        generarValores(bolsa);
        mostrarInfo(bolsa);
        Sleep(2000);
    }

    return 0;
}

void generarValores(BolsaValores &bolsa) {
    int t = time(nullptr);
    srand(t);

    // Generar valores aleatorios
    bolsa.empresa = "Empresa X";
    bolsa.precioCompra = (rand() % 100);
    bolsa.precioVenta = bolsa.precioCompra + (rand() % 10);
}

void mostrarInfo(const BolsaValores &bolsa) {
    cout << "Empresa: " << bolsa.empresa << "\n";
    cout << "Precio de Compra: " << bolsa.precioCompra << "\n";
    cout << "Precio de Venta: " << bolsa.precioVenta << "\n";
    cout << "-------------------\n";
}
