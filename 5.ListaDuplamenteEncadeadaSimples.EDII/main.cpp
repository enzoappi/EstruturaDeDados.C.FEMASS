#include "bibListDuplEncdSimp.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	minhaLista* listaPTR = NULL;
	//listaPTR = inicializar(listaPTR); //inicializando a lista.
	
	int opcao(0), num(0);
	do{
		do{
			printf("\nDigite:\n[1] - INSERIR info no INICIO da lista\n[2] - INSERIR info no FIM da lista\n[3] - REMOVE info no INICIO da lista\n[4] - REMOVE info no FIM da lista\n[5] - REMOVE info SOLICIDATO (KEY), da lista\n[6] - TAMANHO da lista\n[7] - MOSTRAR a lista COMPLETA\n[8] - MOSTRA o INICIO da lista\n[9] - MOSTRA o FIM da lista\n[10] - APAGAR a lista\n[11] - SAIR\nSua opcao: ");
			scanf(" %i", &opcao);
		}while(opcao < 1 || opcao > 11);
	
	
	//iniciando a tela de escolha
		switch(opcao){
			case 1:
				printf("\nDigite um numero inteiro e aleatorio: ");
				scanf(" %i", &num);
				if(listaPTR == NULL){ //testo se a lista criada está vazia ou não.
    				listaPTR = inicializar(listaPTR, num); //caso esteja, inicia-se a mesma com o valor fornecido pelo usuario.
				}
				else{
					listaPTR = insereInicio(listaPTR, num);
				}
				break;
			case 2:
				printf("\nDigite um numero inteiro e aleatorio: ");
				scanf(" %i", &num);
				if(listaPTR == NULL){ //testo se a lista criada está vazia ou não.
    				listaPTR = inicializar(listaPTR, num); //caso esteja, inicia-se a mesma com o valor fornecido pelo usuario.
				}
				else{
					listaPTR = insereFim(listaPTR, num);
				}
				break;
			case 3:
				if(listaPTR == NULL){
					printf("\nNao ha mais elementos para remover!\nA lista ja esta vazia!\n");
				}
				else{
					listaPTR = removeInicio(listaPTR);
				}
				break;
			case 4:
				if(listaPTR == NULL){
					printf("\nNao ha mais elementos para remover!\nA lista ja esta vazia!\n");
				}
				else{
					listaPTR = removeFim(listaPTR);	
				}
				break;
			case 5:
				if(listaPTR == NULL){
					printf("\nNao ha mais elementos para remover!\nA lista ja esta vazia!\n");
				}
				else{
					printf("\nDigite um numero inteiro e aleatorio: ");
					scanf(" %i", &num);
					listaPTR = removeKey(listaPTR, num);
				}
				break;
			case 6:
				if(listaPTR == NULL){
					printf("\nA lista esta vazia!\n");
				}
				else{
					size(listaPTR);
				}
				break;
			case 7:
				if(listaPTR == NULL){
					printf("\nA lista esta vazia!\n");
				}
				else{
					printf("\nInfo: [");
					mostraLista(listaPTR);
					printf("]\n");
				}
				break;
			case 8:
				if(listaPTR == NULL){
					printf("\nA lista esta vazia!\n");
				}
				else{
					mostraInicio(listaPTR);
				}
				break;
			case 9:
				if(listaPTR == NULL){
					printf("\nA lista esta vazia!\n");
				}
				else{
					mostraFim(listaPTR);
				};
				break;
			case 10:
				if(listaPTR == NULL){
					printf("\nLista APAGADA!\n");
				}
				else{
					void apagaLista(minhaLista* listaPTR);
					printf("\nLista APAGADA!\n");
					listaPTR = NULL;
				};
				break;
			case 11:
				printf("\n\n\tObrigado por utilizar o software FEMASS\t\n\n");
				break;
		}
	}while(opcao != 11);
	
	system("PAUSE");
	return 0;
}

