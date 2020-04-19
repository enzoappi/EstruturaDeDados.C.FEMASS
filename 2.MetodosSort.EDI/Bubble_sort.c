/*	Nome do Programa:
	Enunciado:
	Disciplina:
	Prof:
	Aluno:
	data:
*/

//DeclaraÁ„o de bibliotecas e vari·veis
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int vet[], int n){
	int i;
	printf("vet = [");
	for (i = 0; i < n; i++){
		printf(" %d", vet[i]);
	}
	printf(" ]");
}

void bubblesort(int vetor[], int n){
	int k, j, aux;
	printf("\n\nBUBBLESORT\n\n");
	for(k = 0; k < n; k++){
		printf("LOOP (%d) VETOR --> [", k);
		for(j = 0; j < n - 1; j++){
			if(vetor[j] > vetor[j + 1]){
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
				printf(" %d", vetor[j]);
			}
			else{
				printf(" %d", vetor[j]);	
			}
			if(j == (n - 2)){
				printf(" %d", vetor[j + 1]);
			}
		}
		printf(" ]\n");
	}
	printf("\nVETOR ORDENADO:\n[");
	for(j = 0; j < 20; j++){
		printf(" %d", vetor[j]);
	}
	printf(" ]\n");
}

//Programa principal
int main(void){
	int i, vetor[20];
	srand(time(NULL));
	for (i = 0; i < 20; i++){
		vetor[i] = rand() % 20;
	}
	
	printf("\nVetor criado:\n");
	printVetor(vetor, 20);
	
	bubblesort(vetor, 20);
}