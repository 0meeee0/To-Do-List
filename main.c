#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tache{
    int id;
    char titre[20];
    char des[100];
    int dl_day;
    int dl_month;
    int dl_year;
    char status[20];
};
int j = 0;
struct tache add[1000];
void ajoute(){

    printf("\033[0;33m***********|Ajouter des nouvelles taches|**********\n\n\033[0m");

    int k;
        do{
            printf("|------------------task ID : %d-------------------|\n", j + 1);
            printf("Titre : ");
            add[j].id = j + 1 ;
            scanf(" %[^\n]", add[j].titre);
            printf("Status : ");
            scanf(" %[^\n]", add[j].status);
            printf("Description: ");
            scanf(" %[^\n]", add[j].des);
            printf("Deadline (jj mm aa): ");
            scanf("%d %d %d", &add[j].dl_day, &add[j].dl_month, &add[j].dl_year);
            printf("--------------------------------------------------\n");
            printf(">Tache       : %s\n", add[j].titre);
            printf(">Status      : %s\n", add[j].status);
            printf(">Description : %s\n", add[j].des);
            printf(">Deadline    : %d/%d/%d\n", add[j].dl_day, add[j].dl_month, add[j].dl_year);
            printf("--------------------------------------------------\n");
            j++;

            printf("Entrer une nouvelle tache ?\n(oui:1 non:0) > ");
            scanf("%d",&k);
        }while(k);

}

void modif(){
    int z, mod ;
    printf("\033[0;33m***********|Modifier une tache|**********\n\n\033[0m");

    printf("Entrer ID du tache a modifier > ");
    scanf("%d",&z);
    for (int x = 0 ; x < j; x++){
        if(add[x].id == z){
            printf("-task        : %s\n", add[x].titre);
            printf("-status      : %s\n", add[x].status);
            printf("-description : %s\n", add[x].des);
            printf("-deadline    : %d/%d/%d\n", add[x].dl_day, add[x].dl_month, add[x].dl_year);

            do{
                    printf("\033[0;31m*****  MODIFICATION  *****\n\n");
            printf("\033[0;32m");// green

            printf("1- Modifier la description.\n");
            printf("2- Modifier status.\n");
            printf("3- Modifier le deadline \n");
            printf("0- Malk ?\n");

            printf("\033[0m-----------------------------------------\n");
            scanf("%d",&mod);
            switch(mod){
            case 1:
                modif_des(x);
                break;
            case 2:
                modif_stat(x);
                break;
            //case 3:
            //    modif_dl(x);
            //    break;
            }

            }while (mod);
        }
        else
            printf("la \n");
    }


}

void modif_des(int x){
    char n[100];
        printf("\033[0;33m***********|Modifier la description|**********\n\n\033[0m");
        printf("Nouvelle description: ");
        scanf(" %[^\n]",n);
        strcpy(add[x].des,n);
}
void modif_stat(int x){
    char n[100];
        printf("\033[0;33m***********|Modifier la description|**********\n\n\033[0m");
        printf("Nouveau status: ");
        scanf(" %[^\n]",n);
        strcpy(add[x].status,n);
}
/*void modif_dl(int x){
    char n[100];
        printf("\033[0;33m***********|Modifier la description|**********\n\n\033[0m");
        printf("ara deadline jdida: ");
        scanf(" %[^\n]",n);
        strcpy(add[x].dl,n);

}*/

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

    printf("\033[0;31m*****  Projet : Gestion de Taches ToDo  *****\n\n");// 7mr
    printf("\033[0;32m");// khdr

    printf("1- [     Ajouter des nouvelles taches.     ]\n");
    printf("2- [          Modifier une tache.          ]\n");
    printf("3- [  Supprimer une tache par identifiant. ]\n");
    printf("4- [        Rechercher des taches.         ]\n");
    printf("5- [             Statestiques.             ]\n");
    printf("0- [                  EXIT                 ]\n");

    printf("\033[0m   -----------------------------------------\n");  // byd
}

int main(){
    int i;

    do{
            system("cls");
            menu();
        printf("\nEntrer une du 5 options\n");
        scanf("%d",&i);

        switch (i){
            case 1:
                system("cls");
                ajoute();
                break ;
            case 2:
                system("cls");
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
                printf("bslama");
        }
    }while(i);
    /*if (i < 1 || i > 5)
        printf("Entrer une du 5 options\n");*/
    return 0;
}
