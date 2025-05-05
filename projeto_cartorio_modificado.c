
#include <stdio.h>   //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espansão em memória
#include <locale.h>  //biblioteca de alocações de texto por região
#include <string.h>  //biblioteca responssável por cuidar das strings

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

        printf("Deseja cadastrar outro usuário? (s/n): ");
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
            printf("Não foi possível abrir o arquivo, não localizado!");
        } else {
            while (fgets(conteudo, 200, file) != NULL) {
                printf("\nEssas são as informaçóees do usuário: %s\n\n", conteudo);
            }
            fclose(file);
        }

        printf("Deseja consultar outro usuário? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    system("pause");
    return 0;
}

int deletar() {
    char cpf[40], opcao, confirmar;

    do {
        printf("Digite o cpf do usuário a ser deletado: ");
        scanf("%s", cpf);

        printf("Tem certeza que deseja deletar o usuário com CPF %s? (s/n): ", cpf);
        scanf(" %c", &confirmar);

        if (confirmar == 's' || confirmar == 'S') {
            if (remove(cpf) == 0) {
                printf("Usuário deletado com sucesso.\n");
            } else {
                printf("O usuário não se encontra no sistema!\n");
            }
        } else {
            printf("Operação cancelada.\n");
        }

        printf("Deseja deletar outro usuário? (s/n): ");
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
        printf("Escolha a opção desejada no menu:\n\n");
        printf("\t1 - Registrar os nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: ");

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
                printf("Essa opção não existe!\n");
                system("pause");
                break;
        }
    }
}
