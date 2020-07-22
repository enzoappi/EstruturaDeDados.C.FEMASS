#include "bib.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {
	
	struct cadastro *cadastroPTR;
    int cont(0), *contPTR;
  	contPTR = &cont;
	cadastroPTR = (struct cadastro *) malloc(*contPTR * sizeof(struct cadastro));
	menu(cadastroPTR, contPTR);
	
	free(cadastroPTR);
	
	return 0;
}

