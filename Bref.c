#include <stdio.h>
#include<string.h>

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
//fonction mettre a jour tache  
void miseajourtaches() {
    int idRecherche;
    int t = 0; // indice pour dire que la tache est trouvee

    printf("Entrez id  de la tache que vous voulez  mettre a jour : ");
    scanf("%d", &idRecherche);

    for (int i = 1; i < compteur; i++) {
        if (tache[i].id == idRecherche) {
            t = 1;

            //
            printf("tache trouvee :\n");
            printf("id : %d\n", tache[i].id);
            printf("titre : %s\n", tache[i].titre);
            printf("description : %s\n", tache[i].description);
            printf("priorite : %s\n", tache[i].priorite);
            printf("date : %02d/%02d/%04d\n", tache[i].date.jour, tache[i].date.mois, tache[i].date.annee);
            printf("status : %s\n", tache[i].status);

        
            printf("entrez le nouveau titre (actuel : %s) : ", tache[i].titre);
            scanf(" %s", tache[i].titre);

            printf("entrez la nouvelle description (actuelle : %s) : ", tache[i].description);
            scanf(" %s", tache[i].description);

            printf("entrez la nouvelle priorite (actuelle : %s) : ", tache[i].priorite);
            scanf(" %s", tache[i].priorite);

            printf("entrez le nouveau jour (actuel : %d) : ", tache[i].date.jour);
            scanf("%d", &tache[i].date.jour);

            printf("entrez le nouveau mois (actuel : %d) : ", tache[i].date.mois);
            scanf("%d", &tache[i].date.mois);

            printf("entrez la nouvelle annee (actuelle : %d) : ", tache[i].date.annee);
            scanf("%d", &tache[i].date.annee);

            printf("entrez le nouveau status (actuel : %s) : ", tache[i].status);
            scanf(" %s", tache[i].status);

            printf("La tache est mise a jour !\n");
            break;
        }
    }

    if (!t) {
        printf("Aucune tache avec l'id  %d  \n", idRecherche);
    }
}

// fonction supprimee  
void supprimertaches() {
    int idRecherche;
    int t = 0;
    printf("entrez l'id de la tache que vous voulez supprimer : ");
    scanf("%d", &idRecherche);

    for (int i = 1; i < compteur; i++) {
        if (tache[i].id == idRecherche) {
            t= 1;

            printf("tache trouvee:\n");
            printf("id : %d\n", tache[i].id);
            printf("titre : %s\n", tache[i].titre);
            printf("description : %s\n", tache[i].description);
            printf("priorite : %s\n", tache[i].priorite);
            printf("date : %d/%d/%d\n", tache[i].date.jour, tache[i].date.mois, tache[i].date.annee);
            printf("status : %s\n", tache[i].status);

            
            for (int j = i; j < compteur - 1; j++) {
                tache[j] = tache[j + 1]; 
            }
            compteur--;
            printf("La tache est supprimee !\n");
            break;
        }
    }

    if (!t) {
        printf("Aucune tache avec l'Id %d n'a ete trouvee.\n", idRecherche);
    }
}

//fonction filtrer par priorite 
void  filtrerparpriorite() {
    char priorite[50];

    printf("Entrez une priorité : \n");
    scanf("%s", priorite);

    for (int i = 0; i < compteur; i++) {  

        if (strcmp(tache[i].priorite, priorite) == 0) {  
            printf("------Tâche ID %d ---------- \n", tache[i].id);
            printf("Titre: %s \n", tache[i].titre);
            printf("Description: %s \n", tache[i].description);
            printf("Priorité: %s \n", tache[i].priorite);
            printf("Date d'échéance: %d-%d-%d \n", tache[i].date.jour, tache[i].date.mois, tache[i].date.annee);
            printf("Statut: %s \n", tache[i].status);
        }
    }
}

//fonction filtrer par status 
void  filtrerparstatus(){  
    char status[50];
    printf("entrez le status completed/uncompleted : \n");
    scanf("%s", status);

    for (int i = 0; i < compteur; i++) {  

        if (strcmp(tache[i].status, status) == 0) {  
            printf("------tache ID %d ---------- \n", tache[i].id);
            printf("titre: %s \n", tache[i].titre);
            printf("description: %s \n", tache[i].description);
            printf("priorité: %s \n", tache[i].priorite);
            printf("date d'échéance: %d-%d-%d \n", tache[i].date.jour, tache[i].date.mois, tache[i].date.annee);
            printf("statut: %s \n", tache[i].status);
        }
    }

}   

//fonction stocker  
void stocker() {}
void ordonnerlestaches() {}



 //menu 
void menu(){
    printf("----------------------------task-managment---------------------------------------------\n");
    printf("  1.ajouter une tache  \n");
    printf("  2.afficher les taches  \n");
    printf("  3.mise a jour une tache  \n");
    printf("  4.supprimer une tache  \n");
    printf("  5.filtrer les tache par priorite \n");
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
