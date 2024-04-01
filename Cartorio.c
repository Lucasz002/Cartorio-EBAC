#include <stdio.h> //biblioteca de comunicac�o com o usu�rio
#include <stdlib.h> //biblioteca de alocac�o de espaco em mem�ria
#include <locale.h> //biblioteca de aloca�es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);// Responsavel por copiar os valores das string
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf (file,cpf);//salvo o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem para o c�digo suportar os assentos
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informac�es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
		printf("O CPF n�o foi encontrado ou deletado\n");
		system("pause");	
		}
		
}

int main() //Mostra as opc�es que o usu�rio vai ter em sua tela
{
	int opcao=0; //Definindo vari�veis
	int x=1;//Vari�vel para n�o fechar o programa automaticamente
	
	for(x=1;x=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Regi�o feita para suportar os assentos do Brasil
	
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a opc�o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");//opc�es que o usu�rio vai ter em sua tela
		printf("\t2 - Consultar nomes\n");//opc�es que o usu�rio vai ter em sua tela
		printf("\t3 - Deletar nomes\n\n");//opc�es que o usu�rio vai ter em sua tela
		printf("Opc�o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); 
	
		switch(opcao)//SwitchCase foi usado para melhorar a performace do c�digo
		{
			case 1:
				registro();
				break;
				
			case 2:
				consulta();
				break;
			case 3:
				deletar();
				break;
			
			default:
				printf("Essa opc�o n�o existe!\n");
				system("pause");
				break;
		}//Fim do SwitchCase
	
	}
}
