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
		
		int tmp, som;
		printf("Nombre de sommets reliés au sommet %d \n", i+1);
		scanf("%d", &tmp);
		
		for (j=0; j<tmp; j++){
			printf("Sommet relié à %d \n", i+1);
			scanf("%d", &som);
			mat[i][som] = 1;
		}
		
	}	
	return mat;
}


int main(int argc, char* argv[]){
	
	int nb_sommets, i, j ;
	printf("Voyez entrer les nombre de sommets souhaités : \n");
	scanf("%d", &nb_sommets);
	
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
