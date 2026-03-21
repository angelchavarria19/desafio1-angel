#include "pieza.h"
#include <cstdlib>

Pieza::Pieza(){

    int tipo = rand()%3;

    if(tipo==0){

        alto = 1;
        forma[0] = 0b00011110;
    }

    if(tipo==1){

        alto = 2;

        forma[0] = 0b00001100;
        forma[1] = 0b00001100;
    }

    if(tipo==2){

        alto = 2;

        forma[0] = 0b00011100;
        forma[1] = 0b00001000;
    }

    fila = 0;
}

void Pieza::izquierda(){

    for(int i=0;i<alto;i++)
        forma[i] <<=1;
}

void Pieza::derecha(){

    for(int i=0;i<alto;i++)
        forma[i] >>=1;
}

void Pieza::bajar(){

    fila++;
}

void Pieza::rotar(){

    if(alto==2){

        uint32_t temp = forma[0];
        forma[0] = forma[1];
        forma[1] = temp;
    }
}
