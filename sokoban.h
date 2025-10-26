#ifndef SOKOBAN_H
#define SOKOBAN_H
struct s_pos {
    int pos_y;
    int pos_x;
};

typedef struct s_pos position;

int creation_grid();
int afficher_grid();
position creer_joueur_aleatoire();
position creer_point_aleatoire() ;
position creer_colis_aleatoire();
char deplacer_joueur(position *joueur);
#endif