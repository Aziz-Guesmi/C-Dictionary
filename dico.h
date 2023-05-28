#ifndef DICO_H_INCLUDED
#define DICO_H_INCLUDED
#include "arbre.h"

void dicoAfficher(TArbre a);
void aff_sa_gauche(TArbre a,char mot[100] );
void dicoAfficher2(TArbre a);
void dicoInsererMot(char mot[], TArbre *pa);
int dicoNbOcc(char mot[], TArbre a);
int dicoNbMotsDifferents(TArbre a);
int dicoNbMotsTotal(TArbre a);
int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);
void affichageGraphique(TArbre root, int space);
void bfs(TArbre root, char *resut, int *index);
#endif // DICO_H_INCLUDED
