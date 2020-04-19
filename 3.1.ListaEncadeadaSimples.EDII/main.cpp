#include "bibListaSimples.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	minhaLista* listaPTR;
	
	listaPTR = inicializa();
	printf("\nLista Iniciada com sucesso!\n");
	
	int opcao(0), num(0);
	do{
		do{
			printf("\nDigite:\n[1] - INSERIR uma info\n[2] - BUSCAR info\n[3] - REMOVER info\n[4] - EXIBIR a lista\n[5] - Lista esta VAZIA?\n[6] - LIBERAR a memoria\n[7] - Sair\nSua opcao: ");
			scanf(" %i", &opcao);
		}while(opcao < 1 || opcao > 7);
	
	
	//iniciando a tela de escolha
		switch(opcao){
			case 1:
				printf("\nDigite um numero inteiro e aleatorio: ");
				scanf(" %i", &num);
				listaPTR = insereInicio(listaPTR, num);
				//printf("\nEndereco do noh (valor da info %i) -> %p\n\n", num, listaPTR);
				break;
			case 2:
				printf("\nDigite um numero inteiro e aleatorio a ser buscado: ");
				scanf(" %i", &num);
				if(buscaInfo(listaPTR, num) != NULL){
					printf("\nValor CONTIDO na lista!\nEndereco do noh (valor da info %i) -> %p\n\n", num, (void *) buscaInfo(listaPTR, num));
				}
				else{
					printf("\nValor NAO CONTIDO na lista!\n");
				}
				break;
			case 3:
				printf("\nDigite o numero a ser removido da lista: ");
				scanf(" %i", &num);
				listaPTR = retiraDaLista(listaPTR, num);
				break;
			case 4:
				if(listaPTR != NULL){
					printf("\nInfo: [");
					imprimeLista(listaPTR);
					printf("]\n");
				}
				else{
					printf("\n\nLista vazia!\n\n");
				}
				break;
			case 5:
				if(vazia(listaPTR) == 1){
					printf("\nLISTA VAZIA!\n");
				}
				else{
					printf("\nLISTA COM VALORES!\n");
				};
				break;
			case 6:
				liberarMemoria(listaPTR);
				printf("\nMemoria liberada!\n");
				listaPTR = inicializa();
				break;
			case 7:
				printf("\n\n\tObrigado por utilizar o software FEMASS\t\n\n");
				break;
		}
	}while(opcao != 7);
	
	system("PAUSE");
	return 0;
}
