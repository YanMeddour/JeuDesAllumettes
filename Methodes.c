#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int nbAllum = 30;

void afficherAllum()
{
     for (int i = 0; i < nbAllum; i++)
     {
          printf("|");
     }
     printf("\n");
}

int is_valid(char *number, int min, int max)
{
     int size = (int)strlen(number);

     for (int i = 0; i < size; ++i)
     {
          if (isdigit(*(number + i)) == 0)
               return -1;
     }

     int numberInt = (int)atoi(number);

     if (numberInt < min || numberInt > max)
          return -1;

     return numberInt;
}

int saisirNombre()
{
     char i[100];

     do
     {
          printf("ENTREZ UN NOMBRE D'ALLUMETTES: ");

          scanf("%s", i);

     } while (is_valid(i, 1, 3) == -1);
     // while (i < 1 || i > 3)
     // {
     //      printf("RE-ENTRER UN NOMBRE D'ALLUMETTES: ");
     //      scanf("%d", &i);

     // }
     // while (i > nbAllum)
     // {
     //      printf("RE-ENTRER UN NOMBRE D'ALLUMETTES inférieur au nombre restant: ");
     //      scanf("%d", &i);
     // }
     return is_valid(i, 1, 3);
}
void regle_du_jeu()
{
     printf("Vous avez 30 allumettes, et a tour de role vous pouvez en enlever 1, 2 ou 3.\nLe joueur qui enlevera  la derniere allumettes aura perdu\n");
}

void Lancement(){

}
void LancementOrdiSimple()
{

int tour = 2;
     while (finDeJeu(getNbAllum()))
     {
tour = TourDeRole(tour);

          afficherAllum();
          printf("\n");

          printf("JOUEUR %d, a vous de jouer\n", tour);

          if (tour == 1)
          {
               enleverAllumettes(saisirNombre());
          }
          else
          {
               enleverAllumettes(saisirNombreAleatoire());
          }

          if (nbAllum == 0 || nbAllum == 1)
          {
               printf("LE JEU EST TERMINEEEEE, le joueur %d à gagné \n", TourDeRole(tour));
          }
        
     }
   exit;
}


void menu()
{

     int choix;

     printf("entrez 1 pour jouer avec un ami \nentrez 2 pour jouer avec un robot(mode: facile)\nentrez 3 pour quitter le jeu\nentrez 4 pour lire les régles du jeu\nchoix: ");
     scanf("%d", &choix);

     if (choix != 1 && choix != 2 && choix != 3)
     {
          printf("\n");
          printf("il faut entrer 1 ou 2 ou 3\n");
          printf("relancez l'execution\n");
          printf("\n");
          menu();
          printf("\n");
     }

     else if (choix == 1)
     {
          Lancement();
     }
     else if (choix == 2)
     {
          LancementOrdiSimple();
     }
     else if(choix ==  3){
          exit;

     }
     else
     {
          regle_du_jeu();
          printf("\n");
          menu();
     }
}

bool finDeJeu(int nbrestantAllum)
{

     bool continuerAjouer = true;
     if (nbrestantAllum <= 1)
          return !continuerAjouer;
     else
     {

          return continuerAjouer;
     }
}

int enleverAllumettes(int allumettes)
{

     nbAllum -= allumettes;
     printf("il y a %d allumettes\n", nbAllum);
     return allumettes;
}
