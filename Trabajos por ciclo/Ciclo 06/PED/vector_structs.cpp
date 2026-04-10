#include <iostream>
#include <vector>
#include <string>

struct Producto {
    int id;
    std::string nombre;
    double precio;
};

// Utilidad para imprimir el vector
void imprimir(const std::vector<Producto> v, const std::string titulo) {
    std::cout << "\n" << titulo << " (" << v.size() << "):\n";
    for (const auto p : v) {
        std::cout << "  id=" << p.id
                  << ", nombre=" << p.nombre
                  << ", precio=" << p.precio << '\n';
    }
}

int main() {
    // 1) Inicialización
    std::vector<Producto> inventario = {
        {1, "Pan",   0.50},
        {2, "Leche", 4.10},
        {3, "Huevos",2.40}
    };

    // Agregar elementos
    inventario.push_back({4, "Café", 3.20});        // push_back con lista
    inventario.emplace_back(5, "Azúcar", 0.95);     // emplace_back construye in-place

    imprimir(inventario, "Después de inicializar y agregar");

    // 2) Acceso y modificación
    // Por índice (sin verificación)
    inventario[1].nombre = "Leche descremada"; // Cambiamos el nombre de la leche

    imprimir(inventario, "Después de accesos/modificaciones");

    // 3) Eliminación
    // a) Por índice (ejemplo: eliminar el segundo elemento, índice 1)
    if (inventario.size() > 1) {
        inventario.erase(inventario.begin() + 1);
    }
    imprimir(inventario, "Después de borrar por índice (índice 1)");
    
    // c) Del final (pop_back) si no está vacío
    if (!inventario.empty()) {
        inventario.pop_back();
    }
    imprimir(inventario, "Después de pop_back");

    // d) Limpiar todo (mantiene capacidad)
    inventario.clear();
    imprimir(inventario, "Después de clear()");
    
    return 0;
}