#include <stdio.h>  //biblioteca de comuinicação com o úsuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

	int registro() //Função responsavel por cadastrar os usuários no sistema 
	{
		//início da criação de variáveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Fim da criação de variáveis/string
		
		printf("digite o cpf a ser cadastrado: "); //Coletando a informação do usuário
		scanf("%s" , cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w");	//cria o arquivo do tipo write
		fprintf(file,cpf);//salvo o valor da variável
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
			printf("Não foi possível abrir o arquivo , não localizado!.\n ");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
	}
	
	int deletar()
	{
		char cpf[40];
		
		printf("Digite o cpf do usuário a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usuário não se encontra no sistema!.\n");
			system("pause");
		}
	
	}
	
	int main()
{
	
	
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco==1;)
	
	{
	
	system("cls"); //Reponsável por limpar a tela
	
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
		printf("### cartório da EBAC ###\n\n"); //Inicio da seleção menu
		printf("escolha a opção desejada no menu:\n\n");
		printf("\t1 - registrar os nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("\nopção: ");//Fim do menu
	    
    	scanf("%d" , &opcao);//Armazenando a escolha do usuário
    
    	system("cls");
    	
    	switch(opcao)
    	{
    		case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não existe!\n");
			system("pause");
			break;
		}//Fim da seleção
    
    

	}
}
