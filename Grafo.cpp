#include<stdio.h> //Biblioteca para entrada e saida de comandos (printf e scanf) Standard Input/Output
#include<conio.h> //Include é uma diretiva de compilação para carregar uma biblioteca no codigo fonte
#include<stdlib.h> //Standard Library para usar o comando de limpar a tela (system("cls"))

int tamanho; // Precisa ser uma variavel global para controlar o tamanho do grafo que será usada em várias funções;
int matriz[100][100];
int Menu(){
  system("cls"); //Passando comando de limpara a tela para o sistema operacional(CLS:Clear Screen);
  printf("\n ======== MENU DE CONTROLE ========");
  printf("\n = 1: Inicializar a Matriz 	  =");
  printf("\n = 2: Imprimir a Matriz 	  =");
  printf("\n = 3: Inserir valor na Matriz 	  =");
  printf("\n = 4: Percorrer a Matriz 	  =");
  printf("\n = 5: Identificar menor 	  =");
  printf("\n = 6: Sair do programa 		  =");
  printf("\n ==================================");
  printf("\n Digite a opcao desejada: ");
  int resposta;
  scanf("%i", &resposta);
  return(resposta);
}

void LimparMatriz(){
  for(int linha=1; linha<=tamanho; linha++)
    for(int coluna=1; coluna<=tamanho; coluna++)
      matriz[linha][coluna] = 0;
}

void ImprimirMatriz(){
  printf("\n");
    for(int linha=1; linha<=tamanho; linha++)
      for(int coluna=1; coluna<=tamanho; coluna++){
        if(coluna == tamanho){
          printf("%i \n",matriz[linha][coluna]);
        }else{
          printf("%i  ", matriz[linha][coluna]);
        }
      }
  printf("\n");
  printf("\n\n Pressione uma tecla para prosseguir...\n");
  getch();
}
int main(){
	int resposta;
	do{
		resposta = Menu();
		if (resposta == 1){ //Inicializar a matriz na memória limpando as arestas (valor zero);
			printf("\n Informe o tamanho do grafo: ");
			scanf("%i",&tamanho); // %i serve para informar que o valor de entrada é do tipo i: inteiro; f:float;
      LimparMatriz();
			printf("\n Matriz inicializada com sucesso (Tamanho da matriz: %i)", tamanho);
			printf("\n\n Pressione uma tecla para prosseguir...\n");
      getch();
		}
    else if(resposta == 2){ //Imprimir matriz
      ImprimirMatriz();
    }
	}while(resposta != 6);

  	
	getch(); //Comando para guardar o pressionamento de uma tecla (na biblioteca conio.h)
}
