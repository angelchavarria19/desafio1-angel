#include "tablero.h"
#include <iostream>

Tablero::Tablero(int w,int h){

    ancho = w;
    alto = h;

    filas = new uint32_t[alto];

    for(int i=0;i<alto;i++)
        filas[i] = 0;
}

Tablero::~Tablero(){

    delete[] filas;
}

void Tablero::imprimir(uint32_t* pieza,int fila,int altoPieza){

    for(int i=0;i<alto;i++){

        uint32_t linea = filas[i];

        if(i>=fila && i<fila+altoPieza)
            linea |= pieza[i-fila];

        for(int j=ancho-1;j>=0;j--){

            if(linea & (1<<j))
                std::cout<<"#";
            else
                std::cout<<".";
        }

        std::cout<<std::endl;
    }

    std::cout<<std::endl;
}

bool Tablero::colision(uint32_t* pieza,int fila,int altoPieza){

    for(int i=0;i<altoPieza;i++){

        if(fila+i >= alto)
            return true;

        if(filas[fila+i] & pieza[i])
            return true;
    }

    return false;
}

void Tablero::fijar(uint32_t* pieza,int fila,int altoPieza){

    for(int i=0;i<altoPieza;i++)
        filas[fila+i] |= pieza[i];
}

void Tablero::limpiar(){

    uint32_t llena = (1<<ancho)-1;

    for(int i=0;i<alto;i++){

        if(filas[i] == llena){

            for(int j=i;j>0;j--)
                filas[j] = filas[j-1];

            filas[0] = 0;
        }
    }
}

bool Tablero::gameOver(){

    return filas[0] != 0;
}
