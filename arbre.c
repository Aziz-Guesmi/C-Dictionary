#include <stdlib.h>
#include "arbre.h"

TArbre arbreConsVide(void){
    return NULL;
}

int arbreEstVide(TArbre a){
    if(a==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

TArbre arbreCons(char c, int n, TArbre fg, TArbre fd){
    TArbre mon_arbre = NULL;
    mon_arbre = (TArbre)malloc(sizeof(element));
    mon_arbre->fg = fg;
    mon_arbre->fd = fd;
    mon_arbre->c = c;
    mon_arbre->n = n;
    return mon_arbre;
}

char arbreRacineLettre(TArbre a){
    return a->c;
}

int arbreRacineNbOcc(TArbre a){
    return a->n;
}

TArbre arbreFilsGauche(TArbre a){
    return a->fg;
}

TArbre arbreFilsDroit(TArbre a){
    return a->fd;
}

void arbreSuppr(TArbre a){
    if(!arbreEstVide){
        arbreSuppr(a->fg);
        arbreSuppr(a->fd);
        free(a);
        a = NULL;
    }
}
