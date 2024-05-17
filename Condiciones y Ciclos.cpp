#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Producto {
    string nombre;
    double precio;
    int cantidad;
};

void mostrarMenu() {
    cout << "Menu de la Cafeteria:\n";
    cout << "1. Cafe ($2.50)\n";
    cout << "2. Te ($1.80)\n";
    cout << "3. Pastel ($3.20)\n";
    cout << "4. Muffin ($2.00)\n";
    cout << "5. Ver carrito\n";
    cout << "6. Finalizar pedido\n";
    cout << "7. Realizar nueva orden\n";
    cout << "Seleccione una opcion: ";
}

void mostrarCarrito(const vector<Producto>& carrito) {
    double total = 0;
    cout << "\nCarrito de compras:\n";
    for (const auto& producto : carrito) {
        cout << producto.nombre << " - Cantidad: " << producto.cantidad << " - Precio: $" << fixed << setprecision(2) << producto.precio * producto.cantidad << endl;
        total += producto.precio * producto.cantidad;
    }
    cout << "Total a pagar: $" << fixed << setprecision(2) << total << "\n\n";
}

int main() {
    vector<Producto> menu = {
        {"Cafe", 2.50, 0},
        {"Te", 1.80, 0},
        {"Pastel", 3.20, 0},
        {"Muffin", 2.00, 0}
    };

    vector<Producto> carrito;
    int opcion;
    bool finalizar = false;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
            case 2:
            case 3:
            case 4: {
                int cantidad;
                cout << "Ingrese la cantidad de " << menu[opcion - 1].nombre << ": ";
                cin >> cantidad;
                bool encontrado = false;

                for (auto& producto : carrito) {
                    if (producto.nombre == menu[opcion - 1].nombre) {
                        producto.cantidad += cantidad;
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    Producto nuevoProducto = menu[opcion - 1];
                    nuevoProducto.cantidad = cantidad;
                    carrito.push_back(nuevoProducto);
                }

                cout << "Producto agregado al carrito!\n\n";
                break;
            }
            case 5:
                mostrarCarrito(carrito);
                break;
            case 6:
                mostrarCarrito(carrito);
                cout << "¿Desea el pedido para (1) comer en la cafetería o (2) llevar a casa?: ";
                int tipoPedido;
                cin >> tipoPedido;
                if (tipoPedido == 1) {
                    cout << "Pedido para comer en la cafetería. Gracias por su compra!\n";
                } else if (tipoPedido == 2) {
                    cout << "Pedido para llevar a casa. Gracias por su compra!\n";
                } else {
                    cout << "Opcion no valida.\n";
                }
                finalizar = true;
                break;
            case 7:
                carrito.clear();
                cout << "Nueva orden iniciada.\n";
                break;
            default:
                cout << "Opcion no valida, por favor intente de nuevo.\n";
                break;
        }
    } while (!finalizar);

    return 0;
}