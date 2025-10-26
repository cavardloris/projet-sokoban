#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"


int afficher_grid(char grid[81])
{
    printf(" # # # # # # # # # # #\n");
    printf(" # %c %c %c %c %c %c %c %c %c #\n", grid[0], grid[1], grid[2], grid[3], grid[4], grid[5], grid[6], grid[7], grid[8]);
    printf(" # %c %c %c %c %c %c %c %c %c #\n", grid[9], grid[10], grid[11], grid[12], grid[13], grid[14], grid[15], grid[16], grid[17]);
    printf(" # %c %c %c %c %c %c %c %c %c #\n", grid[18], grid[19], grid[20], grid[21], grid[22], grid[23], grid[24], grid[25], grid[26]);
    printf(" # %c %c %c %c %c %c %c %c %c #\n", grid[27], grid[28], grid[29], grid[30], grid[31], grid[32], grid[33], grid[34], grid[35]);
    printf(" # %c %c %c %c %c %c %c %c %c #\n", grid[36], grid[37], grid[38], grid[39], grid[40], grid[41], grid[42], grid[43], grid[44]);
    printf(" # %c %c %c %c %c %c %c %c %c #\n", grid[45], grid[46], grid[47], grid[48], grid[49], grid[50], grid[51], grid[52], grid[53]);
    printf(" # %c %c %c %c %c %c %c %c %c #\n", grid[54], grid[55], grid[56], grid[57], grid[58], grid[59], grid[60], grid[61], grid[62]);
    printf(" # %c %c %c %c %c %c %c %c %c #\n", grid[63], grid[64], grid[65], grid[66], grid[67], grid[68], grid[69], grid[70], grid[71]);
    printf(" # %c %c %c %c %c %c %c %c %c #\n", grid[72], grid[73], grid[74], grid[75], grid[76], grid[77], grid[78], grid[79], grid[80]);
    printf(" # # # # # # # # # # # \n");
    return 0;
}
   
position creer_joueur_aleatoire() 
{
    position joueur;
    joueur.pos_x = rand() % 9; 
    joueur.pos_y = rand() % 9; 
    return joueur;
}

position creer_point_aleatoire() 
{
    position point;
    point.pos_x = rand() % 9; 
    point.pos_y = rand() % 9; 
    return point;
}

position creer_colis_aleatoire() 
{
    position colis;
    colis.pos_x = 1 + rand() % 7; 
    colis.pos_y = 1 + rand() % 7; 
    return colis;
}

char deplacer_joueur(position *joueur) 
{
    char choix;
    printf("Choisissez une direction ou vous deplacer : z: haut, s: bas, q: gauche, d: droite \n");
    scanf(" %c", &choix);  

    if (choix == 'z') {
        if (joueur->pos_y > 0)
            joueur->pos_y--;  // haut
    } 
    else if (choix == 's') {
        if (joueur->pos_y < 8)
            joueur->pos_y++;  // bas
    } 
    else if (choix == 'q') {
        if (joueur->pos_x > 0)
            joueur->pos_x--;  // gauche
    } 
    else if (choix == 'd') {
        if (joueur->pos_x < 8)
            joueur->pos_x++;  // droite
    } 
    else {
        printf("Touche invalide ! Utilisez z, q, s ou d.\n"); // si l'on entre pas pas la bonne touche
    }
    return choix;
}




