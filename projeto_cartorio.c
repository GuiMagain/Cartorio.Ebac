#include <stdio.h>  //biblioteca de comuinica��o com o �suario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

	int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema 
	{
		//in�cio da cria��o de vari�veis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Fim da cria��o de vari�veis/string
		
		printf("digite o cpf a ser cadastrado: "); //Coletando a informa��o do usu�rio
		scanf("%s" , cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w");	//cria o arquivo do tipo write
		fprintf(file,cpf);//salvo o valor da vari�vel
		fclose(file);//fecho o arquivo
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo,"a");
		fprintf(file , nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file , ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file , sobrenome);
		fclose (file);
		
		file = fopen(arquivo, "a");
		fprintf(file , ",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s" , cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
	}

	int consulta()
	{
		setlocale(LC_ALL, "portuguese");//definindo a linguagem
		
		char cpf[50];
		char conteudo[200];
		
		printf("Digite o cpf a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("N�o foi poss�vel abrir o arquivo , n�o localizado!.\n ");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
	}
	
	int deletar()
	{
		char cpf[40];
		
		printf("Digite o cpf do usu�rio a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usu�rio n�o se encontra no sistema!.\n");
			system("pause");
		}
	
	}
	
	int main()
{
	
	
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco==1;)
	
	{
	
	system("cls"); //Repons�vel por limpar a tela
	
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
		printf("### cart�rio da EBAC ###\n\n"); //Inicio da sele��o menu
		printf("escolha a op��o desejada no menu:\n\n");
		printf("\t1 - registrar os nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("\nop��o: ");//Fim do menu
	    
    	scanf("%d" , &opcao);//Armazenando a escolha do usu�rio
    
    	system("cls");
    	
    	switch(opcao)
    	{
    		case 1:
			registro(); //Chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema!!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o existe!\n");
			system("pause");
			break;
			
		}//Fim da sele��o
    
    

	}
}
