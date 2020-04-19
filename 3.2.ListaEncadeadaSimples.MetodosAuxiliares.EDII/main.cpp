#include "bibLisEncSim.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	minhaLista* listaPTR = (minhaLista* ) malloc(sizeof(minhaLista));
	
	inicializa(listaPTR);
	printf("\nLista Iniciada com sucesso!\n");
	
	int opcao(0), num(0);
	do{
		do{
			printf("\nDigite:\n[1] - INSERIR uma info no FIM da lista\n[2] - MOSTRAR o INICIO da lista\n[3] - MOSTRAR o FIM da lista\n[4] - EXIBIR a lista\n[5] - Mostra o TAMANHO da Lista\n[6] - Numero de OCORRENCIAS de um numero\n[7] - LIBERAR a memoria\n[8] - Sair\nSua opcao: ");
			scanf(" %i", &opcao);
		}while(opcao < 1 || opcao > 8);
	
	
	//iniciando a tela de escolha
		switch(opcao){
			case 1:
				printf("\nDigite um numero inteiro e aleatorio: ");
				scanf(" %i", &num);
				insereFim(listaPTR, num);
				break;
			case 2:
				printf("\nInfo: [");
				mostraInicio(listaPTR);
				printf("]\n");
				break;
			case 3:
				printf("\nInfo: [");
				mostraFim(listaPTR);
				printf("]\n");
				break;
			case 4:
				if(listaPTR->proximo != NULL){
					printf("\nInfo: [");
					imprimeLista(listaPTR);
					printf("]\n");
				}
				else{
					printf("\nLista vazia!\n");
				}
				break;
			case 5:
				printf("\nA lista contém %d numero(s).\n", tamanho(listaPTR));
				break;
			case 6:
				printf("\nDigite um numero a ser buscado: ");
				scanf(" %i", &num);
				printf("\nExiste(m) %d ocorrencia(s) do numero fornecido, na da lista.\n", ocorrencias(listaPTR, num));
				break;
			case 7:
				liberarMemoria(listaPTR);
				printf("\nMemoria liberada!\n");
				inicializa(listaPTR);
				break;
			case 8:
				printf("\n\n\tObrigado por utilizar o software FEMASS\t\n\n");
				break;
		}
	}while(opcao != 8);
	
	system("PAUSE");
	return 0;
}
