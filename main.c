#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct date {
    int dl_day;
    int dl_month;
    int dl_year;
};
struct tache{
    int id;
    char titre[20];
    char des[100];
   struct date deadline;
    char status[20];
    int days;
};
struct tache add[1000];
int j = 0;
int comp = 0;
int incomp = 0;

int statadd(int i){
    do{
            printf("\n 1-'a realiser'\n 2-'en cours de realisation'\n 3-'finalisee'\n");
            scanf("%d", &i);
            if (i == 1){
                printf("a realiser\n");
                strcpy(add[j].status, "a realiser");
                incomp++;
                }
            else if (i == 2){
                printf("en cours de realisation\n");
                strcpy(add[j].status, "en cours de realisation");
                incomp++;
            }
            else if (i == 3){
                printf("finalisee'\n");
                strcpy(add[j].status, "finalisee");
                comp++;
            }
            else
                printf("invalid input\n");
            }while(i<1 || i>3);
}
int timecalc(int a, int b, int c)
{
    time_t tt = time(NULL);
    struct tm *dt = localtime(&tt);
    int jour = dt->tm_mday;
    int mois = dt->tm_mon + 1;
    int anne = dt->tm_year + 1900;

    int y = anne - a;
    int m;
    if (mois - b <= 0 && y >= 1)
    {
        y--;
        b += 12;
    }
    m = mois - b;
    int d;
    if (jour - c < 0 && m >= 1)
    {
        m--;
        c += 30;
    }
    d = jour - c;
    int days = -(d + m * 30 + y * 365);
    return days;
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
            scanf("%d %d %d", &add[j].deadline.dl_day, &add[j].deadline.dl_month, &add[j].deadline.dl_year);
            add[j].days = timecalc(add[j].deadline.dl_year, add[j].deadline.dl_month, add[j].deadline.dl_day);
            printf("--------------------------------------------------\n");
            printf(">Tache       : %s\n", add[j].titre);
            printf(">Status      : %s\n", add[j].status);
            printf(">Description : %s\n", add[j].des);
            printf(">Deadline    : %d/%d/%d\n", add[j].deadline.dl_day, add[j].deadline.dl_month, add[j].deadline.dl_year);
            printf("--------------------------------------------------\n");
            j++;

            printf("Entrer une nouvelle tache ?\n(oui:1 non:0) > ");
            scanf("%d",&k);
        }while(k != 0);

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
        printf("\033[0;33m***********|Modifier le status|**********\n\n\033[0m");
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
void modif_dl(int x){
    printf("\033[0;33m***********|Modifier le deadline|**********\n\n\033[0m");
    printf("\nNouveau deadline (jj mm aa): ");
    scanf("%d %d %d", &add[x].deadline.dl_day, &add[x].deadline.dl_month, &add[x].deadline.dl_year);
    add[x].days = timecalc(add[x].deadline.dl_year, add[x].deadline.dl_month, add[x].deadline.dl_day);

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
            printf("-deadline    : %d/%d/%d\n", add[x].deadline.dl_day, add[x].deadline.dl_month, add[x].deadline.dl_year);

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
            case 3:
                modif_dl(x);
                break;
            }

            }while (mod);
        }
        else
            printf("la \n");
    }

}

void suppr(int id){
    int del = 0;
    for(int i = 0; i < j; i++){
        if(id == add[i].id){
            del = 1;
            if (strcmp(add[i].status, "finalisee") == 0) {
                comp--;
            } else {
                incomp--;
            }
            for(int x = i; x < j; x++){
                add[x] = add[x + 1];
            }
        }
    }
    if(del)
        j--;

    printf("suprimer avec success\n");
}

void tri_alph() {
    struct tache temp;
    int found = 1;
    int x = 0;
    while(found){
        found = 0;
        x = 0;
        while(x < j - 1){
            if((add[x].titre[0] - add[x + 1].titre[0]) > 0){
                found = 1;
                temp = add[x];
                add[x] = add[x + 1];
                add[x + 1] = temp;
            }
            x++;
        }
    }
}
void tridl(){
    struct tache temp;
    int swaped = 1;
    int l = 0;
    while(swaped){
        swaped = 0;
        l = 0;
        while(l < j -1){
            if(add[l].days > add[l + 1].days){
                swaped = 1;
                temp = add[l];
                add[l] = add[l + 1];
                add[l + 1] = temp;
            }
            l++;
        }
    }
}
void troij()
{
    int b;
    for (int i = 0; i < j; i++)
    {
        if (add[i].days <= 3)
        {
            printf("|------------------task ID : %d-------------------|\n", add[i].id );
            printf(">Tache       : %s\n", add[i].titre);
            printf(">Status      : %s\n", add[i].status);
            printf(">Description : %s\n", add[i].des);
            printf(">Deadline    : %d/%d/%d\n", add[i].deadline.dl_day, add[i].deadline.dl_month, add[i].deadline.dl_year);
            printf("--------------------------------------------------\n");
        }

    }
    scanf("%d", &b);
}
void aff_tache(){
    int m;
    int e;
    int x = 0;
    if (x < j){

    printf("\033[0;33m***********|Liste des taches|**********\n\n\033[0m");

        for (int i = 0; i < j; i++) {
            printf("|------------------task ID : %d-------------------|\n", add[i].id );
            printf(">Tache       : %s\n", add[i].titre);
            printf(">Status      : %s\n", add[i].status);
            printf(">Description : %s\n", add[i].des);
            printf(">Deadline    : %d/%d/%d\n", add[i].deadline.dl_day, add[i].deadline.dl_month, add[i].deadline.dl_year);
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
       case 2:
            tridl();
            break;
        case 3:
            troij();

        }
    }
}

void stats(){
    int y;

    printf("\033[0;33m***********|Statestiques|**********\n\n\033[0m");
    printf("Nombre de taches: %d\n", j);
    printf("Nombre de taches completes: %d\n", comp);
    printf("Nombre de taches incompletes: %d\n", incomp);
    for (int i = 0; i < j; i++) {
            printf("|------------------task ID : %d-------------------|\n", add[i].id );
            printf(">Tache           : %s\n", add[i].titre);
            printf(">Status          : %s\n", add[i].status);
            printf(">Description     : %s\n", add[i].des);
            printf(">Deadline        : %d/%d/%d\n", add[i].deadline.dl_day, add[i].deadline.dl_month, add[i].deadline.dl_year);
            printf(">Jours restants  : %d\n", add[i].days);
            printf("--------------------------------------------------\n");
        }
    scanf("%d", &y);
}

void menu(){

    printf("\033[0;31m*****  Projet : Gestion de Taches ToDo  *****\n\n");
    printf("\033[0;32m");

    printf("1- [     Ajouter des nouvelles taches.     ]\n");
    printf("2- [   Rechercher et modifier une tache.   ]\n");
    printf("3- [  Supprimer une tache par identifiant. ]\n");
    printf("4- [          Afficher les taches          ]\n");
    printf("5- [             Statestiques.             ]\n");
    printf("0- [                  EXIT                 ]\n");

    printf("\033[0m   -----------------------------------------\n");
}

int main(){
    int i;

    int y;
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
                system("cls");
                printf("\033[0;33m***********|Supprimer une tache|**********\n\n\033[0m");
                printf("Enter ID \n");
                scanf("%d",&y);
                suppr(y);
                break;
            case 4:
                system("cls");
                aff_tache();
                break;
            case 5:
                system("cls");
                stats();
                break;
        }
    }while(i != 0);
    return 0;
}
