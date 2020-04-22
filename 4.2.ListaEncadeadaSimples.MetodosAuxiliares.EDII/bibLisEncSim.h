#include <stdlib.h>
#include <iostream>

struct Lista{
	int info;
	struct Lista* proximo; //ponteiro de ligacao
};

typedef struct Lista minhaLista;
void inicializa(minhaLista* listaPTR);
void insereFim(minhaLista* listaPTR, int i);
void imprimeLista(minhaLista* listaPTR);
void mostraInicio(minhaLista* listaPTR);
void mostraFim(minhaLista* listaPTR);
int tamanho(minhaLista* listaPTR);
int ocorrencias(minhaLista* listaPTR, int valor);
void liberarMemoria(minhaLista* listaPTR);

