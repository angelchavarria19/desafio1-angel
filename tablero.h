#ifndef TABLERO_H
#define TABLERO_H

#include <cstdint>

class Tablero {

private:
    int ancho;
    int alto;
    uint32_t* filas;

public:
    Tablero(int w, int h);
    ~Tablero();

    void imprimir();
    bool detectarColision(uint32_t pieza, int fila);
    void fijarPieza(uint32_t pieza, int fila);
    void limpiarFilas();
    bool gameOver();
};

#endif
