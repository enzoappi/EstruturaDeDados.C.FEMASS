#include "lstEncSimRecBib.h"

minhaLista* inicializa(){
	return NULL;
}

minhaLista* insereInicio(minhaLista* listaPTR, int i){
	minhaLista* novoNoh = (minhaLista* ) malloc(sizeof(minhaLista));
	novoNoh->info = i;
	novoNoh->prox = listaPTR;
	return novoNoh;
}

void imprime_recursiva(minhaLista* listaPTR){
	if (vazia(listaPTR)){
		return;
	}
	/* imprime primeiro elemento */
	printf(" %d ", listaPTR->info);
	/* imprime sub-lista */
	imprime_recursiva(listaPTR->prox);
}

bool vazia(minhaLista* listaPTR){
	return (listaPTR == NULL);
}

minhaLista* buscaInfo(minhaLista* listaPTR, int valor){
	minhaLista* ptr;
	for(ptr = listaPTR; ptr != NULL; ptr = ptr->prox){
		if(ptr->info == valor){
			return ptr;
		}		
	}
	return NULL;
}

void libera_recursiva(minhaLista* listaPTR){
	if (!vazia(listaPTR)){
		libera_recursiva(listaPTR->prox);
		free(listaPTR);
	}
}

minhaLista* retira_recursiva(minhaLista* listaPTR, int valor){
	if (vazia(listaPTR)){
		return listaPTR;
	}
	if (listaPTR->info == valor) {
		Lista* ptr = listaPTR; 
		listaPTR = listaPTR->prox;
		free(ptr);
	}
	else {
		listaPTR->prox = retira_recursiva(listaPTR->prox, valor);
	}
	return listaPTR;
}
