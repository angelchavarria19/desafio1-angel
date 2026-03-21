#include "tablero.h"
#include <iostream>

Tablero::Tablero(int w, int h) {

    ancho = w;
    alto = h;

    filas = new uint32_t[alto];

    for(int i = 0; i < alto; i++)
        filas[i] = 0;
}

Tablero::~Tablero() {

    delete[] filas;
}

void Tablero::imprimir() {

    for(int i = 0; i < alto; i++) {

        for(int j = ancho-1; j >= 0; j--) {

            if(filas[i] & (1 << j))
                std::cout << "#";
            else
                std::cout << ".";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

bool Tablero::detectarColision(uint32_t pieza, int fila) {

    if(fila >= alto)
        return true;

    if(filas[fila] & pieza)
        return true;

    return false;
}

void Tablero::fijarPieza(uint32_t pieza, int fila) {

    filas[fila] |= pieza;
}

void Tablero::limpiarFilas() {

    uint32_t llena = (1 << ancho) - 1;

    for(int i = 0; i < alto; i++) {

        if(filas[i] == llena) {

            for(int j = i; j > 0; j--)
                filas[j] = filas[j-1];

            filas[0] = 0;
        }
    }
}

bool Tablero::gameOver() {

    if(filas[0] != 0)
        return true;

    return false;
}
