#include "abb.h"
using namespace std;

/* Prof. Irineu - Est. de Dados
Projeto de base para implementação de Árvore Binária de Busca (AVL). Supõe-se:
- main.cpp: front-end com usuário;
- abb.h e abb.cpp: prototipação de funções de manipulação da árvore binária de busca (abb),
 contendo definição "struct" do nó-dado (campos info, filho_esquerda e filho_direita; como 
 também as funções de manipulação.
Dica: referência de muitos métodos em: 
 https://www.ic.unicamp.br/~rocha/teaching/2016s1/mc202/aulas/arvore-binaria-busca-01.pdf  
 Livro Robert Lafore, ED e Alg em Java - Ciência Moderna, 2004.
Obs.: Recursos e funções adicionais à biblioteca deverão ser desenvolvidos com base neste.
*/
 
int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Portuguese");
	
	NoArv* root; //ponteiro de controle a partir da raiz - apontará para root - o primeiro nó-dado a ser inserido
	root = abb_criavazia(); //inicializa ponteiro de controle da árvore em NULL
	int num, opcao = 1, resposta;
	
	while(opcao != 0){
	
		cout << "\t\t\t****************\n" << "\t\t\t ARVORE BINARIA " << "\n\t\t\t****************\n";
		cout << "\n\nDigite" << "\n[1] - Criar Noh OU Adicionar Noh" << "\n[2] - Buscar valor-chave" << "\n[3] - Remover Noh";
		cout << "\n[4] - Valores-chave dos nohs da arvore" << "\n[5] - Altura da Arvore" << "\n[6] - Qtde de Nohs na Arvore";
		cout << "\n[7] - Travessia PRE-ordem" << "\n[8] - Travessia IN-ordem" << "\n[9] - Travessia POS-ordem";
		cout << "\n[10] - Mostrar Arvore Binaria (de forma estruturada)" << "\n[11] - Balancear Arvore";
		cout << "\n[0] - SAIR";
		cout << "\nSua opcao: ";
		cin >> opcao;
		
		switch(opcao) {
			
			//Criar ou Adicionar NOH
			case 1:
				cout << "\nDigite um numero inteiro e aleatorio: ";
				cin >> num;
				if(root == NULL) {
					root = abb_cria(num, NULL, NULL);
				}
				else {
					root = abb_insere(root, num);
				}
				cout << "\n\n\n";
				break;
			
			//Buscar valor		
			case 2:
				cout << "\nDigite um numero inteiro e aleatorio: ";
				cin >> num;
				if(abb_busca(root, num) ==  1){
					cout << "\nO valor buscado, existe na arvore binaria!\n\n";
				}
				else{
					cout << "\nO valor buscado, NAO existe na arvore binaria!\n\n";
				}
				cout << "\n\n\n";
				break;
			
			//Remover NOH
			case 3:
				cout << "\n\nDigite um numero inteiro e aleatorio para ser removido da arvore: ";
				cin >> num;
				if(abb_busca(root, num) ==  1){
					root = abb_retira(root, num);
					cout << "\n\nValor removido com sucesso!";
				}
				else{
					cout << "\nO valor que deseja-se remover, nao existe na Arvore Binaria!";
				}
				cout << "\n\n\n";
				break;
			
			//Imprimir valores-chave dos nohs da Arvore
			case 4:
				if(root != NULL){
					cout << "\n\nImpressao dos valores-chave dos nohs da Arvore Binaria: \n";
					abb_imprime(root);
					cout << "\n\n\n";
				}
				else{
					cout << "\nA Arvore esta vazia. Nao ha valores à serem impressos!";
					cout << "\n\n\n";
				}
				break;
			
			//Altura da Arvore Binaria	
			case 5:
				if(exibir_altura(root) < 0) {
					cout << "\nA Arvore esta vazia! Não ha sequer altura, pra ela!";
				}
				else {
					cout << "\n\nA altura dessa arvore eh: " << exibir_altura(root);
				}
				cout << "\n\n\n";
				break;
			
			//Quantidade de nohs na Arvore Binaria
			case 6:
				cout << "\n\nQuantidade de Nohs existentes na Arvore Binaria: " << qtde_nodos(root);
				cout << "\n\n\n";
				break;
				
			//Travessia PRE-ordem	
			case 7:
				if(root != NULL){
					cout << "\n\nImpressao dos numeros da arvore, utilizando Travessia PRE-ORDEM: ";
					abb_imprimeTravessiaPreOrdem(root);
					cout << "\n\n\n";
				}
				else{
					cout << "\nA Arvore esta vazia. Nao ha valores à serem impressos!";
					cout << "\n\n\n";
				}
				break;
			
			//Travessia IN-ordem	
			case 8:
				if(root != NULL){
					cout << "\n\nImpressao dos numeros da arvore, utilizando Travessia IN-ORDEM: ";
					abb_imprimeTravessiaInOrdem(root);
					cout << "\n\n\n";
				}
				else{
					cout << "\nA Arvore esta vazia. Nao ha valores à serem impressos!";
					cout << "\n\n\n";
				}
				break;
			
			//Travessia POS-ordem	
			case 9:
				if(root != NULL){
					cout << "\n\nImpressao dos numeros da arvore, utilizando Travessia POS-ORDEM: ";
					abb_imprimeTravessiaPosOrdem(root);
					cout << "\n\n\n";
				}
				else{
					cout << "\nA Arvore esta vazia. Nao ha valores à serem impressos!";
					cout << "\n\n\n";
				}
				break;
			
			//Mostrar Arvore Binaria (Estruturada)
			case 10:
				if(root != NULL){
					cout << "\n\nMostrando estrutura de árvore:\n";
					abb_displayTree(root);
					cout << "\n\n\n";
				}
				else{
					cout << "\nA Arvore esta vazia. Nao ha valores à serem impressos!";
					cout << "\n\n\n";
				}
				break;			
			
			//Balanceamento	
			case 11:
				if(root != NULL){
					root = abb_balancear(root);
					cout << "\nBalanceamento realizado com sucesso!";
				}
				else{
					cout << "\nA Arvore esta vazia, nao ha o que balancear!";
					cout << "\n\n\n";
				}
				break;	
		}
		
	}
	
	cout << "\n\nFim de programa!" << endl;
	system("pause");
	return 0;
}

