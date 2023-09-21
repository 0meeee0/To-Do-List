#include <stdlib.h>
#include <stdio.h>

struct tache{
    int id;
    char titre[20];
    char des[50];
    int dl;
    char status[20];
};
int j = 0;
struct tache add[1000];
void ajoute(){

    printf("\033[0;33m***********|Ajouter des nouvelles taches|**********\n\n\033[0m");

int k;
        do{
            printf("|------------------task ID : %d-------------------|\n", j + 1);
            printf("ash atsmiha : ");
            add[j].id = j + 1 ;
            scanf(" %[^\n]", add[j].titre);
            printf("kidayra : ");
            scanf(" %[^\n]", add[j].status);
            printf("wsfha : ");
            scanf(" %[^\n]", add[j].des);
            printf("imta atsali: ");
            scanf("%d", &add[j].dl);
            printf("-task        : %s\n", add[j].titre);
            printf("-status      : %s\n", add[j].status);
            printf("-description : %s\n", add[j].des);
            printf("-deadline    : %d\n", add[j].dl);
            j++;

            printf("kml wla trjl: ah  1 la 0");
            scanf("%d",&k);
        }while(k);

}

void modif(){
    int zin, mod ;
    printf("\033[0;33m***********|Modifier une tache|**********\n\n\033[0m");

    printf("tmodifi chi 7aja ?\n");
    printf("ktab l ID dial dakshi libaghi tbadal");
    scanf("%d",&zin);
    for (int x = 0 ; x < j; x++){
        if(add[x].id == zin){
            printf("mitsukitayo \n");
            printf("-task        : %s\n", add[x].titre);
            printf("-status      : %s\n", add[x].status);
            printf("-description : %s\n", add[x].des);
            printf("-deadline    : %d\n", add[x].dl);

            do{
                    printf("\033[0;31m*****  MODIFICATION  *****\n\n");
            printf("\033[0;32m");// green

            printf("1- Mofier la discripitiob.\n");
            printf("2- Modifier status.\n");
            printf("3- Modifier le deadline \n");
            printf("0- Malk ?\n");

            printf("\033[0m-----------------------------------------");
            scanf("%d",&mod);
            switch(mod){
            case 1:
                printf("good");
                break;

            }

            }while (mod);
        }
        else
            printf("la \n");
    }


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
    printf("0- Malk ?\n");

    printf("\033[0m-----------------------------------------");  // white
}

int main(){
    int i;

    do{
            menu();
        printf("\nEntrer une du 5 options\n");
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
                printf("mamalish bn8");
        }
    }while(i);
    /*if (i < 1 || i > 5)
        printf("Entrer une du 5 options\n");*/
    return 0;
}
