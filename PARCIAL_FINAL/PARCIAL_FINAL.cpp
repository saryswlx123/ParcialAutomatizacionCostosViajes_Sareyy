// PARCIAL FINAL SAREY NALIETH SALGUERO LANDINEZ
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//FUNCIONES

// Funcion para validar datos de entrada (distancia y costo)
double validarDato(string mensaje) {
    double valor;
    do {
        cout << mensaje;
        cin >> valor;
        if (valor < 0) {
            cout << "Error: el valor no puede ser negativo. Intente de nuevo." << endl;
        }
	} while (valor < 0);
	return valor;
}

// Funcion para calcular total ganado por conductor
double calcularTotal(double distancia[], double costo[], int viajes) {
    double total = 0;
    for (int i = 0; i < viajes; i++) {
        total += distancia[i] * costo[i];
    }
    return total;
}

// Funcion pra calcular el promedio de distancia por conductor
double promedioDistancia(double distancia[], int viajes) {
    double suma = 0;
    for (int i = 0; i < viajes; i++) {
        suma += distancia[i];
    }
    if (viajes > 0) {
        return suma / viajes;
    }
    else {
        return 0;
    }
}


int main() {
    int conductores, viajes;
    string nombres[10], mejorConductor;
    double totalGanado[10], promedioDist[10], distancia[10], costo[10], mayorIngreso = 0;

    cout << fixed << setprecision(2);

    // Pedir el número de conductores
    do {
        cout << "Ingrese la cantidad de conductores (maximo 10): ";
        cin >> conductores;

        if (conductores <= 0 || conductores > 10) {
            cout << "Error: ingrese un número válido entre 1 y 10." << endl;
        }
    } while (conductores <= 0 || conductores > 10);

    // Bucle anidado para los datos (nombre, viajes, distancia y costo) de cada conductor  
    for (int i = 0; i < conductores; i++) {
        cout << endl << "===== CONDUCTOR #" << i + 1 << " =====" << endl;
        cout << "Nombre: ";
        cin >> nombres[i];

        // Pedir el número de viajes realizados y validar que sea negitivo ni mayor de 10 

        do { //En caso de que sea un num invalido, pedir de nuevo el dato
            cout << "Ingrese el número de viajes realizados: ";
            cin >> viajes;

            if (viajes <= 0 || viajes > 10) {
                cout << "Error!! ingrese un número entre 1 y 10." << endl;
            }
        } while (viajes <= 0 || viajes > 10);

        // Bucle para pedir la distancia y el costo
        for (int j = 0; j < viajes; j++) {
            cout << endl << "--- VIAJE #" << j + 1 << " ---" << endl;
            distancia[j] = validarDato("Distancia (km): ");
            costo[j] = validarDato("Costo por km ($): ");
        }

        // Funciones en el maain para luego ponerla en la salida
        totalGanado[i] = calcularTotal(distancia, costo, viajes);
        promedioDist[i] = promedioDistancia(distancia, viajes);

        // Calcular el conductor con mayor ingreso
        if (totalGanado[i] > mayorIngreso) {
            mayorIngreso = totalGanado[i];
            mejorConductor = nombres[i];
        }
    }

    // ======= RESUMEN FINAL =======

    cout << endl << "================== RESUMEN DE VIAJES ==================" << endl;
    //Bucle para recorrer los conductores y mostrar su resumen
	for (int i = 0; i < conductores; i++) { 
        cout << endl << "Conductor: " << nombres[i] << endl;
        cout << "Total ganado ($): " << totalGanado[i] << endl;
        cout << "Promedio de distancia (km): " << promedioDist[i] << endl;
    }

    cout << "==========================================================================" << endl;
    cout << "El conductor con mayor ingreso fue: " << mejorConductor << " con $" << mayorIngreso << endl;
    cout << "==========================================================================" << endl;

    return 0;
}