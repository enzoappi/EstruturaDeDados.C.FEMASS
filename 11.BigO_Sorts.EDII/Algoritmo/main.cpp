#include "Sorts.h"

//Programa principal
int main(void){
	
	int n = 0;
	printf("Digite o tamanho do vetor de numeros inteiro e aleatorios: ");
	scanf(" %d", &n);
	
	int* vetor = (int*) malloc(n * sizeof(int));
	int* vetorCopia = (int*) malloc(n * sizeof(int));
	//int vetor[n], vetorCopia[n];
	criaVetor(vetor, n);
	
	printf("\n\nVetor Original: ");
	printVetor(vetor, n);
	
	//INCIO DOS METODOS DE ORDENACAO	
	printf("\n\n\n\nBUBBLE SORT");
	memcpy(vetorCopia, vetor, n * sizeof(int));
	//copiaVetor(vetor, vetorCopia, n);
	/*printf("\n\nVetor Copiado:\n");
	printVetor(vetorCopia, n);*/
	executaECalculaTempoBubble(vetorCopia, n);
	/*printf("\n\nVetor Ordenado:\n");
	printVetor(vetorCopia, n);*/
	
	
	printf("\n\nSELECT SORT");
	memcpy(vetorCopia, vetor, n * sizeof(int));
	//copiaVetor(vetor, vetorCopia, n);
	/*printf("\n\nVetor Copiado:\n");
	printVetor(vetorCopia, n);*/
	executaECalculaTempoSelect(vetorCopia, n);
	/*printf("\n\nVetor Ordenado:\n");
	printVetor(vetorCopia, n);*/
	
	
	printf("\n\nINSERTION SORT");
	memcpy(vetorCopia, vetor, n * sizeof(int));
	//copiaVetor(vetor, vetorCopia, n);
	/*printf("\n\nVetor Copiado:\n");
	printVetor(vetorCopia, n);*/
	executaECalculaTempoInsertion(vetorCopia, n);
	/*printf("\n\nVetor Ordenado:\n");
	printVetor(vetorCopia, n);*/
	
	
	printf("\n\nQUICK SORT");
	memcpy(vetorCopia, vetor, n * sizeof(int));
	//copiaVetor(vetor, vetorCopia, n);
	/*printf("\n\nVetor Copiado:\n");
	printVetor(vetorCopia, n);*/
	executaECalculaTempoQuick(vetorCopia, n);
	/*printf("\n\nVetor Ordenado:\n");
	printVetor(vetorCopia, n);*/
	
	
	printf("\n\nSHELL SORT");
	memcpy(vetorCopia, vetor, n * sizeof(int));
	//copiaVetor(vetor, vetorCopia, n);
	/*printf("\n\nVetor Copiado:\n");
	printVetor(vetorCopia, n);*/
	executaECalculaTempoShell(vetorCopia, n);
	/*printf("\n\nVetor Ordenado:\n");
	printVetor(vetorCopia, n);*/
	
	
	printf("\n\nMERGE SORT");
	memcpy(vetorCopia, vetor, n * sizeof(int));
	//copiaVetor(vetor, vetorCopia, n);
	/*printf("\n\nVetor Copiado:\n");
	printVetor(vetorCopia, n);*/
	executaECalculaTempoMerge(vetorCopia, 0, n-1);
	/*printf("\n\nVetor Ordenado:\n");
	printVetor(vetorCopia, n);*/
	
	
	printf("\n\nRADIX SORT");
	memcpy(vetorCopia, vetor, n * sizeof(int));
	//copiaVetor(vetor, vetorCopia, n);
	/*printf("\n\nVetor Copiado:\n");
	printVetor(vetorCopia, n);*/
	executaECalculaTempoRadix(vetorCopia, n);
	/*printf("\n\nVetor Ordenado:\n");
	printVetor(vetorCopia, n);*/
	
	
	printf("\n\n\n\nVetor Ordenado: ");
	printVetor(vetorCopia, n);
}
