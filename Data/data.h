#include <stdio.h>
#include <stdlib.h>

typedef enum {
    INSERT_LINE_LEFT = 0,
    INSERT_LINE_RIGHT = 1,
    INSERT_COLUMN_TOP = 2,
    INSERT_COLUMN_BOTTOM = 3
}t_insertion;

typedef struct{
    int x;
    int y;
    int cible; //prochain trésor
}t_joueur;

typedef struct
{
    int NORD;// présence de mur
    int EST; // présence de mur
    int SUD; // présence de mur
    int OUEST;// présence de mur
    int tresor; // numéro du trésor de la tuile 0 si aucun trésor

}t_tuile;

typedef struct
{
    int taille;
    int TAILLEX; 
    int TAILLEY; 
    t_joueur players[2];
    t_move lastMove;
    int whoPlays; // 0 if we play
    t_tuile tuileSup;
    t_tuile * plateau; // size X * y + x pour tableau à une dimension
}t_labyrintheInfos;

typedef struct
{
    int x, y; 
}t_pos;



typedef struct {
    t_insertion type; 
    int number; 
    int rotation; 
    t_pos moves[11];
    int nbMove;
}t_move;




