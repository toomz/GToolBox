#include <stdio.h>
#include <stdlib.h>
//#include <matrice.h>

int** create_mat(int nb_som) {
	
	int** mat = malloc( nb_som*sizeof(int*) );
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
			while((som <= 0) || (som > nb_som)){
				printf("Sommet relié à %d \n", i+1);
				scanf("%d", &som);
				if (tmp < 0)
				fprintf(stderr, "Ce sommet n'existe pas...");
			}
			mat[i][som-1] = 1;
			mat[som-1][i] = 1;
			som = 0;
		}
		
	}	
	return mat;
}

void show_mat(int** mat, int nb_som){
	int i, j;
	for(i=0; i<nb_som; i++){
		for(j=0; j<nb_som; j++){
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}
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

int** ajouter_sommet(int **matrice, int nb_som){//le sommet est ajouté à la fin de la matrice
	int** mat = malloc( (nb_som+1)*sizeof(int*) );
	int i, j ;
	// Initialisation de la matrice à 0
	for(i=0; i<nb_som+1; i++){
		mat[i] = malloc( nb_som*sizeof(int*) );
		for(j=0; j<nb_som+1; j++){
			mat[i][j] = 0 ;
		}
	}
	//recopiage de la matrice
	for (i=0;i<nb_som;i++){
		for(j=0;j<nb_som;j++){
			mat[i][j]=matrice[i][j];
		}
	}
	return mat;
}

int** enlever_sommet(int **matrice, int nb_som, int numero_som){
	int** mat = malloc( (nb_som-1)*sizeof(int*) );
	int i=0, j=0 ;
	// Initialisation de la matrice à 0
	while(i<nb_som){
		mat[i] = malloc( (nb_som-1)*sizeof(int*) );
		if(i!=numero){
		while(j<nb_som{
			if (j!=numero)
			{mat[i][j] = matrice[i][j] ;}
			j++;
		}
		}
		i++;
	}
	return mat;
}


int main(int argc, char* argv[]){
	
	int nb_sommets = 0;
	int i, j ;
	while((nb_sommets == 0) || (nb_sommets < 0)){
		printf("Veuillez entrer le nombre de sommets souhaités : \n");
		scanf("%d", &nb_sommets);
		if(nb_sommets < 0){
			fprintf(stderr, "Le nombre de sommets ne peut pas être négatif...");
		}
	}
	
	int **matrice = NULL ;
	matrice = create_mat(nb_sommets);
	show_mat(matrice, nb_sommets);
	
	
	return 0 ;
}
