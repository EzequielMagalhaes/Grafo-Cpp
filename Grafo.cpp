#include<stdio.h> //Biblioteca para entrada e saida de comandos (printf e scanf) Standard Input/Output
#include<conio.h> //Include  uma diretiva de compilacao para carregar uma biblioteca no codigo fonte
#include<stdlib.h> //Standard Library para usar o comando de limpar a tela (system("cls"))

int tamanho; // Precisa ser uma variavel global para controlar o tamanho do grafo que sera usada em varias funcões;
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
        printf(" %i  ", matriz[linha][coluna]);
        if(coluna == tamanho){
          printf("\n");
        }
      }
  printf("\n");
  printf("\n\n Pressione uma tecla para prosseguir...\n");
  getch(); //Comando para guardar o pressionamento de uma tecla (na biblioteca conio.h)
}

void GravarValor(int A, int B, int C){
  matriz[A][B] = C;
  printf("\n O valor %i foi gravado na posicao [%i,%i] da matriz.",C,A,B);
  printf("\n\n Pressione uma tecla para prosseguir...\n");
  getch();
}

int main(){ //Programa principal;
	int resposta,vlr,lin,col;
  lin = -1; //só por segurança pra nao haver nenhum lixo de memoria que comprometa o grafico;
  col = -1;
  char confirma; //Para confirmar a sobreposião de valores das arestas da matriz;
	do{
		resposta = Menu();
		if (resposta == 1){ //Inicializar a matriz na memória limpando as arestas (valor zero);
			printf("\n Informe o tamanho do grafo: ");
			scanf("%i",&tamanho); // %i serve para informar que o valor de entrada  do tipo i: inteiro; f:float;
      LimparMatriz();
			printf("\n Matriz inicializada com sucesso (Tamanho da matriz: %i)", tamanho);
			printf("\n\n Pressione uma tecla para prosseguir...\n");
      getch();
		}
    else if(resposta == 2){ //Imprimir matriz
      ImprimirMatriz();
    }
    else if(resposta == 3){ //Inserir valor na matriz
      do{
        //Camada de regras de negócio
      if((lin == col) & (lin > 0))
        printf(" A linha e a coluna nao podem ter o mesmo valor!\n");
      if(lin > tamanho)
        printf(" A linha informada esta fora da matriz!\n");
      if(col > tamanho)
        printf(" A coluna informada esta fora da matriz!\n");
      
        //Fim da camada de regras de negócio
      printf(" Informe a posicao da linha: ");  // Pedindo dados;
      scanf("%i",&lin);                        // Capurando o valor informado para a linha;
      printf(" Informe a posicao da coluna: "); // Pedindo dados;
      scanf("%i",&col);                        // Capurando o valor informado para a coluna;
      if(matriz[lin][col] > 0) {
        printf(" A posicao [%i][%i] ja contem o valor %i!\n",lin,col,matriz[lin][col]);
        printf(" Confirmar sobreposicao?! (S/N)");
        scanf("%s",&confirma); // %s -> pega a variavel do tipo caractere(char);
        if(confirma == 'N' | confirma == 'n'){
          printf("\n");
          printf("\n\n Pressione uma tecla para prosseguir...\n");
          return(resposta);
        }
        else if(confirma == 'S' | confirma == 's'){
          do{
            printf(" Informe um valor positivo para a Aresta: ");   // Pedindo dados;
            scanf("%i",&vlr);                        // Capurando o valor informado para o peso;
          }while(vlr <= 0);
            GravarValor(lin,col,vlr);
            lin = -1; //Limpando o conteudo das variaveis linha e coluna para as proximas rodadas do programa;
            col = -1;
            printf("Novo valor gravado com sucesso!");
        }
      }
      }while ((lin == col) | (lin > tamanho) | (col > tamanho)); //Diferença de um & pra && -> com dois &&, se a primeira falhar ele nem testa as demais; Com um &, ele vai ate o final;
      do{
      printf(" Informe um valor positivo para a Aresta: ");   // Pedindo dados;
      scanf("%i",&vlr);                        // Capurando o valor informado para o peso;
      }while(vlr <= 0);
      GravarValor(lin,col,vlr);
      lin = -1; //Limpando o conteudo das variaveis linha e coluna para as proximas rodadas do programa;
      col = -1;
    }
	}while(resposta != 6);
  getch();
}