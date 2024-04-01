#include <stdio.h> //biblioteca de comunicacão com o usuário
#include <stdlib.h> //biblioteca de alocacão de espaco em memória
#include <locale.h> //biblioteca de alocaões de texto por região
#include <string.h>//biblioteca responsável por cuidar das string

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
	fprintf (file,cpf);//salvo o valor da variável
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
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem para o código suportar os assentos
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informacões do usuário: ");
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
		printf("O CPF não foi encontrado ou deletado\n");
		system("pause");	
		}
		
}

int main() //Mostra as opcões que o usuário vai ter em sua tela
{
	int opcao=0; //Definindo variáveis
	int x=1;//Variável para não fechar o programa automaticamente
	
	for(x=1;x=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Região feita para suportar os assentos do Brasil
	
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opcão desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");//opcões que o usuário vai ter em sua tela
		printf("\t2 - Consultar nomes\n");//opcões que o usuário vai ter em sua tela
		printf("\t3 - Deletar nomes\n\n");//opcões que o usuário vai ter em sua tela
		printf("Opcão: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); 
	
		switch(opcao)//SwitchCase foi usado para melhorar a performace do código
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
				printf("Essa opcão não existe!\n");
				system("pause");
				break;
		}//Fim do SwitchCase
	
	}
}
