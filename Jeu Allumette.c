#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int nbAllum = 30;
int i;



void afficherAllum()
{
    for (int i = 0; i < nbAllum; i++)
    {
        printf("|");
    }

}

int saisirNombre()
{
    printf("ENTRER UN NOMBRE D'ALLUMETTES: ");
    scanf("%d",&i);
    /*int teste = isdigit(i);

    while (teste==1)
    {
     printf("ta grand mère chois un chiffre") ;
    }
    */
    while (i!=1 && i!=2 && i!=3)
    {
        printf("RE-ENTRER UN NOMBRE D'ALLUMETTES: ");
        scanf("%d",&i);

    }
    while (i>nbAllum)
    {
        printf("RE-ENTRER UN NOMBRE D'ALLUMETTES inférieur au nombre restant: ");
        scanf("%d",&i);
    }
    return i;


}


int saisirNombreAleatoire()
{
    printf("ENTRER UN NOMBRE D'ALLUMETTES: ");
    int i2 = rand() % 3 + 1;
    printf("%d\n", i2);
    return i2;
}


int enleverAllumettes(int allumettes)
{
    nbAllum-=allumettes;
    printf("il y a %d allumettes\n", nbAllum);
}

int TourDeRole(int joueur)
{
    if(joueur == 1)
    {
        joueur = 2;
    }
    else
    {
        joueur =1;
    }



    return joueur;

}
int getNbAllum()
{
    return nbAllum;
}

bool finDeJeu(int nbrestantAllum)
{
    bool continuerAjouer = true;
    if(nbrestantAllum <=1) return !continuerAjouer;
    else
    {

        return continuerAjouer;
    }
}


int modOrdiFacile()
{

}

int LancementOrdiSimple()
{
    int tour = 2;
    while(finDeJeu(getNbAllum()))
    {
        tour= TourDeRole(tour);


        afficherAllum();
        printf("\n");

        printf("joueur %d, a vous de jouer\n",tour );

        if(tour==1)
        {
            enleverAllumettes(saisirNombre());
        }
        else
        {
            enleverAllumettes(saisirNombreAleatoire());
        }


        if(nbAllum == 0 )
        {
            printf("LE JEU EST TERMINEEEEE, le joueur %d à gagné \n", TourDeRole(tour));
            return 0;
        }
        else if (nbAllum == 1)
        {
            printf("LE JEU EST TERMINEEEEE, le joueur %d à gagné \n", tour);
            return 0;
        }

    }
}

void regle_du_jeu()
{
    printf("Vous avez 30 allumettes, et a tour de role vous pouvez en enlever 1, 2 ou 3.\nLe joueur qui enlevera  la derniere allumettes aura perdu\n");
}

int Lancement()
{
    int tour = 2;
    while(finDeJeu(getNbAllum()))
    {
        tour= TourDeRole(tour);


        afficherAllum();
        printf("\n");

        printf("joueur %d, a vous de jouer\n",tour );

        enleverAllumettes(saisirNombre());


    }
    if(nbAllum == 0 || nbAllum == 1)
    {
        printf("LE JEU EST TERMINEEEEE, le joueur %d à gagné \n", tour);
        return 0;
    }
}


void menu()
{

    int choix;

    printf("entrez 1 pour jouer avec un ami \nentrez 2 pour jouer avec un robot(mode: facile)\nentrez 3 pour lire les régles du jeu\nchoix: ");
    scanf("%d", &choix);

    if (choix != 1 && choix!=2 && choix!=3)
    {
        printf("\n");
        printf("il faut entrer 1 ou 2 ou 3\n");
        printf("relancez l'execution\n");
        printf("\n");
        menu();
        printf("\n");
    }

    else if (choix==1)
    {
        Lancement();
    }
    else if (choix==2)
    {
        LancementOrdiSimple();
    }
    else
    {
        regle_du_jeu();
        printf("\n");
        menu();
    }
}


int main()
{
    printf("Bienvenue sur le Jeu Des Allumettes\n");
    printf("\n");
    menu();
}
