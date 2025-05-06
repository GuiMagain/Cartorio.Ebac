
#include <stdio.h>   //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espans�o em mem�ria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca responss�vel por cuidar das strings

int registro() {
    char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];
    char opcao;

    do {
        printf("Digite o cpf a ser cadastrado: ");
        scanf("%s", cpf);
        strcpy(arquivo, cpf);

        FILE *file = fopen(arquivo, "w");
        fprintf(file, cpf);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ",");
        fclose(file);

        printf("Digite o nome a ser cadastrado: ");
        scanf("%s", nome);
        file = fopen(arquivo, "a");
        fprintf(file, nome);
        fprintf(file, ",");
        fclose(file);

        printf("Digite o sobrenome a ser cadastrado: ");
        scanf("%s", sobrenome);
        file = fopen(arquivo, "a");
        fprintf(file, sobrenome);
        fprintf(file, ",");
        fclose(file);

        printf("Digite o cargo a ser cadastrado: ");
        scanf("%s", cargo);
        file = fopen(arquivo, "a");
        fprintf(file, cargo);
        fclose(file);

        printf("Deseja cadastrar outro usu�rio? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    system("pause");
    return 0;
}

int consulta() {
    setlocale(LC_ALL, "portuguese");
    char cpf[50], conteudo[200], opcao;

    do {
        printf("Digite o cpf a ser consultado: ");
        scanf("%s", cpf);

        FILE *file = fopen(cpf, "r");

        if (file == NULL) {
            printf("N�o foi poss�vel abrir o arquivo, n�o localizado!");
        } else {
            while (fgets(conteudo, 200, file) != NULL) {
                printf("\nEssas s�o as informa��ees do usu�rio: %s\n\n", conteudo);
            }
            fclose(file);
        }

        printf("Deseja consultar outro usu�rio? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    system("pause");
    return 0;
}

int deletar() {
    char cpf[40], opcao, confirmar;

    do {
        printf("Digite o cpf do usu�rio a ser deletado: ");
        scanf("%s", cpf);

        printf("Tem certeza que deseja deletar o usu�rio com CPF %s? (s/n): ", cpf);
        scanf(" %c", &confirmar);

        if (confirmar == 's' || confirmar == 'S') {
            if (remove(cpf) == 0) {
                printf("Usu�rio deletado com sucesso.\n");
            } else {
                printf("O usu�rio n�o se encontra no sistema!\n");
            }
        } else {
            printf("Opera��o cancelada.\n");
        }

        printf("Deseja deletar outro usu�rio? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    system("pause");
    return 0;
}

int main() {
    int opcao = 0;
    int laco = 1;

    for (laco = 1; laco == 1;) {
        system("cls");
        setlocale(LC_ALL, "portuguese");

        printf("### cartorio da EBAC ###\n\n");
        printf("Escolha a op��o desejada no menu:\n\n");
        printf("\t1 - Registrar os nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: ");

        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;

            case 4:
                printf("Obrigado por utilizar o sistema!!\n");
                return 0;
                break;

            default:
                printf("Essa op��o n�o existe!\n");
                system("pause");
                break;
        }
    }
}
