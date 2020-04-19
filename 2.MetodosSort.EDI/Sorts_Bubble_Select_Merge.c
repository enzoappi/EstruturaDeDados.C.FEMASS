/*	Nome do Programa:
	Enunciado:
	Disciplina:
	Prof:
	Aluno:
	data:
*/

//Declaração de bibliotecas e variáveis
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int selectsort(int vetor[], int n){
	int i, j, k, aux;
	printf("\n\nSELECTSORT\n");
	for(i = 0; i < n - 1; i++){
		printf("\nLOOP (%d) VETOR --> ", i + 1);
		for(j = i + 1; j < n; j++){
			if(vetor[i] > vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
		for(k = 0; k < n; k++){
			printf(" %d", vetor[k]);
		}
	}
	printf("\n\nVETOR ORDENADO:\n[");
	for(i = 0; i < 20; i++){
		printf(" %d", vetor[i]);
	}
	printf(" ]");
}

void mergesort(int vetor[], int l, int r){
	if(r > l){
		int i, m = (l + (r - 1)) / 2;
		mergesort(vetor, l, m);
		mergesort(vetor, m + 1, r);
		intercalar(vetor, l, m, r);
	}
}

int intercalar(int vetor[], int l, int m, int r){
	int i, j, k;
	int indice1 = m - l + 1;
	int indice2 = r - m;
	int vetTEMP1[indice1], vetTEMP2[indice2];
	for (i = 0; i < indice1; i++){
		vetTEMP1[i] = vetor[l + i];
	}
	for (j = 0; j < indice2; j++){
		vetTEMP2[j] = vetor[m + 1+ j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < indice1 && j < indice2){
		if (vetTEMP1[i] <= vetTEMP2[j]){
			vetor[k] = vetTEMP1[i];
			i++;
		}
		else{
			vetor[k] = vetTEMP2[j];
			j++;
		}
		k++;
	}
	while (i < indice1){
		vetor[k] = vetTEMP1[i];
		i++;
		k++;
	}
	while (j < indice2){
		vetor[k] = vetTEMP2[j];
		j++;
		k++;
	}
	return 0;
}

void printVetor(int vet[], int n){
	int i;
	printf("vet = [");
	for (i = 0; i < n; i++){
		printf(" %d", vet[i]);
	}
	printf(" ]");
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
	
	int escolha;
	printf("\n\nDigite:\n[0] - Ordenacao Bubble\n[1] - Ordenacao Select\n[2] - Ordenacao Merge\nSUA ESCOLHA: ");
	scanf(" %d", &escolha);
	
	if(escolha == 0){
		bubblesort(vetor, 20);
	}
	else if(escolha == 1){
		selectsort(vetor, 20);
	}
	else if(escolha == 2){
		mergesort(vetor, 0, 19);
		printf("\n\nMERGE SORT\n");
		printf("\nVetor ordenado:\n");
		printVetor(vetor, 20);
	}
}
