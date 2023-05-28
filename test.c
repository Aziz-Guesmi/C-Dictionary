#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"dico.h"


#include<conio.h>

void addstring(char buf[100]){
    char t='?';
    strncat(buf,&t,1);
    printf("%s test1\n",buf);
}
void DEMOINSERTION(TArbre dico, char *buffer)
{
 dicoAfficher(dico);

    printf("\"%s\" \t -> %d\n", "gallon", dicoNbOcc("gallon",dico));
    printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOcc("mumu",dico));
    printf("\"%s\" \t -> %d\n", "munier", dicoNbOcc("munier",dico));
    printf("\"%s\" \t -> %d\n", "gastro", dicoNbOcc("gastro",dico));
    printf("\"%s\" \t -> %d\n", "lespine", dicoNbOcc("lespine",dico));
    printf("\"%s\" \t\t -> %d\n", "aaa", dicoNbOcc("aaa",dico));
    printf("\n");

};

void trouverDansDICO(TArbre dico, char *buffer)
{

    if(dicoNbOcc(buffer, dico) != 0)
    {
        printf("Le mot existe dans le dictionnire");
    }
    else
    {
        printf("Le mot n'existe pas");
    }

}


int main()
{

    char result[100];int index = 0;
    int choice = 0;
    int i ;
    TArbre dico;
    char buffer[300],chaine[350],welcome[5000];
    dico = arbreConsVide();
    char mot[50];

    strcpy(buffer, "gallon");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "munier");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "abenia");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "munier");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "mumu");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "alpha");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "alphabeta");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "al");
    dicoInsererMot(buffer, &dico);

   addstring(buffer);
   printf("%s test2\n",buffer);


printf("****************************************************\n");
printf("****************************************************\n");
printf("**                                                **\n");
printf("**  \xB2  1. Statistics                           **\n");
printf("**                                                **\n");
printf("**  \xB2  2. Insert New Word                      **\n");
printf("**                                                **\n");
printf("**  \xB2  3. Display Dictionary                   **\n");
printf("**                                                **\n");
printf("**  \xB2  4. Search                               **\n");
printf("**                                                **\n");
printf("**  \xB2  5. Quit                                 **\n");
printf("**                                                **\n");
printf("**  \xB2  6. Affichage 2d                         **\n");
printf("**                                                **\n");
printf("**                                                **\n");
printf("****************************************************\n");



 printf("%s",welcome);

    while (choice<=6){


        switch (choice)
        {

        case 1:
            printf("nombre des mots sans redondance :%d\n",dicoNbMotsDifferents(dico));
            printf("nombre des mots total :%d\n",dicoNbMotsTotal(dico));
            break;


        case 2:

            printf("Enter un mot: ");
            scanf("%s", mot);
            strcpy(buffer, mot);
            dicoInsererMot(buffer, &dico);
            break;


        case 3:
            dicoAfficher2(dico);
            break;


        case 4:
            printf("Enter un mot a rechercher: ");
            scanf("%s", mot);
            strcpy(buffer, mot);
            trouverDansDICO(dico, buffer );
            break;
        case 5:
            exit(0);
            break;
        case 6:
        affichageGraphique(dico,2);
        bfs(dico, result, &index); 
        
        break;
        }

         printf("\nEnter your choice: ");

        while (scanf("%d", &choice) == 0 || choice > 6)
        {
            printf("Invalid input. Try again\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        };
    }



    return 0;

}
