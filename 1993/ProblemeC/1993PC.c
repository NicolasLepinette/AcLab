#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct noeud {
	int capaciteAncetre; 
	int capaciteDescendant; 
	int nombreDescendant; 
	int nombreAncetre;
	int index;
	int *poids;
	struct noeud **ancetre
	struct noeud **desc; 
	char *nom;
} NOEUD;

NOEUD *creer_noeud(char *nom){
	int i;
	NOEUD *noeud;
	noeud = malloc(1, sizeof(NOEUD)); noeud->name = malloc(6*sizeof(char)); for(i=0;i<6;i++) noeud->nom[i]=nom[i];
	NOEUD **descendant;
	descendant = malloc(5, sizeof(NOEUD)); noeud->descendant=descendant;
	NOEUD **ancetre;
	ancetre = malloc(5, sizeof(NOEUD)); noeud->ancetre = ancetre;
	noeud->nombredDescendant = 0; 
	noeud->nombreAncetre=0; 
	noeud->capaciteAncetre=5;
	noeud->capaciteDescendant=5;
	noeud->poids=malloc(noeud->capaciteAncetre,sizeof(int)); for(i=0;i<noeud->capaciteAncetre;i++) noeud->poids[i]=0;
    return noeud;
}


void liberer_memoire_noeud(NOEUD *n){ 
	free(n->nom); 
	for(int i=0;i<n->nombredDescendant;i++){
		free(n->descendant[i]); 
	}

	free(n->descendant);
	for(int i=0;i<n->nombreAncetre;i++){ 
		free(n->ancetre);
	}

	free(n->ancetre); 
	free(n->poids);
	free(n); 
}
