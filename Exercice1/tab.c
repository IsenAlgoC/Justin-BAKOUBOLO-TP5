# include <stdlib.h>
# include <stdio.h>

# define Taille 10
# define TAB2SIZE 100
#define TAILLEAJOUT 50


int initTab(int* tab, int size) {
	if (tab == NULL || size < 0) {
		return (-1);
	}
	for (int i = 0; i <size; i++) {
		*(tab + i) = 0;
	}
	return size;
}


int afficheTab(int* tab, int size, int nbElts) {
	if (tab == NULL || size < 0 || nbElts < 0 || nbElts > size) { // Si tab est le pointeur ou si size ou nbElements sont négatifs ou si nbElements > size : Erreur
		return (-1);
	}
	for (int i = 0; i < nbElts; i++) {
		printf("%d", *(tab + i));
	}
	printf("\n");
	return 0;
}

int * ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL || *size < 0 || *nbElts <0 || *size< *nbElts) {
		return (NULL);
	}

	if (*(nbElts) == *(size)) {
		*(size)+= TAILLEAJOUT; 
		int * temp ; 
		temp = tab; 
		tab = (int*) realloc(tab, (*size)*sizeof(int));
		if (tab == NULL) {
			tab = temp;
			free(temp);
			return NULL;
		}
	}

	*(tab+(*nbElts)) = element; 
	*(nbElts) += 1;
	
	return (tab); 
}



int main() {
	
	
	int* MyTab2; 
	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int)); // Creation dynamique du Tableau MyTab2 de taille TAB2SIZE
	if (MyTab2 != NULL) { initTab(MyTab2, TAB2SIZE); }
	else { printf("mémoire insuffisante"); return(-1); }
		
	for (int i = 0; i < 20; i++) { // initialise les 20 premiers élements du tableau avec les chiffres de 1 à 20
		*(MyTab2 + i) = i + 1;
	}

	afficheTab(MyTab2, TAB2SIZE, 20); 

	free(MyTab2);

	system("PAUSE");
	return (EXIT_SUCCESS);

}