#include "biblivcds.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	struct livro *cadastroPTR;
    int cont(0), *contPTR;
  	contPTR = &cont;
	cadastroPTR = (struct livro *) malloc(*contPTR * sizeof(struct livro));
	
	//iniciando o arquivamento
	FILE *pont_arq;
	pont_arq = fopen("bibCdstrLivros.txt", "a");
	
	//coletando as informacoes
	menu(cadastroPTR, contPTR, pont_arq);
	
	//fechando o arquivo
	fclose(pont_arq);
	
	//liberando a memoria
	free(cadastroPTR);
	
	return 0;
}

