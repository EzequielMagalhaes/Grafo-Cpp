#include<stdio.h> //Biblioteca para entrada e saida de comandos (printf e scanf) Standard Input/Output
#include<conio.h> //Include é uma diretiva de compilação para carregar uma biblioteca no codigo fonte
#include<stdlib.h> //Standard Library para usar o comando de limpar a tela (system("cls"))
int Menu(){
  system("cls");
  printf("\n ====== MENU DE CONTROLE ======");
  printf("\n = 1: Inicializar a Matriz 	  =");
  printf("\n = 2: Imprimir a Matriz 	  =");
  printf("\n = 3: Inserir valor na Matriz 	  =");
  printf("\n = 4: Percorrer a Matriz 	  =");
  printf("\n = 5: Identificar menor 	  =");
  printf("\n = 6: Sair do programa 		  =");
  printf("\n ==============================");
  printf("\n Digite a opcao desejada: ");
  int resposta;
  scanf("%i", &resposta);
  return(resposta);
}

int main(){
	int resposta;
	do{
		resposta = Menu();
	}while(resposta != 6);

  	
	getch(); //Comando para guardar o pressionamento de uma tecla (na biblioteca conio.h)
}
