#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

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



//ajouter une tache 
void ajoutertache(){

    taskidcompteur++;
    tache[compteur].id=taskidcompteur;
  
    printf("entrez le titre : ");
    scanf(" %[^\n]", tache[compteur].titre);

    printf("entrez la description de la tache :");
    scanf(" %[^\n]", tache[compteur].description);

    printf("entrez la priorite high/low :");
    scanf(" %[^\n]", tache[compteur].priorite);

    printf("entrez le jour :");
    scanf(" %d", &tache[compteur].date.jour);

    printf("entrez le mois :");
    scanf(" %d", &tache[compteur].date.mois);


    printf("entrez l'annee :");
    scanf(" %d", &tache[compteur].date.annee);

    printf("entrez status de la tache complete / incomplete :");
    scanf(" %[^\n]", tache[compteur].status);

    compteur++;

    printf("tache ajoutee avec succees\n");

}

//afficher les taches 
void afficherlestaches(){

        for (int i = 1; i < compteur ; i++)
    {
      printf("============tache id  %d=============== \n",tache[i].id);
      printf("titre : %s \n",tache[i].titre);
      printf("description : %s \n",tache[i].description);
      printf("priotite : %s \n",tache[i].priorite);
      printf("date echeance : %d-%d-%d \n",tache[i].date.jour,tache[i].date.mois,tache[i].date.annee);
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
            printf("======Tache trouvee=========== :\n");
            printf("id : %d\n", tache[i].id);
            printf("titre : %s\n", tache[i].titre);
            printf("description : %s\n", tache[i].description);
            printf("priorite : %s\n", tache[i].priorite);
            printf("date : %02d/%02d/%04d\n", tache[i].date.jour, tache[i].date.mois, tache[i].date.annee);
            printf("status : %s\n", tache[i].status);

        
            printf("entrez le nouveau titre (actuel : %s) : ", tache[i].titre);
            scanf(" %[^\n]", tache[i].titre);

            printf("entrez la nouvelle description (actuelle : %s) : ", tache[i].description);
            scanf(" %[^\n]", tache[i].description);

            printf("entrez la nouvelle priorite (actuelle : %s) : ", tache[i].priorite);
            scanf(" %s", tache[i].priorite);

            printf("entrez le nouveau jour (actuel : %d) : ", tache[i].date.jour);
            scanf(" %d", &tache[i].date.jour);

            printf("entrez le nouveau mois (actuel : %d) : ", tache[i].date.mois);
            scanf("%d", &tache[i].date.mois);

            printf("entrez la nouvelle annee (actuelle : %d) : ", tache[i].date.annee);
            scanf("%d", &tache[i].date.annee);

            printf("entrez le nouveau status (actuel : %s) : ", tache[i].status);
            scanf(" %[^\n]", tache[i].status);

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
    int t = 0;   // i 
    printf("entrez l'id de la tache que vous voulez supprimer : ");
    scanf("%d", &idRecherche);

    for (int i = 1; i < compteur; i++) {
        if (tache[i].id == idRecherche) {
            t= 1;

            printf("==========Tache trouvee=============:\n");
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
            printf("================Tâche ID %d ================= \n", tache[i].id);
            printf("Titre: %s \n", tache[i].titre);
            printf("Description: %s \n", tache[i].description);
            printf("Priorité: %s \n", tache[i].priorite);
            printf("Date d'échéance: %d-%d-%d \n", tache[i].date.jour, tache[i].date.mois, tache[i].date.annee);
            printf("Statut: %s \n", tache[i].status);
        }
    }
}


//ordonner les taches
void ordonnerlestaches() {
    printf("cette fonctionalité sera disponible dans les prochaines versions \n");
}

//fonction filtrer par status 
void  filtrerparstatus(){  
    char status[50];
    printf("entrez le status completed/incompleted : \n");
    scanf("%s", status);

    for (int i = 0; i < compteur; i++) {  

        if (strcmp(tache[i].status, status) == 0) {  
            printf("============tache ID %d============== \n", tache[i].id);
            printf("titre: %s \n", tache[i].titre);
            printf("description: %s \n", tache[i].description);
            printf("priorité: %s \n", tache[i].priorite);
            printf("date d'échéance: %d-%d-%d \n", tache[i].date.jour, tache[i].date.mois, tache[i].date.annee);
            printf("statut: %s \n", tache[i].status);
        }
    }

}   




//generer des pseudo taches pour tester l'application 
void generatedata() {
    int nombreDeTaches;
    printf("Entrez nbre tache que vous voulez ajouter \n");
    scanf("%d", &nombreDeTaches);
    srand(time(NULL)); 

    for (int i = 0; i < nombreDeTaches; i++) {
        taskidcompteur++;
        tache[compteur].id = taskidcompteur;
        
   
        sprintf(tache[compteur].titre, "Tache_%d", taskidcompteur);
   
        sprintf(tache[compteur].description, "Description_%d", taskidcompteur);
   
        char* priorites[] = {"high", "low"};
        strcpy(tache[compteur].priorite, priorites[rand() % 2]);

      
        tache[compteur].date.jour = rand() % 28 + 1; 
        tache[compteur].date.mois = rand() % 12 + 1; 
        tache[compteur].date.annee = 2024 + rand() % 5; 
  
        char* status[] = {"complete", "incomplete"};
        strcpy(tache[compteur].status, status[rand() % 2]);

        compteur++;
    }

    printf("%d taches generee avec succes\n", nombreDeTaches);
}

// Fonction pour enregistrer les taches 
void stocker() {
    FILE *fichier = fopen("tache.txt", "w");  
    if (fichier == NULL) {
        printf("erreur d ouvrir le fichier.\n");
        return;
    }

    for (int i = 1; i < compteur; i++) {
        fprintf(fichier, "==============tache id %d ==================\n", tache[i].id);
        fprintf(fichier, "titre : %s\n", tache[i].titre);
        fprintf(fichier, "description : %s\n", tache[i].description);
        fprintf(fichier, "priorité : %s\n", tache[i].priorite);
        fprintf(fichier, "date échéance : %d-%d-%d\n", tache[i].date.jour, tache[i].date.mois, tache[i].date.annee);
        fprintf(fichier, "statut : %s\n\n", tache[i].status);
    }

    fclose(fichier);  
    printf("Les tâches est enregistrer  dans le fichier tache.txt.\n");
}



 //menu 
void menu(){
    printf("======================Task-management==================================\n");
    printf("  1.Ajouter une tache  \n");
    printf("  2.Afficher les taches  \n");
    printf("  3.Mise a jour une tache  \n");
    printf("  4.Supprimer une tache  \n");
    printf("  5.Filtrer les taches par priorite \n");
    printf("  6.Ordonner les taches  \n");
    printf("  7.Filtrer les taches par status \n");
    printf("  8.Stocker dans un fichier texte \n");
    printf("  9.Generer pseudo taches  \n");
    printf("  10.Effacer l'ecran  \n");
    printf("  11.Quitter le programme \n");
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

     case 10 :
      system("cls");      
       break;
       default:
        printf("choix invalide choisissez entre 1 et 10 \n"); 
        break;
    }
   
 } 
 while (choix!=11);
  return 0;
}
