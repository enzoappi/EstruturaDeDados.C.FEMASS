#include "bib.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	struct cadastro *cadastroPTR;
    int cont = 0, *contPTR;
  	contPTR = &cont;
	cadastroPTR = (struct cadastro *) malloc(*contPTR * sizeof(struct cadastro));
	
	//iniciando o arquivamento
	FILE *pont_arq;
	pont_arq = fopen("bibCdstrPessoas.txt", "a+");
	
	/*Testando se o arquivo existe/abre
	if ((pont_arq = fopen("bibCdstrPessoas.txt","a+")) == EOF) {
		printf("\n Arquivo bibCdstrPessoas.txt esta vazio!: TECLE ALGO");
		getch();
	}*/
	
	char leitura1[30], leitura2[11], leitura3[13], leitura4[150]; //lê o 1o caractere do arquivo
	while (ch != EOF) { //varre o arquivo
		putchar(leitura1); //imprime na tela o caractere lido
		ch = getc(arq); //lê o próximo caractere
	}
	fclose (arq); //fecha o arquivo
	
	return 0;
}

	
	//coletando as informacoes
	menu(cadastroPTR, contPTR, pont_arq);
	
	//fechando o arquivo
	fclose(pont_arq);
	
	//liberando a memoria
	free(cadastroPTR);
	
	return 0;
}

