#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	int nb_sommets ;
	printf("Voyez entrer les nombre de sommets souhaités : \n");
	scanf("%d", &nb_sommets);
	
	int matrice[nb_sommets][nb_sommets] ;
	int i, j ;
	
	for(i=0; i<nb_sommets; i++){
		for(j=0; j<nb_sommets; j++){
			matrice[i][j] = 0 ;
		}
	}
	
	for(i=0; i<nb_sommets; i++){
		
		int tmp, som;
		printf("Nombre de sommets reliés au sommet %d \n", i+1);
		scanf("%d", &tmp);
		
		for (j=0; j<tmp; j++){
			printf("Sommet relié à %d \n", i);
			scanf("%d", &som);
			matrice[i][som] = 1;
		}
		
	}
	
	for(i=0; i<nb_sommets; i++){
		for(j=0; j<nb_sommets; j++){
			printf("%d", matrice[i][j]);
		}
		printf("\n");
	}
	
	
	return 0 ;
}
