#include <stdio.h>
#include <stdlib.h>
#include "data.h"



void setDataLaby(t_labyrintheInfos laby, char * labyData,int sizeX, int sizeY){
    laby.taille = sizeX * sizeY; 
    laby.TAILLEX = sizeX;
    laby.TAILLEY = sizeY;
    t_tuile * plateau = malloc(sizeof(t_tuile)* laby.taille); 
    for (int i=0; i<laby.taille; i++){
        *(plateau +i) = 
    }






    laby.plateau = plateau;
}


void setDataPlayers(t_joueur me, t_joueur adversaire,int start, int x, int y){
    if (start == 0){
        me.x = 0; 
        me.y = 0; 
        adversaire.x = x-1;
        adversaire.y = y-1;
    }
    else{
        me.x = x-1; 
        me.y = y-1; 
        adversaire.x = 0; 
        adversaire.y = 0;
    }
}


