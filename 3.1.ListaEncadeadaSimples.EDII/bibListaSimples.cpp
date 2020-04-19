#include "bibListaSimples.h"

minhaLista* inicializa(){
	return NULL;
}

minhaLista* insereInicio(minhaLista* listaPTR, int i){
	minhaLista* novoNoh = (minhaLista* ) malloc(sizeof(minhaLista));
	novoNoh->info = i;
	novoNoh->prox = listaPTR;
	return novoNoh;
}

void imprimeLista(minhaLista* listaPTR){
	for(minhaLista* ptr = listaPTR; ptr != NULL; ptr = ptr->prox){
		printf(" %i ", ptr->info);
	}
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

void liberarMemoria(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR;
	while(ptr != NULL){
		minhaLista* tempPTR = ptr->prox;
		free(ptr);
		ptr = tempPTR;
	}
}

minhaLista* retiraDaLista(minhaLista* listaPTR, int valor){
	minhaLista* anterior = NULL;
	minhaLista* ptr = listaPTR;
	
	while(ptr != NULL && ptr->info != valor){
		anterior = ptr;
		ptr = ptr->prox;
	}
	
	
	if(anterior == NULL){ 
		listaPTR = ptr->prox; //se o valor achado foi no primeiro elemento, quer dizer que o ponteiro do anterior era nulo.
	}
	if(ptr == NULL){
		printf("\nNAO ENCONTREI o VALOR desejado, para remocao.\n");
		return listaPTR; //Caso tenha parado o loop por nao ter achado o valor, retorno o endereco da lista original, sem exclusao alguma.
	}
	else{
		anterior->prox = ptr->prox; //Caso o valor achado, esteja no meio da lista. Precisou-se fazer a ponte para apontar o end da frente do PTR.
	}
	free(ptr);
	return listaPTR;
}

