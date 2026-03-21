#include <iostream>
#include "tablero.h"
#include "pieza.h"

using namespace std;

int main() {

    int ancho, alto;

    cout << "Ancho del tablero: ";
    cin >> ancho;

    cout << "Alto del tablero: ";
    cin >> alto;

    Tablero tablero(ancho, alto);

    Pieza pieza;

    char opcion;

    while(true) {

        tablero.imprimir();

        cout << "a izquierda | d derecha | s bajar: ";
        cin >> opcion;

        if(opcion == 'a')
            pieza.moverIzquierda();

        if(opcion == 'd')
            pieza.moverDerecha();

        if(opcion == 's')
            pieza.bajar();

        if(tablero.detectarColision(pieza.forma, pieza.fila)) {

            pieza.fila--;
            tablero.fijarPieza(pieza.forma, pieza.fila);

            tablero.limpiarFilas();

            pieza = Pieza();
        }

        if(tablero.gameOver()) {

            cout << "GAME OVER" << endl;
            break;
        }
    }

    return 0;
}
