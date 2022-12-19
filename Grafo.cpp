#include<stdio.h> //Biblioteca para entrada e saida de comandos (printf e scanf) Standard Input/Output
#include<conio.h> //Include é uma diretiva de compilação para carregar uma biblioteca no codigo fonte
#include<stdlib.h> //Standard Library para usar o comando de limpar a tela (system("cls"))
int Menu(){
  system("cls");
  printf("\n ====== MENU DE CONTROLE =====")
}

int main(){
  int tamanho;
	printf ("Informe o tamanho do grafo: ");
	scanf("%i", &tamanho);
	printf("Foi informado o tamanho do grafo: %i", tamanho);
	getch(); //Comando para guardar o pressionamento de uma tecla (na biblioteca conio.h)
}
