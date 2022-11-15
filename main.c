#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAILLE_GRILLE 10
#define VIDE 0
#define DECOUVERTE 1
#define TRESOR_CACHE 2
#define TRESOR_DECOUVERT 3


void initialiserGrille(unsigned int grille[TAILLE_GRILLE][TAILLE_GRILLE]);
void afficherGrille(unsigned int grille[TAILLE_GRILLE][TAILLE_GRILLE]);
void demanderLigneEtColonne(unsigned int* ligne, unsigned int* colonne);
void cacherTresor(unsigned int grille[TAILLE_GRILLE][TAILLE_GRILLE],unsigned int* x, unsigned int* y);
void play (unsigned int grille[TAILLE_GRILLE][TAILLE_GRILLE],unsigned int x, unsigned int y,unsigned int ligne,unsigned int colone);
void afficherDistance(unsigned int x1, unsigned int unsigned y1,unsigned int x2, unsigned int y2);
void afficherInformations(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);

int main() {
    //initialisation des variables
    unsigned int grille [TAILLE_GRILLE]={};
    unsigned int ligne = 0;
    unsigned int colone =0;
    unsigned int ligneTresor = 2;
    unsigned int colonetresor = 2;

    //initialisation de la grille
    initialiserGrille(grille);
    cacherTresor(grille,&ligneTresor,&colonetresor);
    srand (time(NULL));

    //play
    play(grille,ligneTresor,colonetresor,ligne,colone);

    return 0;
}


void initialiserGrille(unsigned int grille[TAILLE_GRILLE][TAILLE_GRILLE]){
    for (int i=0;i<TAILLE_GRILLE;i++){
        for (int j=0;j<TAILLE_GRILLE; j++){
            grille[i][j] = VIDE;
        }
    }
}

void afficherGrille(unsigned int grille[TAILLE_GRILLE][TAILLE_GRILLE]){
    for (int i=0;i<TAILLE_GRILLE;i++){
        for (int j=0;j<TAILLE_GRILLE; j++){
            switch (grille [i][j]) {
                case VIDE:
                    printf("X  ");
                    break;
                case DECOUVERTE:
                    printf("   ");
                    break;
                case TRESOR_CACHE:
                    printf("X  ");
                    break;
                case TRESOR_DECOUVERT:
                    printf("$  ");
                    break;
            }
        }
        printf("\n");
    }
}

void demanderLigneEtColonne(unsigned int* ligne, unsigned int* colonne){
    printf("\n");
    printf("Entrez la prochaine ligne a jouer ?");
    printf("\n");
    scanf ("%d",ligne);
    while (*ligne>TAILLE_GRILLE||*ligne<0){
        printf("veuillez entrer une valeur entre 0 et %d",TAILLE_GRILLE);
        printf("\n");
        printf("Entrez la prochaine ligne a jouer ?");
        printf("\n");
        scanf ("%d",ligne);
        printf("\n");
    }


    printf("\n");
    printf("Entrez la prochaine colonne a jouer ?");
    printf("\n");
    scanf ("%d",colonne);
    while (*ligne>TAILLE_GRILLE||*ligne<0){
        printf("veuillez entrer une valeur entre 0 et %d",TAILLE_GRILLE);
        printf("\n");
        printf("Entrez la prochaine ligne a jouer ?");
        printf("\n");
        scanf ("%d",ligne);
        printf("\n");
    }
}

void cacherTresor(unsigned int grille[TAILLE_GRILLE][TAILLE_GRILLE],unsigned int* x, unsigned int* y){

    *x = rand()%TAILLE_GRILLE;
    *y = rand()%TAILLE_GRILLE;

    grille [*x][*y]= TRESOR_CACHE;
}

void play (unsigned int grille[TAILLE_GRILLE][TAILLE_GRILLE],unsigned int x, unsigned int y,unsigned int ligne,unsigned int colone){
    afficherGrille(grille);
    demanderLigneEtColonne(&ligne,&colone);
    if (ligne==x&&colone==y){
        grille[x][y]= TRESOR_DECOUVERT;
        printf("gg well play");
    }else {
        grille[ligne][colone]=DECOUVERTE;
        afficherDistance(x,y,ligne,colone);
        afficherInformations(x,y,ligne,colone);
        play(grille,x,y,ligne,colone);

    }

}

void afficherDistance(unsigned int x1, unsigned int unsigned y1,unsigned int x2, unsigned int y2) {
    printf("Le tresor se trouve a une distance d’environ %d cases\n\n\n", abs(x2 - x1) + abs(y2 - y1));
}


void afficherInformations(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2){
    printf("Le tresor se trouve en");
    if (y1<y2){
        printf("bas");
    }
    if (y1>y2){
        printf("haut");
    }
    if (x1<x2){
        printf("à gauche");
    }
    if (x1>x2){
        printf("à droite");
    }

}

