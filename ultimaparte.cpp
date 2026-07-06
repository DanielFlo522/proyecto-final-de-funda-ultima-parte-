#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Producto {
    string nombre;
    double precio;

};

int main(){
    cout << fixed << setprecision(2);

     vector<Producto> productos = {
        {"Cafe con Leche", 1.50},
        {"Medialuna", 0.80},
        {"Sandwich de Jamon y Queso", 3.00},
        {"Ensalada Mixta", 3.50},
        {"Gaseosa 500ml", 1.80},
        {"Jugo Natural", 2.20},
        {"Porcion de Torta", 2.50}
    };
    
    //Dantos del cliente 
string Nombredecliente;
int carnetEstudiante;

cout << "===================================" << endl;
cout <<  "Cafeteria Universitaria - Registro" << endl;
cout << "===================================" << endl;
cout << "Ingrese el nombre del cliente:";
getline(cin, Nombredecliente);
cout << "Ingrese el carten del estudiante:";
cin >> carnetEstudiante;

// Arreglos para cantidad de productos 
vector<int> cantidadseleccion(7, 0);
    vector<double> precioproducto(7);
    vector<string> comidaproducto(7);

    for (int i = 0; i < 7; ++i) {
        comidaproducto[i] = productos[i].nombre;
        precioproducto[i] = productos[i].precio;

        cout << "\nSeleccione las cantidades para los sigientes productos:" << endl;
        double Totalcompra = 0.0;
        for (int i = 0; i = 7; i++){
            cout << "- " << comidaproducto[i] << " ($" << precioproducto[i] << "): ";
        cin >> cantidadseleccion[i];
        if (cantidadseleccion[i] < 0) {
            cantidadseleccion[i] = 0;
        }

            Totalcompra += cantidadseleccion[i] * precioproducto[i];
        }

        //Descuento
        double descuentoAplicado = 0.0;
        count << "\nIngrese el porcentaje de descuento (0 a 100):";
        double tempDescuento;
        cin >> tempDescuento;

        // Aprobacion de descuento
        if (tempDescuento >= 0 && tempDescuento <= 100) {
        descuentoAplicado = tempDescuento / 100.0;
    }
     double facturaTotal = Totalcompra * (1.0 - descuentoAplicado);

     if
     string nombreArchivo = Nombrecliente + "_" + to_string(carnetEstudiante) + ".txt";

      ofstream archivo(nombreArchivo);

      if(archivo.is_open()){
         archivo << "=========================================" << endl;
        archivo << "CAFETERIA UNIVERSITARIA" << endl;
        archivo << "=========================================" << endl;
        archivo << "Cliente: " << Nombrecliente << endl;
        archivo << "Carnet: " << carnetEstudiante << endl;
        archivo << "=========================================" << endl;
        archivo << left << setw(25) << "PRODUCTO" << " | " << setw(5) << "CANT." << " | " << "TOTAL ITEM" << endl;
        archivo << "-----------------------------------------" << endl;
       
        for (int i = 0; i < 7; ++i) {
             if (cantidadseleccion[i] > 0) {
                
                double subtotalItem = cantidadseleccion[i] * precioproducto[i];

                
                archivo << left << setw(25) << comidaproducto[i] 
                        << " | " << setw(5) << cantidadseleccion[i] 
                        << " | $" << fixed << setprecision(2) << subtotalItem << endl;
            }
             archivo << "-----------------------------------------" << endl;
        archivo << "Subtotal sin descuento: $" << fixed << setprecision(2) << Totalcompra << endl;
        archivo << "Descuento aplicado: " << fixed << setprecision(1) << (descuentoAplicado * 100.0) << "%" << endl;
        archivo << "Precio final: $" << fixed << setprecision(2) << facturaTotal << endl;
        archivo << "=========================================" << endl;
        archivo << "¡Gracias por su compra!" << endl;
        archivo << "=========================================" << endl;

        archivo.close();

         cout << "\nFactura " << nombreArchivo << " generada con exito." << endl;
    } else {
        
        cout << "\nNo se pudo generar la factura" << endl;
    }
      cout << "\nPresione Enter para salir...";
    cin.ignore();
    cin.get();
     
    return 0;
      }

      






}