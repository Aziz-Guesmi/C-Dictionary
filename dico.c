#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define LINE_WIDTH 150
#include "arbre.h"
#include "dico.h"
#define PARENT(i) ((i-1) / 2)
#define NUM_NODES 35



void dicoAfficher(TArbre a)
{
    if (!arbreEstVide(a))
    {
        printf("%c", arbreRacineLettre(a));
        dicoAfficher(arbreFilsGauche(a));
        dicoAfficher(arbreFilsDroit(a));
    }
}
void dicoAfficher2(TArbre a)
{
    char mot[100] = "\0";
    if (!arbreEstVide(a))
    {
        strncat(mot, &a->c, 1);
        aff_sa_gauche(a->fg, mot);
        dicoAfficher2(a->fd);
    }
}
void aff_sa_gauche(TArbre a, char mot[100])
{
    if (!arbreEstVide(a))
    {
        char p[100] = "\0";
        if (a->c == '\0')
            printf("mot: %s\n", mot);
        strcpy(p, mot);
        aff_sa_gauche(arbreFilsDroit(a), p);
        strncat(mot, &a->c, 1);
        aff_sa_gauche(arbreFilsGauche(a), mot);
    }
}

// void dicoInsererMot(char mot[], TArbre *pa){
//     TArbre mon_arbre ;
//     if(arbreEstVide(*pa)){
//         if(mot[0] == '\0'){
//             *pa = arbreCons(mot[0],1,arbreConsVide(),arbreConsVide());
//         }
//         else{
//             mon_arbre = arbreConsVide();
//             dicoInsererMot(mot+1,&mon_arbre);
//             *pa = arbreCons(mot[0],0,mon_arbre,arbreConsVide());
//         }
//     }
//     else{
//         if(mot[0] == arbreRacineLettre(*pa)){
//             if(mot[0] == '\0'){
//                 mon_arbre = *pa;
//                 *pa = NULL;
//                 *pa = arbreCons('\0',(arbreRacineNbOcc(mon_arbre)+1),arbreFilsGauche(mon_arbre),arbreFilsDroit(mon_arbre));
//             }
//             else{
//                 mon_arbre = arbreConsVide();
//                 mon_arbre = arbreFilsGauche(*pa);
//                 dicoInsererMot(mot+1,&mon_arbre);
//                 *pa = arbreCons(mot[0],0,mon_arbre,arbreFilsDroit(*pa));
//             }
//         }
//         else{
//             if((int)arbreRacineLettre(*pa) < (int)mot[0]){
//                 mon_arbre = arbreConsVide();
//                 mon_arbre = arbreFilsDroit(*pa);
//                 dicoInsererMot(mot,&mon_arbre);
//                 *pa = arbreCons(arbreRacineLettre(*pa),arbreRacineNbOcc(*pa),arbreFilsGauche(*pa),mon_arbre);
//             }
//             else{
//                 if(mot[0] == '\0'){
//                     *pa = arbreCons(*mot,1,arbreConsVide(),*pa);
//                 }
//                 else{
//                     mon_arbre = arbreConsVide();
//                     dicoInsererMot(mot+1,&mon_arbre);
//                     *pa = arbreCons(mot[0],0,mon_arbre,*pa);
//                 }
//             }
//         }
//     }
// }

void dicoInsererMot(char mot[], TArbre *pa)
{
    if (*pa == NULL)
    {
        *pa = arbreCons(mot[0], mot[0] == '\0' ? 1 : 0, arbreConsVide(), arbreConsVide());
        if (mot[0] != '\0')
        {
            dicoInsererMot(mot + 1, &(*pa)->fg);
        }
    }
    else
    {
        if (mot[0] == arbreRacineLettre(*pa))
        {
            if (mot[0] == '\0')
            {
                (*pa)->n = (*pa)->n + 1;
            }
            else
            {
                dicoInsererMot(mot + 1, &(*pa)->fg);
            }
        }
        else if ((int)arbreRacineLettre(*pa) < (int)mot[0])
        {
            dicoInsererMot(mot, &(*pa)->fd);
        }
        else
        {
            TArbre new_node = arbreCons(mot[0], mot[0] == '\0' ? 1 : 0, NULL, *pa);
            if (mot[0] != '\0')
            {
                dicoInsererMot(mot + 1, &new_node->fg);
            }
            *pa = new_node;
        }
    }
}

int dicoNbOcc(char mot[], TArbre a)
{
    if (!arbreEstVide(a))
    {
        if (arbreRacineLettre(a) == mot[0])
        {
            if (mot[0] == '\0')
            {
                return arbreRacineNbOcc(a);
            }
            else
            {
                return dicoNbOcc(mot + 1, arbreFilsGauche(a));
            }
        }
        else
        {
            if ((int)arbreRacineLettre(a) > (int)mot[0])
            {
                return 0;
            }
            else
            {
                return dicoNbOcc(mot, arbreFilsDroit(a));
            }
        }
    }
    else
    {
        return 0;
    }
}

int dicoNbMotsDifferents(TArbre a)
{
    if (!arbreEstVide(a))
    {
        int nbGauche = dicoNbMotsDifferents(arbreFilsGauche(a));
        int nbDroite = dicoNbMotsDifferents(arbreFilsDroit(a));
        int nbCourant = 0;
        if (arbreRacineLettre(a) == '\0')
        {
            nbCourant = 1;
        }
        return nbCourant + nbGauche + nbDroite;
    }
    else
    {
        return 0;
    }
}

int dicoNbMotsTotal(TArbre a)
{
    if (!arbreEstVide(a))
    {
        int nbGauche = dicoNbMotsTotal(arbreFilsGauche(a));
        int nbDroite = dicoNbMotsTotal(arbreFilsDroit(a));
        int nbCourant = arbreRacineNbOcc(a);
        return nbCourant + nbGauche + nbDroite;
    }
    else
    {
        return 0;
    }
}

int piocherMot(char *motPioche)
{
    FILE *dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule

    // On vérifie si on a réussi à ouvrir le dictionnaire
    if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0; // On retourne 0 pour indiquer que la fonction a �chou�
        // � la lecture du return, la fonction s'arréte immédiatement.
    }

    // On compte le nombre de mots dans le fichier (il suffit de compter les
    // entr�es \n
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while (caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard

    // On recommence � lire le fichier depuis le d�but. On s'arr�te lorsqu'on est arriv� au bon mot
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    /* Le curseur du fichier est positionn� au bon endroit.
    On n'a plus qu'� faire un fgets qui lira la ligne */
    fgets(motPioche, 100, dico);
    // On vire le \n � la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);
    return 1; // Tout s'est bien pass�, on retourne 1
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}

void affichageGraphique(TArbre root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 3;

    // Process right child first
    affichageGraphique(root->fd, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 3; i < space; i++)
        printf(" ");
    if (root->c == '\0')
    {
        printf("\\0 : %d", root->n);
    }
    else
    {
        printf("%c : %d\n", root->c, root->n);
    }

    // Process left child
    affichageGraphique(root->fg, space);
    printf("\n");
}

int maxDepth(TArbre node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->fg);
        int rDepth = maxDepth(node->fd);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void enqueue(struct Queue *queue, TArbre node)
{
    if (queue->tail == MAX_QUEUE_SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    queue->items[++queue->tail] = node;
    if (queue->front == -1)
        queue->front = 0;
}

struct element *dequeue(struct Queue *queue)
{
    if (queue->front == -1)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    TArbre node = queue->items[queue->front];
    if (queue->front == queue->tail)
        queue->front = queue->tail = -1;
    else
        queue->front++;
    return node;
}

int is_empty(struct Queue queue)
{
    return queue.front == -1;
}

void bfs(TArbre root, char *result, int *index)
{
    struct Queue queue; 
    int tree[NUM_NODES];
    int print_pos[NUM_NODES];
    int i, j, k, pos, x=1, level=0;

    print_pos[0] = 0;
    char test;
    queue.front = queue.tail = -1;
    enqueue(&queue, root);
    while (!is_empty(queue))
    {
        TArbre node = dequeue(&queue);
        result[(*index)++] = node->c;
        if (node->fg)
            enqueue(&queue, node->fg);
        if (node->fd)
            enqueue(&queue, node->fd);
    }
    // for (int cp = 0; cp < *index; cp++)
    // {
    //     test = result[cp];
    //     if (test == '\0')
    //         // printf("%d ) \\0 : %s\n",i);
    //         printf("%d)\\0 \n", cp);

    //     else
    //     {
    //         printf("%d ) %c \n ", cp, result[cp]);
    //     }
    // }
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("\n");
    printf("\n");

    for(i=0,j=1; i<NUM_NODES; i++,j++) {
        pos = print_pos[PARENT(i)] + (i%2?-1:1)*(LINE_WIDTH/(pow(2,level+1))+1);

        for (k=0; k<pos-x; k++) printf("%c",i==0||i%2?' ':'-');
        { {
            test = result[i];
             if (test == '\0')
            // printf("%d ) \\0 : %s\n",i);
            printf("\\0 ");

        else
        {
            printf("%c", result[i]);
        }
        }}

        print_pos[i] = x = pos+1;
        if (j==pow(2,level)) {
            printf("\n");
            level++;
            x = 1;
            j = 0;
        }
    }


}