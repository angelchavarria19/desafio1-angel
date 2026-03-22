#include "pieza.h"
#include <cstdlib>

Pieza::Pieza(){

    int tipo = rand()%7;

    if(tipo==0){ // I

        alto=1;
        forma[0]=0b00011110;
    }

    if(tipo==1){ // O

        alto=2;

        forma[0]=0b00001100;
        forma[1]=0b00001100;
    }

    if(tipo==2){ // T

        alto=2;

        forma[0]=0b00011100;
        forma[1]=0b00001000;
    }

    if(tipo==3){ // S

        alto=2;

        forma[0]=0b00001110;
        forma[1]=0b00011100;
    }

    if(tipo==4){ // Z

        alto=2;

        forma[0]=0b00011100;
        forma[1]=0b00001110;
    }

    if(tipo==5){ // L

        alto=2;

        forma[0]=0b00011100;
        forma[1]=0b00000100;
    }

    if(tipo==6){ // J

        alto=2;

        forma[0]=0b00011100;
        forma[1]=0b00010000;
    }

    fila=0;
}

void Pieza::izquierda(){

    for(int i=0;i<alto;i++)
        forma[i]<<=1;
}

void Pieza::derecha(){

    for(int i=0;i<alto;i++)
        forma[i]>>=1;
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
