#include <stdio.h>
#include <stdlib.h>
#include "APIS/clientAPI.h"
#include "APIS/labyrinthAPI.h"



int main(){
    char* labyrinthName = malloc(sizeof(char)* 51); 
    int sizeX; 
    int sizeY;  
    connectToServer("vps-1a2cee88.vps.ovh.net", 1234, "OREO"); 
    printf("--------------------------------------------Connexion au serveur--------------------------------------------\n");
    
    


    waitForLabyrinth("TRAINING DONTMOVE start=1", labyrinthName, &sizeX, &sizeY);
    int tailleData = ((sizeX*sizeY+5)*11);
    
    char * labyData = malloc(sizeof(char) * tailleData);

    int start = getLabyrinth(labyData);
    t_return_code winningStatus = NORMAL_MOVE;
    



    
    



    while(winningStatus == 0){
        printLabyrinth(); // affiche le labyrinthe

        

        if (start == 0){
            printf("Your turn to play\n");
            char * move = malloc(sizeof(char) *20);
            char * message = malloc(sizeof(char)*  50);
            message = "Héhéhé";
            int n1;
            int n2;
            int n3;
            int n4;
            int n5;
            printf("Your Move\n");
            scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
            sprintf(move, "%d %d %d %d %d", n1, n2, n3, n4, n5);
            printf("Your move is %s \n", move);           
            winningStatus = sendMove(move, message);
            start = 1;

        }
        else{
            printf("The opponent's turn\n");
            char * move = malloc(sizeof(char)*tailleData);
            char * msg = malloc(sizeof(char)*50);
            winningStatus = getMove(move, msg);
            printf("Le coup joué est  : \n");
            printf("%s\n\n",move);
            printf("Le message est\n");
            printf("%s\n\n",msg);
            start = 0;

        }





    }
    


    


    
    
    
    
    
    
    
    
    
    
    
    closeConnection();
    free(labyrinthName); 
    free(labyData);
    
    
    return EXIT_SUCCESS; 
}