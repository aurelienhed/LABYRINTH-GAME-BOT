#include <stdio.h>
#include <stdlib.h>
#include "APIS/clientAPI.h"
#include "APIS/labyrinthAPI.h"
#include "Data/data.h"



int main(){
    //t_joueur adversaire; 
    //t_joueur me; 
    //t_labyrintheInfos labyrinthe; 
    //t_tuile tableau[taille]
    


    

















    char* labyrinthName = malloc(sizeof(char)* 51); 
    int sizeX; 
    int sizeY;  
    connectToServer("vps-1a2cee88.vps.ovh.net", 1234, "DORI"); 
    printf("--------------------------------------------Connexion au serveur--------------------------------------------\n");
    
    


    waitForLabyrinth("TRAINING DONTMOVE start=1 seed=1234", labyrinthName, &sizeX, &sizeY);
    int tailleData = ((sizeX*sizeY+5)*11);
    
    char * labyData = malloc(sizeof(char) * tailleData);

    int start = getLabyrinth(labyData);
    // start = 0 me commence si start =  1 alors l'adversaire commence
    t_return_code winningStatus = NORMAL_MOVE;

    

    printf("%s\n",labyData);
    
    

    //printf("%s", labyrinthName);

    //printf("Coordonnées de start %d %d\n", sizeX-1, sizeY-1);

   

   


    
    



    while(winningStatus == 0){
        printLabyrinth(); // affiche le labyrinthe

        

        if (start == 0){
            //printf("Your turn to play\n");
            char * move = malloc(sizeof(char) *20);
            char message[10] = "Héhéhé";
            int n1;
            int n2;
            int n3;
            int n4;
            int n5;
            //printf("Your Move\n");
            scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
            sprintf(move, "%d %d %d %d %d", n1, n2, n3, n4, n5);
            //printf("Your move is %s \n", move);           
            winningStatus = sendMove(move, message);
            start = 1;
            free(move);

        }
        else{
            //printf("The opponent's turn\n");
            char * move = malloc(sizeof(char)*tailleData);
            char * msg = malloc(sizeof(char)*50);
            winningStatus = getMove(move, msg);
            //printf("Le coup joué est  : \n");
            //printf("%s\n\n",move);
            //printf("Le message est\n");
            //printf("%s\n\n",msg);
            start = 0;
            free(move);
            free(msg);

        }





    }
        
    


    


    
    
    
    
    
    
    
    
    
    
    
    closeConnection();
    free(labyrinthName); 
    free(labyData);
    
    
    return EXIT_SUCCESS; 
}