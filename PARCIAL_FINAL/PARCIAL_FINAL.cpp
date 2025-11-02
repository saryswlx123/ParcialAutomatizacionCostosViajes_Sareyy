// PARCIAL AVANCE SAREY NALIETH SALGUERO LANDINEZ
#include <iostream>
#include <string>

using namespace std;

//FUNCIONES

// Funcion para calcular total ganado por conductor
float calcularTotal(float distancia[], float costo[], int viajes) {
    float total = 0;
    for (int i = 0; i < viajes; i++) {
        total += distancia[i] * costo[i];
    }
    return total;
}

// Funcion pra calcular el promedio de distancia por conductor
float promedioDistancia(float distancia[], int viajes) {
    float suma = 0;
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
    int i, j, conductores, viajes;
    string nombres[10], mejorConductor;
    float totalGanado[10], promedioDist[10], distancia[10], costo[10], mayorIngreso = 0;

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

        do { //En caso de que sea un nu,m invalido, pedir de nuevo el dato
            cout << "Ingrese el número de viajes realizados: ";
            cin >> viajes;

            if (viajes <= 0 || viajes > 10) {
                cout << "Error!! ingrese un número entre 1 y 10." << endl;
            }
        } while (viajes <= 0 || viajes > 10);

        // Bucle para pedir la distancia y el costo
        for (int j = 0; j < viajes; j++) {
            cout << endl << "--- VIAJE #" << j + 1 << " ---" << endl;

            do {  // Validar que la distancia no sea negativa o sino pedirla de nuevo
                cout << "Distancia (km): ";
                cin >> distancia[j];
                if (distancia[j] < 0) {
                    cout << "La distancia no puede ser negativa!!" << endl;
                }
            } while (distancia[j] < 0);

            do { // Validar que el costo no sea negativo o sino pedirlo de nuevo
                cout << "Costo por km ($): ";
                cin >> costo[j];
                if (costo[j] < 0) {
                    cout << "El costo no puede ser negativo!!" << endl;
                }
            } while (costo[j] < 0);
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
    // (Falta terminar)
    cout << "========= RESUMEN DE VIAJES =========" << endl;
    cout << "Conductores:" << endl;
    cout << "Total ganado ($) : " << endl;
    cout << "Promedio distancia (km) : " << endl;
    cout << "El contador con mayor ingreso fue: ";

    return 0;

}