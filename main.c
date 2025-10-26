#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"
#include <time.h>
int main()
{
    srand(time(NULL));

    char *grid = malloc(81 * sizeof(char));  // creation de la grille
    if (!grid) return 1;

    for (int i = 0; i < 81; i++) grid[i] = ' ';

    

    position joueur = creer_joueur_aleatoire();
    grid[joueur.pos_x + joueur.pos_y *9] = 'O'; // creation de la position du joueur
    printf("Position joueur : %d ; %d\n", joueur.pos_x, joueur.pos_y); // affichage de celle-ci



   position point = creer_point_aleatoire();
    while (point.pos_x == joueur.pos_x && point.pos_y == joueur.pos_y)
    {
        point = creer_point_aleatoire(); 
    }
    grid[point.pos_x + point.pos_y *9] = '.';   // creation de l'emplacement
   printf("Position emplacement : %d ; %d\n", point.pos_x, point.pos_y);


   
   
   position colis = creer_colis_aleatoire();
   while ((colis.pos_x == joueur.pos_x && colis.pos_y == joueur.pos_y) || (colis.pos_x == point.pos_x && colis.pos_y == point.pos_y))
   {
        colis = creer_colis_aleatoire(); 
   }
   grid[colis.pos_x + colis.pos_y *9] = 'X';   // creation du colis
   printf("Position colis : %d ; %d\n", colis.pos_x, colis.pos_y);
   
 
   afficher_grid(grid); // affichage de la grille


   int fin = 0;
   while(fin == 0)
   {
        printf("Position joueur : %d ; %d\n", joueur.pos_x, joueur.pos_y);
        printf("Position colis : %d ; %d\n", colis.pos_x, colis.pos_y);
        printf("Position emplacement : %d ; %d\n", point.pos_x, point.pos_y);
        afficher_grid(grid);
        if ((joueur.pos_x == colis.pos_x && joueur.pos_y == colis.pos_y)) 
        {
            grid[joueur.pos_x + joueur.pos_y * 9] = ' ';
        }
        grid[joueur.pos_x + joueur.pos_y * 9] = ' ';
        char direction = deplacer_joueur(&joueur);
        if(joueur.pos_x == colis.pos_x && joueur.pos_y == colis.pos_y)
        {
            grid[colis.pos_x + colis.pos_y * 9] = ' ';

            if (direction == 'z' && colis.pos_y > 0)
            {
                colis.pos_y--;
            }
            else if (direction == 's' && colis.pos_y < 8)
            {
                colis.pos_y++;
            }
            else if (direction == 'q' && colis.pos_x > 0)
            {
                colis.pos_x--;
            }
            else if (direction == 'd' && colis.pos_x < 8)
            {
                colis.pos_x++;
            }
            else
            {
                if (direction == 'z') 
                {
                    joueur.pos_y++;
                }
                else if (direction == 's') 
                {
                    joueur.pos_y--;
                }
                else if (direction == 'q') 
                {
                    joueur.pos_x++;
                }
                else if (direction == 'd') 
                {
                    joueur.pos_x--;
                }
            }
        }
        
        grid[colis.pos_x + colis.pos_y * 9] = 'X';
        grid[joueur.pos_x + joueur.pos_y * 9] = 'O';
        if(colis.pos_x == point.pos_x && colis.pos_y == point.pos_y)
        {
            printf("Bravo ! Vous avez gagné\n");
            afficher_grid(grid);
            fin ++;
        }
        else if((colis.pos_x == 0 && point.pos_x != 0) ||
        (colis.pos_x == 8 && point.pos_x != 8) ||
        (colis.pos_y == 0 && point.pos_y != 0) ||
        (colis.pos_y == 8 && point.pos_y != 8))
        {
            printf("Dommage vous avez perdu\n");
            afficher_grid(grid);
            fin ++;
        }
    }

    free(grid);
    return 0;
}