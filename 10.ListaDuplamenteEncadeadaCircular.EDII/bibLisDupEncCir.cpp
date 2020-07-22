#include "bibLisDupEncCir.h"

minhaLista* inicializar(minhaLista* listaPTR, int valor){
    minhaLista* novoNoh = (minhaLista*)malloc(sizeof(minhaLista)); //cria-se o novo noh.
    novoNoh->info = valor; //atribui-se um valor inteiro na parte info do noh.
    listaPTR = novoNoh; //fazemos com que a lista iniciada receba o endereço do primeiro noh criado.
    listaPTR->anterior = novoNoh;
	listaPTR->proximo = novoNoh; //lista inicializada, aponta pra ela mesmo.
    return listaPTR; //retornamos o endereco da lista inicializada.
}

minhaLista* insereInicio(minhaLista* listaPTR, int valor){
	minhaLista* novoNoh = (minhaLista*)malloc(sizeof(minhaLista)); //cria-se o novo noh.
    novoNoh->info = valor;  //atribui-se um valor inteiro na parte info do noh.
    minhaLista* ptrTemp = listaPTR;
    do{
    	ptrTemp = ptrTemp->proximo;
	}while(ptrTemp->proximo != listaPTR);
	novoNoh->anterior = ptrTemp;
	novoNoh->proximo = listaPTR;
	listaPTR->anterior = novoNoh;
    ptrTemp->proximo = novoNoh;
    return novoNoh;
}

minhaLista* insereFim(minhaLista* listaPTR, int valor){
	minhaLista* novoNoh = (minhaLista*)malloc(sizeof(minhaLista)); //cria-se o novo noh.
    novoNoh->info = valor;  //atribui-se um valor inteiro na parte info do noh.
    minhaLista* ptrTemp = listaPTR;
    do{
    	ptrTemp = ptrTemp->proximo;
	}while(ptrTemp->proximo != listaPTR);
	novoNoh->anterior = ptrTemp;
	novoNoh->proximo = listaPTR;
	listaPTR->anterior = novoNoh;
    ptrTemp->proximo = novoNoh;
  	return listaPTR; 
}

minhaLista* removeInicio(minhaLista* listaPTR){
    if(listaPTR->anterior == listaPTR && listaPTR->proximo == listaPTR){ //a lista so tem um elemento
    	free(listaPTR); //libero o ponteiro temporario e, por consequencia, o ultimo noh que entrou na lista.
    	listaPTR = NULL; //atribuo um valor nulo, pra ela.
    	return listaPTR;
	}
    minhaLista* ptrTemp1 = listaPTR->proximo;
    minhaLista* ptrTemp2 = listaPTR->anterior;
    ptrTemp1->anterior = ptrTemp2;
	ptrTemp2->proximo = ptrTemp1;
    free(listaPTR);
    return ptrTemp1;
}

minhaLista* removeFim(minhaLista* listaPTR){
	if(listaPTR->anterior == listaPTR && listaPTR->proximo == listaPTR){ //a lista so tem um elemento
    	free(listaPTR); //libero o ponteiro temporario e, por consequencia, o ultimo noh que entrou na lista.
    	listaPTR = NULL; //atribuo um valor nulo, pra ela.
    	return listaPTR;
	}
    minhaLista* ptrTemp1 = listaPTR->anterior;
    minhaLista* ptrTemp2 = ptrTemp1->anterior;
    ptrTemp2->proximo = listaPTR;
    listaPTR->anterior = ptrTemp2;
    free(ptrTemp1);
	return listaPTR;
}

void buscaKey(minhaLista* listaPTR, int valor){
	minhaLista* ptrTemp = listaPTR;
	while(ptrTemp->info != valor && ptrTemp != listaPTR->anterior){
		ptrTemp = ptrTemp->proximo;
	}
	if(ptrTemp->info != valor){
		printf("\nNao encontrei o numero desejado, na lista!\n");
	}
	else{
		printf("\nEncontrei!\nO numero desejado, esta contido na lista!\n");
	}
}

minhaLista* removeKey(minhaLista* listaPTR, int valor){
	minhaLista* ptrTemp = listaPTR;
	while(ptrTemp->info != valor && ptrTemp != listaPTR->anterior){
		ptrTemp = ptrTemp->proximo;
	}
	if(ptrTemp->info != valor){
		printf("\nNao encontrei o numero a ser removido, na lista!\n");
		return listaPTR;
	}
	else{
		if(ptrTemp->anterior == ptrTemp && ptrTemp->proximo == ptrTemp){
			free(ptrTemp);
			listaPTR = NULL; //atribuo um valor nulo, pra ela.
			return listaPTR;
		}
		else{
			if(ptrTemp == listaPTR){
				listaPTR->anterior->proximo = listaPTR->proximo;
				listaPTR->proximo->anterior = listaPTR->anterior;
				listaPTR = ptrTemp->proximo;
				free(ptrTemp);
				return listaPTR;
			}
			else{
				ptrTemp->anterior->proximo = ptrTemp->proximo;
				ptrTemp->proximo->anterior = ptrTemp->anterior;
				free(ptrTemp);
				return listaPTR;
			}
		}
	}
}

void size(minhaLista* listaPTR){
	minhaLista* tempPTR = listaPTR;
	int cont = 1;
	while(tempPTR->proximo != listaPTR){
		cont++;
		tempPTR = tempPTR->proximo;
	}
	printf("\nO tamanho da lista eh: %d\n", cont);
}

void mostraListaInicioFim(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR;
	do{
		printf(" %d ", ptr->info);
		ptr = ptr->proximo;	
	}while(ptr != listaPTR);
}

void mostraListaFimInicio(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR;
	do{
		ptr = ptr->anterior;
		printf(" %d ", ptr->info);	
	}while(ptr->anterior != listaPTR->anterior);
}

void mostraInicio(minhaLista* listaPTR){
	printf("\nInfo: [ %d ]\n", listaPTR->info);
}

void mostraFim(minhaLista* listaPTR){
	minhaLista* ptrTemp = listaPTR->anterior;
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


