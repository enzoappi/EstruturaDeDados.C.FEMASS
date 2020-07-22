#include <stdlib.h>
#include <iostream>

struct Lista{
	int info;
	struct Lista* prox; //ponnteiro de ligacao
};

typedef struct Lista minhaLista;
minhaLista* inicializa();
minhaLista* insereInicio(minhaLista* listaPTR, int i);
void imprimeLista(minhaLista* listaPTR);
bool vazia(minhaLista* listaPTR);
minhaLista* buscaInfo(minhaLista* listaPTR, int valor);
void liberarMemoria(minhaLista* listaPTR);
minhaLista* retiraDaLista(minhaLista* listaPTR, int valor);

