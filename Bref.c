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


void generatedata() {}
void ajoutertache(){}
void afficherlestaches(){}
void miseajourtaches() {}
void supprimertaches() {}
void filtrerparpriorite() {}
void ordonnerlestaches() {}
void filtrerparstatus(){}
void stocker() {}
void menu(){}



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
