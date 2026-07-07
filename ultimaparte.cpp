#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Librería necesaria para formatear los decimales (ej. $1.50)

using namespace std;

// Estructura que infiero que tenías creada arriba de tu código
struct Producto {
    string nombre;
    double precio;
};

int main() {
    // 1. Inicializar la lista de productos y precios según tu consola
    vector<Producto> productos = {
        {"Cafe con Leche", 1.50},
        {"Medialuna", 0.80},
        {"Sandwich de Jamon y Queso", 3.00},
        {"Ensalada Mixta", 3.50},
        {"Gaseosa 500ml", 1.80},
        {"Jugo Natural", 2.20},
        {"Porcion de Torta", 2.50}
    };

    string Nombredecliente;
    string carnetEstudiante;

    // 2. Solicitar datos del cliente
    cout << "Ingrese el nombre del cliente: ";
    // cin.ignore(); // Quita las barras '//' de esta línea si antes de pedir el nombre hubo algún 'cin >>'
    getline(cin, Nombredecliente);

    cout << "Ingrese el carnet del estudiante: ";
    cin >> carnetEstudiante;
    cout << endl;

    // 3. Vectores de tu código original
    vector<int> cantidadseleccion(7, 0);
    vector<double> precioproducto(7);
    vector<string> comidaproducto(7);

    cout << "Seleccione las cantidades para los siguientes productos:\n";
    
    // 4. Llenar vectores y pedir cantidades
    for (int i = 0; i < 7; i++) {
        comidaproducto[i] = productos[i].nombre;
        precioproducto[i] = productos[i].precio;

        // Se imprime el menú dinámicamente con sus precios
        cout << i + 1 << ". " << comidaproducto[i] << " ($" << fixed << setprecision(2) << precioproducto[i] << "): ";
        cin >> cantidadseleccion[i];
    }

    double descuento = 0.0;
    cout << "\nIngrese el porcentaje de descuento (0 a 100): ";
    cin >> descuento;

    // 5. VALIDACIÓN: ¿Por qué no se generaba la factura?
    // Aquí validamos que el descuento sea real (entre 0 y 100)
    if (descuento < 0 || descuento > 100) {
        cout << "\nNo se pudo generar la factura. Porcentaje de descuento invalido.\n";
    } else {
        // 6. Calcular el subtotal de la compra
        double Totalcompra = 0.0;
        for (int i = 0; i < 7; i++) {
            Totalcompra += cantidadseleccion[i] * precioproducto[i];
        }

        // Si el cliente puso '0' en todo, no hay factura que generar
        if (Totalcompra == 0.0) {
            cout << "\nNo se pudo generar la factura. No selecciono ningun producto.\n";
        } else {
            // 7. Aplicar la matemática del descuento e Imprimir
            double montoDescuento = Totalcompra * (descuento / 100.0);
            double totalFinal = Totalcompra - montoDescuento;

            cout << "\n========================================\n";
            cout << "            FACTURA DE COMPRA\n";
            cout << "========================================\n";
            cout << "Cliente: " << Nombredecliente << "\n";
            cout << "Carnet:  " << carnetEstudiante << "\n";
            cout << "----------------------------------------\n";
            
            
            for (int i = 0; i < 7; i++) {
                if (cantidadseleccion[i] > 0) {
                    cout << cantidadseleccion[i] << "x " << comidaproducto[i] 
                         << " - $" << fixed << setprecision(2) << (cantidadseleccion[i] * precioproducto[i]) << "\n";
                }
            }
            
            cout << "----------------------------------------\n";
            cout << "Subtotal:   $" << fixed << setprecision(2) << Totalcompra << "\n";
            cout << "Descuento (" << descuento << "%): -$" << fixed << setprecision(2) << montoDescuento << "\n";
            cout << "TOTAL A PAGAR: $" << fixed << setprecision(2) << totalFinal << "\n";
            cout << "========================================\n";
        }
    }

    // 8. Salida limpia
    cout << "\nPresione Enter para salir...\n";
    cin.ignore(); 
    cin.get();    

    return 0;
}