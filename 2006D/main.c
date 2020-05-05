#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_ZEROS 10
#define CHAINE 1000

int main(){
    FILE* fichier = NULL;
    int decimal = 1000000000;
    int tab[MAX_ZEROS];
    int modul,nb1,nb2,cpt_nb1,cpt_nb2,arret = 0;
    int i,j,k,data;
    char buff[CHAINE];
    fichier = fopen("bipartite.in.txt","r");
    if(fichier == NULL){
        printf("pas de fichier\n");
        return EXIT_FAILURE;
    }
    while(fgets(buff,CHAINE,fichier) != NULL){
        data = atoi(buff);
        if(data != 0){
            for(j = 1;arret == 0;j++){
                modul = data * j;
                for(k =0;k < MAX_ZEROS;k++){
                    tab[k] = modul / decimal;
                    modul = modul % decimal;
                    decimal = decimal / 10;
                }
                decimal = 1000000000;
                for(i = 0;i < MAX_ZEROS;i++){
                    arret = 1;
                    if(tab[i] != 0 && nb1 == 0)
                        nb1 = tab[i];
                    if(tab[i] != nb1 && cpt_nb2 == 0)
                        nb2 = tab[i];
                    if(tab[i] == nb1 && nb1 != 0)
                        cpt_nb1++;
                    if(tab[i] == nb2 && nb1 != 0)
                        cpt_nb2++;
                    if(tab[i] != nb1 && tab[i] != nb2){
                        arret = 0;
                        nb1 = 0;
                        nb2 = 0;
                        cpt_nb1 = 0;
                        cpt_nb2 = 0;
                        break;
                    }
                }
            }
            printf("%d: %d %d %d %d\n",data,cpt_nb1,nb1,cpt_nb2,nb2);
        }
            nb1 = 0;
            nb2 = 0;
            cpt_nb1 = 0;
            cpt_nb2 = 0;
            modul=0;
            arret=0;
    }
    return EXIT_SUCCESS;
}
