#include <iostream>
#include <vector>
#include <memory> // para std::unique_ptr
#include <iomanip> // para std::setprecision

// Clase base Producto
class Producto {
public:
    // Constructor que inicia el nombre y precio para el producto
    Producto(const std::string& nombre, double precio) : nombre(nombre), precio(precio) {}

    // Método para precio
    virtual double obtenerPrecio() const = 0;

    // Método para nombre del producto
    virtual std::string obtenerNombre() const {
        return nombre;
    }

    // Virtual destructor
    virtual ~Producto() {}

protected:
    std::string nombre;
    double precio;
};

// Clase para Café
class Cafe : public Producto {
public:
    Cafe() : Producto("Café", 2.50) {}

    double obtenerPrecio() const override {
        return precio;
    }
};

// Clase para Té
class Te : public Producto {
public:
    Te() : Producto("Té", 1.80) {}

    double obtenerPrecio() const override {
        return precio;
    }
};

// Clase para Pastel
class Pastel : public Producto {
public:
    Pastel() : Producto("Pastel", 3.20) {}

    double obtenerPrecio() const override {
        return precio;
    }
};

// Clase para Muffin
class Muffin : public Producto {
public:
    Muffin() : Producto("Muffin", 2.00) {}

    double obtenerPrecio() const override {
        return precio;
    }
};

int main() {
    // Vector de punteros únicos a Producto
    std::vector<std::unique_ptr<Producto>> productos;

    // Se agrega diferentes productos al vector
    productos.push_back(std::make_unique<Cafe>());
    productos.push_back(std::make_unique<Te>());
    productos.push_back(std::make_unique<Pastel>());
    productos.push_back(std::make_unique<Muffin>());

    // Bienvenida
    std::cout << "Bienvenido a la Cafetería Gourmet!\n";
    std::cout << "Aquí está nuestro menú del día:\n\n";

    // Aquí se muestran los productos y se calcula el precio total
    double precioTotal = 0.0;
    std::cout << std::fixed << std::setprecision(2); // Para mostrar precios con dos decimales

    for (const auto& producto : productos) {
        std::cout << "- " << producto->obtenerNombre() << ": Q" << producto->obtenerPrecio() << '\n';
        precioTotal += producto->obtenerPrecio();
    }

    std::cout << "\nEl precio total de todos los productos es: Q" << precioTotal << '\n';

    // Despedida
    std::cout << "\nGracias por visitarnos. ¡Que tenga buen día!\n";

    return 0;
}
