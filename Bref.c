#include <stdio.h>

struct Date{
    int jour;
    int mois;
    int annee;
};

struct Tache{
    int id;
    char titre[50];
    char description[50];
    struct Date date;
    char priorite[50];
    char status[50];
    
};

struct Tache tache[100];
int compteur=1;
int taskidcompteur=0;


void generatedata() {}

//ajouter une tache 
void ajoutertache(){

    taskidcompteur++;
    tache[compteur].id=taskidcompteur;
  

    printf("entrez le titre  \n");
    scanf(" %s", tache[compteur].titre);

    printf("entrez la description de la tache  \n");
    scanf(" %s", tache[compteur].description);

    printf("entrez la priorite  \n");
    scanf(" %s", tache[compteur].priorite);

    printf("entrez le jour  \n");
    scanf(" %d", &tache[compteur].date.jour);

    printf("entrez le mois  \n");
    scanf(" %d", &tache[compteur].date.mois);


    printf("entrez l annee  \n");
    scanf("%d", &tache[compteur].date.annee);

    printf("entrez status de la tache  \n");
    scanf(" %s", tache[compteur].status);

    compteur++;

    printf("tache ajoutee avec succees\n");


}

//afficher les taches 
void afficherlestaches(){

        for (int i = 1; i < compteur ; i++)
    {
      printf("------tache id  %d ---------- \n",tache[i].id);
      printf("titre %s \n",tache[i].titre);
      printf("description %s \n",tache[i].description);
      printf("priotite %s \n",tache[i].priorite);
      printf("date echeance  %d-%d-%d \n",tache[i].date.jour,tache[i].date.mois,tache[i].date.annee);
      printf(" %s \n",tache[i].status);

    }


}
void miseajourtaches() {}
void supprimertaches() {}
void filtrerparpriorite() {}
void ordonnerlestaches() {}
void filtrerparstatus(){}
void stocker() {}

 //menu 
void menu(){
    printf("-------------------------task-managment-----------------------------------------------\n");
    printf("  1.ajouter une tache  \n");
    printf("  2.afficher les taches  \n");
    printf("  3.mise a jour une tache  \n");
    printf("  4.supprimer une tache  \n");
    printf("  5.filtrer les tache par priorite  \n");
    printf("  6.ordonner les taches  \n");
    printf("  7.filtrer les tache par status \n");
    printf("  8.stocker dans un fichier texte \n");
    printf("  9.generer pseudo taches  \n");
    printf("  10.quiter le programme \n");
}



int main(){
    
 int choix;
 do
 {    
    menu();
    scanf("%d", &choix); 
    switch (choix)
    {
    case 1 :
        ajoutertache();
        break;
    case 2 :
        afficherlestaches();
        
        break;
    
    case 3 :
       miseajourtaches();
        
        break;
    case 4 :
      supprimertaches();  
        break;
    case 5 :
      filtrerparpriorite();      
        break;
    case 6 :
      ordonnerlestaches();        
        break;
     case 7 :
      filtrerparstatus();     
        break;
     case 8 :
     stocker();      
       break;

     case 9 :
      generatedata();      
       break;
       default:
        printf("choix invalide choisissez entre 1 et 10 \n"); 
        break;
    }
   
 } 
 while (choix!=10);
  return 0;
}
