#include "Sorts.h"

void criaVetor(int* vetor, int n){
	srand(time(NULL));
	for (int i = 0; i < n; i++){
		vetor[i] = rand() % 1000000;
	}
}

void copiaVetor(int* vetor, int* vetorCopia, int n){
	for(int i = 0; i < n; i++){
		vetorCopia[i] = vetor[i];
	}
}

void printVetor(int* vet, int n){
	int i;
	printf("[");
	for (i = 0; i < n; i++){
		printf(" %d", vet[i]);
	}
	printf(" ]");
}

void bubbleSort(int* vetor, int n){
	int k, j, aux;
	for(k = 0; k < n; k++){
		for(j = 0; j < n - 1; j++){
			if(vetor[j] > vetor[j + 1]){
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}

void selectSort(int* vetor, int n){
	int i, j, k, aux;
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(vetor[i] > vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

void insertionSort(int* vetor, int n) {
	for(int i = 1; i < n; i++) {
		int tmp = vetor[i];
		int j = i;
		while(j > 0 && tmp < vetor[j - 1]) {
			vetor[j] = vetor[j - 1];
			j--;
		}
		vetor[j] = tmp;
	}
}

void quickSort(int* vetor, int n) {
  if (n < 2) return;
 
  int pivo = vetor[n / 2];
 
  int i, j;
  for (i = 0, j = n - 1; ; i++, j--) {
    while (vetor[i] < pivo) i++;
    while (vetor[j] > pivo) j--;
 
    if (i >= j) break;
 
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
  }
 
  quickSort(vetor, i);
  quickSort(vetor + i, n - i);
}

void shellSort (int* vetor, int n) {
    int h, i, j, t;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            t = vetor[i];
            for (j = i; j >= h && t < vetor[j - h]; j -= h) {
                vetor[j] = vetor[j - h];
            }
            vetor[j] = t;
        }
    }
}

void mergeSort(int* vetor, int l, int r){
	if(r > l){
		int i, m = (l + (r - 1)) / 2;
		mergeSort(vetor, l, m);
		mergeSort(vetor, m + 1, r);
		intercalar(vetor, l, m, r);
	}
}

void intercalar(int* vetor, int l, int m, int r){
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
}

void radixSort(int* vetor, int n) {
	int i, baseExponencial = 1, m = 0, bucket[n], vetorAux[n];

	for(i = 0; i < n; i++) {
		if(vetor[i] > m) {
			m = vetor[i];
		}
	}

	while((m/baseExponencial) > 0) {
		for (i = 0; i < n; i++) {
			bucket[i] = 0;
		}
		for(i = 0; i < n; i++) {
			bucket[(vetor[i] / baseExponencial) % 10]++;
		}
		for(i = 1; i < n; i++) {
			bucket[i] += bucket[i-1];
		}
		for(i = (n - 1); i >= 0; i--) {
			vetorAux[--bucket[(vetor[i] / baseExponencial) % 10]] = vetor[i];
		}
		for(i = 0; i < n; i++) {
			vetor[i] = vetorAux[i];
		}
		baseExponencial *= 10;
	}
}

void executaECalculaTempoBubble(int* vetor, int n){
	clock_t inicio = clock();

	bubbleSort(vetor, n);

	clock_t fim = clock();
	double tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo gasto na execucao do metodo: %f segundos", tempoDeCpu);
}

void executaECalculaTempoSelect(int* vetor, int n){
	clock_t inicio = clock();

	selectSort(vetor, n);

	clock_t fim = clock();
	double tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo gasto na execucao do metodo: %f segundos", tempoDeCpu);
}

void executaECalculaTempoInsertion(int* vetor, int n){
	clock_t inicio = clock();

	insertionSort(vetor, n);

	clock_t fim = clock();
	double tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo gasto na execucao do metodo: %f segundos", tempoDeCpu);
}

void executaECalculaTempoQuick(int* vetor, int n){
	clock_t inicio = clock();

	quickSort(vetor, n);

	clock_t fim = clock();
	double tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo gasto na execucao do metodo: %f segundos", tempoDeCpu);
}

void executaECalculaTempoShell(int* vetor, int n){
	clock_t inicio = clock();

	shellSort(vetor, n);

	clock_t fim = clock();
	double tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo gasto na execucao do metodo: %f segundos", tempoDeCpu);
}

void executaECalculaTempoMerge(int* vetor, int n, int r){
	clock_t inicio = clock();

	mergeSort(vetor, n, r);

	clock_t fim = clock();
	double tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo gasto na execucao do metodo: %f segundos", tempoDeCpu);
}

void executaECalculaTempoRadix(int* vetor, int n){
	clock_t inicio = clock();

	radixSort(vetor, n);

	clock_t fim = clock();
	double tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo gasto na execucao do metodo: %f segundos", tempoDeCpu);
}

