//Declaração de bibliotecas e variáveis
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>


void criaVetor(int* vetor, int n);
void copiaVetor(int* vetor, int* vetorCopia, int n);
void printVetor(int* vet, int n);

//Metodos de ordenacao
void bubbleSort(int* vetor, int n);
void selectSort(int* vetor, int n);
void insertionSort(int* vetor, int n);
void quickSort(int* vetor, int n);
void shellSort (int* vetor, int n);
void mergeSort(int* vetor, int l, int r);
void intercalar(int* vetor, int l, int m, int r);
void radixSort(int* vetor, int n);

//Execucao dos metodos de ordenacao com calculo dos tempos gastos
void executaECalculaTempoBubble(int* vetor, int n);
void executaECalculaTempoSelect(int* vetor, int n);
void executaECalculaTempoInsertion(int* vetor, int n);
void executaECalculaTempoQuick(int* vetor, int n);
void executaECalculaTempoShell(int* vetor, int n);
void executaECalculaTempoMerge(int* vetor, int n, int r);
void executaECalculaTempoRadix(int* vetor, int n);

