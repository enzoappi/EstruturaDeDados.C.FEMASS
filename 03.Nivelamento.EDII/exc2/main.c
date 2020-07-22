#include "bib_vetor.h"
#define n 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int *vPtr, v[n];
	
	vPtr = &v[0];
	
	for(int i = 0; i < n; i++){
		printf("Informe o %do valor para o vetor: ", i + 1);
		scanf("%d", &vPtr[i]);
	}
	
	printVetor(10, vPtr);
	
	return 0;
}
