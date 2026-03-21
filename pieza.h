#ifndef PIEZA_H
#define PIEZA_H

#include <cstdint>

class Pieza {

public:

    uint32_t forma;
    int fila;

    Pieza();

    void moverIzquierda();
    void moverDerecha();
    void bajar();
};

#endif
