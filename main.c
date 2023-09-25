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
struct tache add[1000];
int j = 0;

int statadd(int i){
    do{
            printf("\n 1-'a realiser'\n 2-'en cours de realisation'\n 3-'finalisee'\n");
            scanf("%d", &i);
            if (i == 1){
                printf("a realiser\n");
                strcpy(add[j].status, "a realiser");
                }
            else if (i == 2){
                printf("en cours de realisation\n");
                strcpy(add[j].status, "en cours de realisation");
            }
            else if (i == 3){
                printf("finalisee'\n");
                strcpy(add[j].status, "finalisee");
            }
            else
                printf("invalid input\n");
            }while(i<1 || i>3);
}

void ajoute(){

    printf("\033[0;33m***********|Ajouter des nouvelles taches|**********\n\n\033[0m");
    int i;
    int k;
        do{
            printf("|------------------task ID : %d-------------------|\n", j + 1);
            printf("Titre : ");
            add[j].id = j + 1 ;
            scanf(" %[^\n]", add[j].titre);
            statadd(i);
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

    printf("Entrer ID du tache > ");
    scanf("%d",&z);
    for (int x = 0 ; x < j; x++){
        if(add[x].id == z){
            printf("-task        : %s\n", add[x].titre);
            printf("-status      : %s\n", add[x].status);
            printf("-description : %s\n", add[x].des);
            printf("-deadline    : %d/%d/%d\n", add[x].dl_day, add[x].dl_month, add[x].dl_year);

            do{
                    printf("\033[0;31m*****  MODIFICATION  *****\n\n");
            printf("\033[0;32m");// khdr

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
    int i;
        printf("\033[0;33m***********|Modifier la description|**********\n\n\033[0m");
        printf("Nouveau status: ");
        do{
        printf("\n 1-'a realiser' 2-'en cours de realisation' 3-'finalisee' \n");
        scanf("%d", &i);
        if (i == 1){
            printf("a realiser\n");
            strcpy(add[x].status, "a realiser");
            }
        else if (i == 2){
            printf("en cours de realisation\n");
            strcpy(add[x].status, "en cours de realisation");
        }
        else if (i == 3){
            printf("finalisee'\n");
            strcpy(add[x].status, "finalisee");
        }
        else
            printf("invalid input\n");
        }while(i<1 || i>3);
}

void suppr(){
    printf("\033[0;33m***********|Supprimer une tache par identifiant|**********\n\n\033[0m");
}

void tri_alph() {
    struct tache temp;
    int i, j;

    for (i = 0; i < j-1; i++) {
        for (j = i+1; j < j; j++) {
            if (strcmp(add[i].titre, add[j].titre) > 0) {
                temp = add[i];
                add[i] = add[j];
                add[j] = temp;
            }
        }
    }

    printf("Tasks sorted alphabetically.\n");
}

void aff_tache(){
    int m;
    int e;
    printf("\033[0;33m***********|Afficher les taches|**********\n\n\033[0m");
    printf("%d Taches valable\n", j);
    int x=0;
    if (x < add){

    printf("\033[0;33m***********|Liste des taches|**********\n\n\033[0m");

        for (int i = 0; i < j; i++) {
            printf("|------------------task ID : %d-------------------|\n", i + 1);
            printf(">Tache       : %s\n", add[i].titre);
            printf(">Status      : %s\n", add[i].status);
            printf(">Description : %s\n", add[i].des);
            printf(">Deadline    : %d/%d/%d\n", add[i].dl_day, add[i].dl_month, add[i].dl_year);
            printf("--------------------------------------------------\n");
        }
    printf("---------------------------------------------\n");
    printf("1- Tri alpha\n");
    printf("2- Tri deadline\n");
    printf("3- Deadline < 3j ou moins\n");
    printf("0- Exit\n");

    scanf("%d", &m);
    switch (m){
        case 1:
            tri_alph();
            break;
       // case 2://       break;
    }

}


}

void stats(){
    printf("\033[0;33m***********|Statestiques|**********\n\n\033[0m");

}

void menu(){

    printf("\033[0;31m*****  Projet : Gestion de Taches ToDo  *****\n\n");// 7mr
    printf("\033[0;32m");// khdr

    printf("1- [     Ajouter des nouvelles taches.     ]\n");
    printf("2- [   Rechercher et modifier une tache.   ]\n");
    printf("3- [  Supprimer une tache par identifiant. ]\n");
    printf("4- [          Afficher les taches          ]\n");
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
                system("cls");
                aff_tache();
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
