#include <stdio.h>
#include <locale.h>
#include <string.h>

#define N 15

typedef struct info{
	char nome[30];
};

typedef struct Fila{
	struct info elementos[20];	
	int inicio, fim;
} FILA;


void criarFila(FILA* F){
	F->inicio = 0;
	F->fim = -1;
}

void pushFila(FILA* F, char c[30]){ // aqui havia um int c;
	F->fim++;
	strcpy(F->elementos[F->fim].nome, c);
}

void popFila(FILA* F){
	if(F->inicio > F->fim){
		printf("Sem Vazia!\n");
	} else {
		F->inicio++;
	}
}

void mostrarFila(FILA F) {
    int i;
    for (i = F.inicio; i <= F.fim; i++) {
        printf("%s\n", F.elementos[i].nome);
    }
}



main(){
	setlocale(LC_ALL, "Portuguese");
	FILA F;
	int op;
	char nome[30];
	
	criarFila(&F);
	
	printf("Seja Bem Vindo à Fila de Impressão!\n");
	
	do{
		printf("\nEscolha uma Opção: ");
		printf("\n1 - Fornecer o Nome do Arquivo");
		printf("\n2 - Encaminhar o Arquivo para Impressão");
		printf("\n3 - Mostrar o Nome dos Arquivos");
		printf("\n4 - Sair do Programa\n");
		printf("Sua Opção: ");
		scanf("%d", &op);
		
		
		switch(op){
			case 1:
				printf("\nEscreva o Nome do Arquivo que Deseja Adicionar à Fila de Impressão: ");
				scanf("%s", &nome);
				pushFila(&F, &nome);
				printf("Arquivo Adicionado com Sucesso!\n");
				break;
			case 2:
				printf("Encaminhando Arquivo * %s * para Impressão...\n", &nome);
				printf("Arquivo Enviado com Sucesso!\n");
				popFila(&F);
				break;
			case 3:
				mostrarFila(F);
				break;
			case 4:
				printf("\nSaindo do Programa...");
				break;
			
		}
		
	} while( op != 4);
	
}