#include "pieza.h"

Pieza::Pieza() {

    forma = 0b00011100;
    fila = 0;
}

void Pieza::moverIzquierda() {

    forma <<= 1;
}

void Pieza::moverDerecha() {

    forma >>= 1;
}

void Pieza::bajar() {

    fila++;
}
