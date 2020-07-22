#include "bib.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//criando o ponteiro do vetor
	int *v; 
	v = (int *) malloc((num) * sizeof(int));
	
	menu(v);
	
	free(v);
	
	return 0;
}
