#include <iostream>
#include <cstdlib>
#include <ctime>

#include "tablero.h"
#include "pieza.h"

using namespace std;

int main(){

    srand(time(0));

    int ancho,alto;

    cout<<"Ancho del tablero: ";
    cin>>ancho;

    cout<<"Alto del tablero: ";
    cin>>alto;

    if(ancho<8 || alto<8 || ancho%8!=0){

        cout<<"Dimensiones invalidas"<<endl;
        return 0;
    }

    Tablero tablero(ancho,alto);

    Pieza pieza;

    char op;

    while(true){

        tablero.imprimir(pieza.forma,pieza.fila,pieza.alto);

        cout<<"a izquierda | d derecha | s bajar | r rotar : ";
        cin>>op;

        if(op=='a')
            pieza.izquierda();

        if(op=='d')
            pieza.derecha();

        if(op=='s')
            pieza.bajar();

        if(op=='r')
            pieza.rotar();

        pieza.bajar(); // caída automática

        if(tablero.colision(pieza.forma,pieza.fila,pieza.alto)){

            pieza.fila--;

            tablero.fijar(pieza.forma,pieza.fila,pieza.alto);

            tablero.limpiar();

            pieza = Pieza();
        }

        if(tablero.gameOver()){

            cout<<"GAME OVER"<<endl;
            break;
        }
    }

    return 0;
}
