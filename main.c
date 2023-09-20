#include <stdlib.h>
#include <stdio.h>

struct tache{
    int id;
    char titre[20];
    char des[50];
    int dl;
    char status[20];
};

void ajoute(){
//    int i;
//    struct tache add[i];
    printf("\033[0;33m***********|Ajouter des nouvelles taches|**********\n\n\033[0m");


    printf("Combien de tache ?");

}
void modif(){
    printf("\033[0;33m***********|Modifier une tache|**********\n\n\033[0m");
}

void suppr(){
    printf("\033[0;33m***********|Supprimer une tache par identifiant|**********\n\n\033[0m");
}

void srch(){
    printf("\033[0;33m***********|Rechercher les taches|**********\n\n\033[0m");

}

void stats(){
    printf("\033[0;33m***********|Statestiques|**********\n\n\033[0m");

}

void menu(){

    printf("\033[0;31m*****  Projet : Gestion de Taches ToDo  *****\n\n");
    printf("\033[0;32m");// green

    printf("1- Ajouter des nouvelles taches.\n");
    printf("2- Modifier une tache.\n");
    printf("3- Supprimer une tache par identifiant.\n");
    printf("4- Rechercher des taches.\n");
    printf("5- Statestiques.\n");

    printf("\033[0m-----------------------------------------");  // white
}

int main(){
    int i;
        menu();
        printf("\nEntrer une du 5 options\n");
    do{
        scanf("%d",&i);

        switch (i){
            case 1:
                ajoute();
                break ;
            case 2:
                modif();
                break;
            case 3:
                suppr();
                break;
            case 4:
                srch();
                break;
            case 5:
                stats();
                break;
            default :
                printf("shi wa7d fihom");
        }
    }while(i);
    /*if (i < 1 || i > 5)
        printf("Entrer une du 5 options\n");*/
    return 0;
}
