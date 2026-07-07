#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 

using namespace std;


struct Producto {
    string nombre;
    double precio;
    
};

int main() {
    
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


  
    cout << "Ingrese el nombre del cliente: ";
   
    getline(cin, Nombredecliente);

    cout << "Ingrese el carnet del estudiante: ";
    cin >> carnetEstudiante;
    cout << endl;

    
    vector<int> cantidadseleccion(7, 0);
    vector<double> precioproducto(7);
    vector<string> comidaproducto(7);

    cout << "Seleccione las cantidades para los siguientes productos:\n";
    
   
    for (int i = 0; i < 7; i++) {
        comidaproducto[i] = productos[i].nombre;
        precioproducto[i] = productos[i].precio;

        
        cout << i + 1 << ". " << comidaproducto[i] << " ($" << fixed << setprecision(2) << precioproducto[i] << "): ";
        cin >> cantidadseleccion[i];
    }
    
    //Descuento
    double descuento = 0.0;
    cout << "\nIngrese el porcentaje de descuento (0 a 100): ";
    cin >> descuento;

    
    if (descuento < 0 || descuento > 100) {
        cout << "\nNo se pudo generar la factura. Porcentaje de descuento invalido.\n";
    } else {
       
        double Totalcompra = 0.0;
        for (int i = 0; i < 7; i++) {
            Totalcompra += cantidadseleccion[i] * precioproducto[i];
        }

       
        if (Totalcompra == 0.0) {
            cout << "\nNo se pudo generar la factura. No selecciono ningun producto.\n";
        } else {
            
            double montoDescuento = Totalcompra * (descuento / 100.0);
            double totalFinal = Totalcompra - montoDescuento;

            cout << "\n========================================\n";
            cout << "            CAETERIA UNIVERSITARIA\n";
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

    
    cout << "\nPresione Enter para salir...\n";
    cin.ignore(); 
    cin.get();    

    return 0;
}