#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int nbAllum = 30;
int i;



void afficherAllum(){
     for (int i = 0; i < nbAllum; i++)
     {
         printf("|");
     }
     
}

int saisirNombre(){
     printf("ENTRER UN NOMBRE D'ALLUMETTES: ");
     scanf("%d",&i);
     
     
     if ( i<1|| i>3){ 
     printf("RE-ENTRER UN NOMBRE D'ALLUMETTES: ");
     scanf("%d",&i);
     return i;
      }
    
      else{
          return i;
           

      }

}
int saisirNombreAleatoire(){
    
     
   
     printf("ENTRER UN NOMBRE D'ALLUMETTES: ");
    int i2 = rand() % 3 + 1;
    printf("%d\n", i2);
     return i2;

      
    


}



int enleverAllumettes(int allumettes){
    
          nbAllum-=allumettes;
     printf("il y a %d allumettes\n", nbAllum);
     
}

int TourDeRole(int joueur){
    
     if(joueur == 1){
          joueur = 2;
     }
     else {
          joueur =1;
          
     }
     


     return joueur;

}
int getNbAllum(){
     return nbAllum;
}

bool finDeJeu(int nbrestantAllum){
     bool continuerAjouer = true;
     if(nbrestantAllum <=1) return !continuerAjouer;
     else  {
        
          return continuerAjouer;
     }
}


int modOrdiFacile(){
     
}

int LancementOrdiSimple(){
     int tour = 2;
     while(finDeJeu(getNbAllum())){
     tour= TourDeRole(tour);


     afficherAllum();
     printf("\n");

     printf("joueur %d, a vous de jouer\n",tour );
     
     if(tour==1){
     enleverAllumettes(saisirNombre());
     }
     else{
          enleverAllumettes(saisirNombreAleatoire());
     }

     
     if(nbAllum == 0 || nbAllum == 1){
          printf("LE JEU EST TERMINEEEEE, le joueur %d à gagné \n" , tour);
          return 0;
     }
     }
}

int Lancement(){
     int tour = 2;
     while(finDeJeu(getNbAllum())){
     tour= TourDeRole(tour);


     afficherAllum();
     printf("\n");

     printf("joueur %d, a vous de jouer\n",tour );
     
     enleverAllumettes(saisirNombre());
     

     }
     if(nbAllum == 0 || nbAllum == 1){
          printf("LE JEU EST TERMINEEEEE, le joueur %d à gagné \n" , tour);
          return 0;
     }
}



int main(){

    LancementOrdiSimple();
}