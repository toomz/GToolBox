#include <stdio.h>
#include <stdlib.h>
//#include <matrice.h>

int** create_mat(int nb_som) {
	
	int ** mat = malloc( nb_som*sizeof(int*) );
	int i, j ;
	
	// Initialisation de la matrice à 0
	for(i=0; i<nb_som; i++){
		mat[i] = malloc( nb_som*sizeof(int*) );
		for(j=0; j<nb_som; j++){
			mat[i][j] = 0 ;
		}
	}
	
	// Remplissage de la matrice 
	for(i=0; i<nb_som; i++){
		
		int tmp = 0;
		int som = 0;
		while((tmp == 0) || (tmp < 0)){
			printf("Nombre de sommets reliés au sommet %d \n", i+1);
			scanf("%d", &tmp);
			if (tmp < 0)
				fprintf(stderr, "Problème, nombre de sommets négatif...");
		}
				
		for (j=0; j<tmp; j++){
			while((som == 0) || (som > nb_som) || (som < 0)){
				printf("Sommet relié à %d \n", i+1);
				scanf("%d", &som);
				if (tmp < 0)
				fprintf(stderr, "Ce sommet n'existe pas...");
			}
			mat[i][som] = 1;
		}
		
	}	
	return mat;
}



void supprimer_arete(int **matrice, int sommet1, int sommet2 ){
	matrice[sommet1][sommet2]=0;
	matrice[sommet2][sommet1]=0;
	return;
}

void ajouter_arete(int **matrice, int sommet1, int sommet2, int nb ){
	matrice[sommet1][sommet2]=nb;
	matrice[sommet2][sommet1]=nb;
	return;
}

int lecture_arete(int **matrice, int sommet1, int sommet2){
	return(matrice[sommet1][sommet2]);
}



int main(int argc, char* argv[]){
	
	int nb_sommets = 0;
	int i, j ;
	while((nb_sommets == 0) || (nb_sommets < 0)){
		printf("Voyez entrer les nombre de sommets souhaités : \n");
		scanf("%d", &nb_sommets);
		if(nb_sommets < 0){
			fprintf(stderr, "Le nombre de sommets ne peut pas être négatif...");
		}
	}
	
	int **matrice = NULL ;
	matrice = create_mat(nb_sommets);
	
	
	for(i=0; i<nb_sommets; i++){
		for(j=0; j<nb_sommets; j++){
			printf("%d", matrice[i][j]);
		}
		printf("\n");
	}
	
	
	return 0 ;
}
