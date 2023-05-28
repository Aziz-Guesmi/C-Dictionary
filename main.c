/* -------------------------------------------------------*/
/* Eval TP 1 ING 2021 (ISI) */
/* fichier "projet.c" */
/* -------------------------------------------------------*/
#include <stdio.h>

#include "arbre.h"
#include "dico.h"
#define COUNT 5

/* -------------------------------------------------------*/
/* Eval TP 1 ING 2021 (ISI) */
/* fichier "projet.c" */
/* -------------------------------------------------------*/
/* -------------------------------------------------------*/


void print2DUtil(TArbre root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->fd, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
        if(root->c == '\0'){
                printf("\\0");

        } else{
                printf("%c\n", root->c);

        }

    // Process left child
    print2DUtil(root->fg, space);
}
/*
int main(int argc, char **argv)
{
    TArbre dico;
    char buffer[100];
    dico = arbreConsVide();

    strcpy(buffer, "gallon");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");
    strcpy(buffer, "munier");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");
    strcpy(buffer, "abenia");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");
    strcpy(buffer, "munier");

    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");
        strcpy(buffer, "mu");
    dicoInsererMot(buffer, &dico);
    strcpy(buffer, "mumu");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");
    strcpy(buffer, "alpha");
    dicoInsererMot(buffer, &dico);
    strcpy(buffer, "alphabeta");
    dicoInsererMot(buffer, &dico);
    strcpy(buffer, "al");
    dicoInsererMot(buffer, &dico);
        strcpy(buffer, "a");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico); printf("\n");
    printf("\"%s\" \t -> %d\n", "gallon", dicoNbOcc("gallon",dico));
    printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOcc("mumu",dico));
    printf("\"%s\" \t -> %d\n", "munier", dicoNbOcc("munier",dico));
    printf("\"%s\" \t -> %d\n", "gastro", dicoNbOcc("gastro",dico));
    printf("\"%s\" \t -> %d\n", "lespine", dicoNbOcc("lespine",dico));
    printf("\"%s\" \t\t -> %d\n", "aaa", dicoNbOcc("aaa",dico));
    printf("\n");
    printf("azeddsqf");
    dicoAfficher2(dico);

}
*/
/* -------------------------------------------------------*/
