#include "bibListDuplEncdSimp.h"

minhaLista* inicializar(minhaLista* listaPTR, int valor){
    minhaLista* novoNoh = (minhaLista*)malloc(sizeof(minhaLista)); //cria-se o novo noh.
    novoNoh->info = valor; //atribui-se um valor inteiro na parte info do noh.
    listaPTR = novoNoh; //fazemos com que a lista iniciada receba o endereço do primeiro noh criado.
    listaPTR->anterior = NULL;
	listaPTR->proximo = NULL; //lista inicializada, aponta pra ela mesmo.
    return listaPTR; //retornamos o endereco da lista inicializada.
}

minhaLista* insereInicio(minhaLista* listaPTR, int valor){
	minhaLista* novoNoh = (minhaLista*)malloc(sizeof(minhaLista)); //cria-se o novo noh.
    novoNoh->info = valor;  //atribui-se um valor inteiro na parte info do noh.
    novoNoh->anterior = NULL;
	novoNoh->proximo = listaPTR; //fazemos com que o novo noh aponte à lista iniciada na parte em que ela aponta o noh seguinte.
    listaPTR->anterior = novoNoh;
    return novoNoh;
}

minhaLista* insereFim(minhaLista* listaPTR, int valor){
	minhaLista* novoNoh = (minhaLista*)malloc(sizeof(minhaLista));
	novoNoh->info = valor;
	novoNoh->proximo = NULL;
	minhaLista* ptrTemp = listaPTR;
	while(ptrTemp->proximo != NULL){
		ptrTemp = ptrTemp->proximo;
	}
	ptrTemp->proximo = novoNoh;
	novoNoh->anterior = ptrTemp;
  	return listaPTR; 
}

minhaLista* removeInicio(minhaLista* listaPTR){
    if(listaPTR->anterior == NULL && listaPTR->proximo == NULL){ //a lista so tem um elemento
    	free(listaPTR); //libero o ponteiro temporario e, por consequencia, o ultimo noh que entrou na lista.
    	listaPTR = NULL; //atribuo um valor nulo, pra ela.
    	return listaPTR;
	}
	minhaLista* ptrTemp = listaPTR;
	listaPTR = listaPTR->proximo;
	listaPTR->anterior = NULL;
    free(ptrTemp); //libero o ponteiro temporario e, por consequencia, o ultimo noh que entrou na lista.
    return listaPTR;
}

minhaLista* removeFim(minhaLista* listaPTR){
	if(listaPTR->anterior == NULL && listaPTR->proximo == NULL){ //a lista so tem um elemento
    	free(listaPTR); //libero o ponteiro temporario e, por consequencia, o ultimo noh que entrou na lista.
    	listaPTR = NULL; //atribuo um valor nulo, pra ela.
    	return listaPTR;
	}
	minhaLista* ptrTempAnt = listaPTR;
	minhaLista* ptrTempPost = listaPTR;
	while(ptrTempPost->proximo != NULL){
		ptrTempAnt = ptrTempPost;
		ptrTempPost = ptrTempPost->proximo;
	}
	ptrTempAnt->proximo = NULL;
	free(ptrTempPost);
	return listaPTR;
}

minhaLista* removeKey(minhaLista* listaPTR, int valor){
	minhaLista* ptrTempAnt = listaPTR;
	minhaLista* ptrTempPost = listaPTR;
	while(ptrTempPost->info != valor && ptrTempPost->proximo != NULL){
		ptrTempAnt = ptrTempPost;
		ptrTempPost = ptrTempPost->proximo;
	}
	if(ptrTempPost->info != valor){
		printf("\nNao encontrei o numero a ser removido, na lista!\n");
		return listaPTR;
	}
	else{
		if(ptrTempPost->anterior == NULL && ptrTempPost->proximo == NULL){
			free(ptrTempPost);
			listaPTR = NULL; //atribuo um valor nulo, pra ela.
			return listaPTR;
		}
		else if(ptrTempPost->anterior == NULL && ptrTempPost->proximo != NULL){
			listaPTR = ptrTempPost->proximo;
			listaPTR->anterior = NULL;
			free(ptrTempPost);
			return listaPTR;
		}
		else if(ptrTempPost->anterior != NULL && ptrTempPost->proximo != NULL){
			minhaLista* nohFrentePtrPost = ptrTempPost->proximo;
			nohFrentePtrPost->anterior = ptrTempAnt;
			ptrTempAnt->proximo = nohFrentePtrPost;
			free(ptrTempPost);
			return listaPTR;
		}
		else{
			ptrTempAnt->proximo = NULL;
			free(ptrTempPost);
			return listaPTR;
		}
	}
}

void size(minhaLista* listaPTR){
	minhaLista* tempPTR = listaPTR;
	int cont = 1;
	while(tempPTR->proximo != NULL){
		cont++;
		tempPTR = tempPTR->proximo;
	}
	printf("\nO tamanho da lista eh: %d\n", cont);
}

void mostraLista(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR;
	do{
		printf(" %d ", ptr->info);
		ptr = ptr->proximo;	
	}while(ptr != NULL);
}

void mostraInicio(minhaLista* listaPTR){
	printf("\nInfo: [ %d ]\n", listaPTR->info);
}

void mostraFim(minhaLista* listaPTR){
	minhaLista* ptrTemp = listaPTR;
	while(ptrTemp->proximo != NULL){
		ptrTemp = ptrTemp->proximo;
	}
	printf("\nInfo: [ %d ]\n", ptrTemp->info);
}

void apagaLista(minhaLista* listaPTR){
	do{
    	minhaLista* tempPTR = listaPTR->proximo;
    	listaPTR->proximo = tempPTR->proximo;
    	free(tempPTR);
    	listaPTR = NULL;
	}while(listaPTR == listaPTR->proximo);
    free(listaPTR);
}

