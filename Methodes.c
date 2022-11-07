#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int nbAllum = 30;



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