#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED
#define MAX_QUEUE_SIZE 100

typedef struct element {
    char c;
    int n;
    struct element *fg;
    struct element *fd;
}element;

typedef struct element* TArbre;



struct Queue {
    int front, tail;
    char c;
    struct element *items[MAX_QUEUE_SIZE];
};
/* -------------------------------------------------------*/
/* Primitives de gestion des arbres */
/* -------------------------------------------------------*/
TArbre arbreConsVide(void);
/*
   this function returns a xxx
*/
int arbreEstVide(TArbre a);
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd);
char arbreRacineLettre(TArbre a);
int arbreRacineNbOcc(TArbre a);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);
void arbreSuppr(TArbre a);
/* -------------------------------------------------------*/


#endif // ARBRE_H_INCLUDED
