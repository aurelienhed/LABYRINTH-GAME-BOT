#include <stdio.h>
#include <stdlib.h>
#include "clientAPI.h"
#include "labyrinthAPI.h"



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
    
    printLabyrinth();


    
    



    while(winningStatus == NORMAL_MOVE){

        

        if (start == 0){
            printf("Your turn to play\n");
            printf("What's your turn\n");
            
            /*scanf();
            winningStatus = sendMove();
            printLabyrinth();
            */
            
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
            printLabyrinth();

        }





    }
    


    


    
    
    
    
    
    
    
    
    
    
    
    closeConnection();
    free(labyrinthName); 
    free(labyData);
    
    
    return EXIT_SUCCESS; 
}