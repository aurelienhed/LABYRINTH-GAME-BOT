#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
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
    t_tuile tuileSup;
    t_tuile * plateau;
}t_labyrintheInfos;




