#include "LstCircSimEncBib.h"

minhaLista* inicializar(minhaLista* listaPTR, int valor){
    minhaLista* novoNoh = (minhaLista*)malloc(sizeof(minhaLista)); //cria-se o novo noh.
    novoNoh->info = valor; //atribui-se um valor inteiro na parte info do noh.
    listaPTR = novoNoh; //fazemos com que a lista iniciada receba o endereço do primeiro noh criado.
    listaPTR->proximo = listaPTR; //lista inicializada, aponta pra ela mesmo.
    return listaPTR; //retornamos o endereco da lista inicializada.
}

minhaLista* insereInicio(minhaLista* listaPTR, int valor){
	minhaLista* novoNoh = (minhaLista*)malloc(sizeof(minhaLista)); //cria-se o novo noh.
    novoNoh->info = valor;  //atribui-se um valor inteiro na parte info do noh.
    novoNoh->proximo = listaPTR->proximo; //fazemos com que o novo noh aponte à lista iniciada na parte em que ela aponta o noh seguinte.
    listaPTR->proximo = novoNoh; //fazemos com que a lista que anteriormente se apontava. Passe a apontar o noh seguinte.
    return listaPTR;
}

minhaLista* insereFim(minhaLista* listaPTR, int valor){
	minhaLista* novoNoh = (minhaLista*)malloc(sizeof(minhaLista));
	novoNoh->info = valor;
	novoNoh->proximo = listaPTR->proximo; 
  	listaPTR->proximo = novoNoh; 
  	listaPTR = novoNoh; 
    
  	return listaPTR; 
}

minhaLista* removeInicio(minhaLista* listaPTR){
    if(listaPTR == listaPTR->proximo){ //se a lista estiver apontando para ela mesma, significa que eh o ultimo elemento remanescente.
    	minhaLista* tempPTR = listaPTR->proximo; //ponteiro temporario vai apontar no elemento mais a esquerda da lista (ultimo a entrar).
    	listaPTR->proximo = tempPTR->proximo; //primeiro elemento que entrou, vai apontar aonde o ponteiro temporario aponta agora, ou seja, no segundo.
    	free(tempPTR); //libero o ponteiro temporario e, por consequencia, o ultimo noh que entrou na lista.
    	listaPTR = NULL; //atribuo um valor nulo, pra ela.
    	return listaPTR;
	}
	minhaLista* tempPTR = listaPTR->proximo; //ponteiro temporario vai apontar no elemento mais a esquerda da lista (ultimo a entrar).
    listaPTR->proximo = tempPTR->proximo; //primeiro elemento que entrou, vai apontar aonde o ponteiro temporario aponta agora, ou seja, no segundo.
    free(tempPTR); //libero o ponteiro temporario e, por consequencia, o ultimo noh que entrou na lista.
    return listaPTR;
}

minhaLista* removeFim(minhaLista* listaPTR){
	if(listaPTR != listaPTR->proximo){ //se a lista estiver apontando para ela mesma, significa que eh o ultimo elemento remanescente.
    	minhaLista* tempPTR = listaPTR->proximo;
		do{
			tempPTR = tempPTR->proximo;
		}while(tempPTR->proximo != listaPTR);
		tempPTR->proximo = listaPTR->proximo;
		free(listaPTR);
		return tempPTR;
	}
	free(listaPTR);
	listaPTR = NULL;
	return listaPTR;
}

minhaLista* removeKey(minhaLista* listaPTR, int valor){
	minhaLista* keyAnteriorPTR = listaPTR;
	minhaLista* keyPTR = listaPTR->proximo;
	if(listaPTR != listaPTR->proximo){
		while(keyPTR->info != valor){
			if(keyPTR == listaPTR){
				printf("\nNao encontrei o valor solicitado, para remocao!\n");
				return listaPTR;
			}
			keyAnteriorPTR = keyPTR;
			keyPTR = keyPTR->proximo;
		}
		keyAnteriorPTR->proximo = keyPTR->proximo;
		free(keyPTR);
		return keyAnteriorPTR;
	}
	else{
		if(keyPTR->info == valor){
			free(keyPTR);
			listaPTR = NULL;
			return listaPTR;
		}	
	}
	printf("\nNao encontrei o numero a ser removido, na lista!\n");
	return listaPTR;
}

void size(minhaLista* listaPTR){
	minhaLista* tempPTR = listaPTR->proximo;
	int cont = 1;
	while(tempPTR != listaPTR){
		cont++;
		tempPTR = tempPTR->proximo;
	}
	printf("\nO tamanho da lista eh: %d\n", cont);
}

void mostraLista(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR->proximo;
	do{
		printf(" %d ", ptr->info);
		ptr = ptr->proximo;	
	}while(ptr != listaPTR->proximo);
}

void mostraInicio(minhaLista* listaPTR){
	minhaLista* ptr = listaPTR->proximo;
	printf("\nInfo: [ %d ]\n", ptr->info);
}

void mostraFim(minhaLista* listaPTR){
	printf("\nInfo: [ %d ]\n", listaPTR->info);
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

