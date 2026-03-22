#ifndef PIEZA_H
#define PIEZA_H

#include <cstdint>

class Pieza{

public:

    uint32_t forma[4];
    int alto;
    int fila;

    Pieza();

    void izquierda();
    void derecha();
    void bajar();

    void rotar();
};

#endif
