//
// Created by Roberto C on 31/10/24.
//

#include <iostream>
using namespace std;

int contarMovimientosDesdePosicion(int posicion, int movRestantes) {
    if (movRestantes == 1) {
        switch(posicion) {
            case 0: return 2;
            case 1: return 2;
            case 2: return 2;
            case 3: return 2;
            case 4: return 3;
            case 5: return 0;
            case 6: return 3;
            case 7: return 2;
            case 8: return 2;
            case 9: return 2;
            default: return 0;
        }
    }

    int totalMovimientos = 0;

    switch(posicion) {
        case 0:
            totalMovimientos += contarMovimientosDesdePosicion(4, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(6, movRestantes - 1);
            break;
        case 1:
            totalMovimientos += contarMovimientosDesdePosicion(6, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(8, movRestantes - 1);
            break;
        case 2:
            totalMovimientos += contarMovimientosDesdePosicion(7, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(9, movRestantes - 1);
            break;
        case 3:
            totalMovimientos += contarMovimientosDesdePosicion(4, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(8, movRestantes - 1);
            break;
        case 4:
            totalMovimientos += contarMovimientosDesdePosicion(0, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(3, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(9, movRestantes - 1);
            break;
        case 5:
            break;
        case 6:
            totalMovimientos += contarMovimientosDesdePosicion(0, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(1, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(7, movRestantes - 1);
            break;
        case 7:
            totalMovimientos += contarMovimientosDesdePosicion(2, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(6, movRestantes - 1);
            break;
        case 8:
            totalMovimientos += contarMovimientosDesdePosicion(1, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(3, movRestantes - 1);
            break;
        case 9:
            totalMovimientos += contarMovimientosDesdePosicion(2, movRestantes - 1);
            totalMovimientos += contarMovimientosDesdePosicion(4, movRestantes - 1);
            break;
    }

    return totalMovimientos;
}

int calcularMovimientosTotales(int cantidadMovimientos) {
    if (cantidadMovimientos == 1) {
        return 20;
    }

    int total = 0;
    for(int inicio = 0; inicio <= 9; inicio++) {
        total += contarMovimientosDesdePosicion(inicio, cantidadMovimientos);
    }

    return total;
}

int main() {
    cout << "Programa para calcular movimientos validos del caballo" << endl;
    cout << "---------------------------------------------------" << endl;

    int movimientos[] = {1, 2, 3, 5, 8, 10, 15, 18, 21, 23, 32};
    int cantidadPruebas = 11;

    cout << "Cantidad de movimientos | Posibilidades validas" << endl;
    cout << "---------------------------------------------------" << endl;

    for(int i = 0; i < cantidadPruebas; i++) {
        int resultado = calcularMovimientosTotales(movimientos[i]);
        cout << movimientos[i] << " | " << resultado << endl;
    }

    return 0;
}



