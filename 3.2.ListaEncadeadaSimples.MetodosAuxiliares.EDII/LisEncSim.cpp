#include "bibLisEncSim.h"

void inicializa(minhaLista* listaPTR){
	listaPTR->proximo = NULL;
}

void insereFim(minhaLista* listaPTR, int i){
	minhaLista *novoNoh=(minhaLista *) malloc(sizeof(minhaLista));
	if(!novoNoh){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	novoNoh->info = i;
	novoNoh->proximo = NULL;
	 
	if(listaPTR->proximo == NULL){
		listaPTR->proximo = novoNoh;
	}
	else{
		minhaLista *ptr = listaPTR->proximo;
	  
		while(ptr->proximo != NULL){
			ptr = ptr->proximo;
		}
		ptr->proximo = novoNoh;
	}
}

void imprimeLista(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR->proximo;
	while(ptr != NULL){
		printf(" %i ", ptr->info);
		ptr = ptr->proximo;
	}
}

void mostraInicio(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR->proximo;
	printf(" %i ", ptr->info);
}

void mostraFim(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR->proximo;
	do{
		ptr = ptr->proximo;
	}while(ptr->proximo != NULL);
	printf(" %i ", ptr->info);
}

int tamanho(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR->proximo;
	int cont = 0;
	while(ptr != NULL){
		cont++;
		ptr = ptr->proximo;
	}
	return cont;
}

int ocorrencias(minhaLista* listaPTR, int valor){
	minhaLista* ptr = listaPTR->proximo;
	int cont = 0;
	while(ptr != NULL){
		if(ptr->info == valor){
			cont++;
		}
		ptr = ptr->proximo;		
	}
	return cont;
}

void liberarMemoria(minhaLista* listaPTR){
  minhaLista* nohAtual = listaPTR->proximo;
  while(nohAtual != NULL){
   minhaLista* proximoNoh = nohAtual->proximo;
   free(nohAtual);
   nohAtual = proximoNoh;
  }
 }
