#ifndef TABLERO_H
#define TABLERO_H

#include <cstdint>

class Tablero{

private:

    int ancho;
    int alto;
    uint32_t* filas;

public:

    Tablero(int w,int h);
    ~Tablero();

    void imprimir(uint32_t* pieza,int fila,int altoPieza);

    bool colision(uint32_t* pieza,int fila,int altoPieza);

    void fijar(uint32_t* pieza,int fila,int altoPieza);

    void limpiar();

    bool gameOver();
};

#endif
