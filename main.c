#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM_ALUNO 4
#define TAM_MAX_NOME 99
#define TAM_CPF 11

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

// STRUCT ALUNO
typedef struct
{
    int matricula;
    char nome[TAM_MAX_NOME];
    char sexo;
    char cpf[TAM_CPF];
    Data data_aluno;

} Aluno;

int main()
{
    Aluno listaAluno[TAM_ALUNO]; // VETOR ALUNOS
    int option;
    int out = 0;
    int qtdAluno = 0;
    int incrementadorMatricula = 0;

    while (!out)
    {
        printf("--------> MENU ESCOLA <-------\n");
        printf("##############################\n");
        printf(" 1 -> Portal do Aluno. <-\n");
        printf(" 2 -> Portal do Professor. <- \n");
        printf(" 3 -> Portal da Disciplina. <-\n");
        printf(" 0 -> Sair do Programa. <-\n\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        { // MODULO ALUNO
            int optionAluno;
            int outAluno = 0;
            printf(" ---> PORTAL ALUNO <---\n");

            while (!outAluno)
            {
                printf("#########################\n");
                printf("1 --> Cadastrar aluno. <--\n");
                printf("2 --> Listar aluno. <--\n");
                printf("3 --> Atualizar aluno. <--\n");
                printf("4 --> Excluir aluno. <--\n");
                printf("0 --> Voltar para o PORTAL. <--\n\n");
                scanf("%d", &optionAluno);
                getchar();

                switch (optionAluno)
                {
                case 1:
                {

                    // nome OK, matricula(id), sexo OK, data de nascimento OK.
                    // CADASTRO DO NOME
                    if (qtdAluno < TAM_ALUNO)
                    {
                        printf("Digite o nome do aluno: \n");
                        fgets(listaAluno[qtdAluno].nome, TAM_MAX_NOME, stdin);
                        listaAluno[qtdAluno].nome[strcspn(listaAluno[qtdAluno].nome, "\n")] = '\0';

                        // CADASTRO CPF

                        printf("Digite o CPF: (APENAS NUMEROS)\n");
                        fgets(listaAluno[qtdAluno].cpf, TAM_CPF, stdin);
                        listaAluno[qtdAluno].cpf[strcspn(listaAluno[qtdAluno].cpf, "\n")] = '\0';
                        getchar();

                        // CADASTRO SEXO
                        do
                        {
                            printf("Digite o sexo (M/F): \n");
                            scanf(" %c", &listaAluno[qtdAluno].sexo);
                            listaAluno[qtdAluno].sexo = toupper(listaAluno[qtdAluno].sexo);
                            getchar();
                        } while ((listaAluno[qtdAluno].sexo) != 'M' && (listaAluno[qtdAluno].sexo) != 'F');

                        // CADASTRO DATA DE NASCIMENTO
                        do
                        {
                            printf("Digite a data de nascimento: (Digite nesse formato: dd mm aaaa) \n");
                            scanf("%d %d %d", &listaAluno[qtdAluno].data_aluno.dia, &listaAluno[qtdAluno].data_aluno.mes, &listaAluno[qtdAluno].data_aluno.ano);

                            if (listaAluno[qtdAluno].data_aluno.dia < 1 || listaAluno[qtdAluno].data_aluno.dia > 31 || listaAluno[qtdAluno].data_aluno.mes < 1 || listaAluno[qtdAluno].data_aluno.mes > 12 || listaAluno[qtdAluno].data_aluno.ano < 1900 || listaAluno[qtdAluno].data_aluno.ano > 2025)
                            {
                                printf("Data invalida!, digite novamente. \n");
                            }
                        } while (listaAluno[qtdAluno].data_aluno.dia < 1 || listaAluno[qtdAluno].data_aluno.dia > 31 ||
                                 listaAluno[qtdAluno].data_aluno.mes < 1 || listaAluno[qtdAluno].data_aluno.mes > 12 ||
                                 listaAluno[qtdAluno].data_aluno.ano < 1900 || listaAluno[qtdAluno].data_aluno.ano > 2025);

                        listaAluno[qtdAluno].matricula = ++incrementadorMatricula;
                        qtdAluno++;
                        printf("Cadastro concluido!\n");
                    }
                    else
                    {
                        printf("Lista de aluno cheia. \n\n");
                    }
                    break;
                }

                case 2:
                {
                    for (int i = 0; i < qtdAluno; i++)
                    {
                        printf("Matricula: %d - Nome: %s, CPF: %s, Sexo: %c , Data de nascimento: %d/%d/%d. \n", listaAluno[i].matricula, listaAluno[i].nome,
                               listaAluno[i].cpf, listaAluno[i].sexo,
                               listaAluno[i].data_aluno.dia, listaAluno[i].data_aluno.mes, listaAluno[i].data_aluno.ano);
                    }
                    break;
                }

                case 3:
                {
                    printf("-> Atualizar Aluno: \n");
                    printf("#### Todos Alunos\n");
                    for (int i = 0; i < qtdAluno; i++)
                    {
                        printf("Matricula: %d - Nome: %s, CPF: %s, Sexo: %c , Data de nascimento: %d/%d/%d.\n",
                               listaAluno[i].matricula, listaAluno[i].nome,
                               listaAluno[i].cpf, listaAluno[i].sexo,
                               listaAluno[i].data_aluno.dia, listaAluno[i].data_aluno.mes, listaAluno[i].data_aluno.ano);
                    }

                    while (!outAluno)
                    {
                        printf("#########################\n");
                        printf("1 --> Atualizar Nome. <--\n");
                        printf("2 --> Atualizar CPF. <--\n");
                        printf("3 --> Atualizar Sexo. <--\n");
                        printf("4 --> Atualizar Data de nascimento. <--\n");
                        printf("0 --> Voltar para o PORTAL. <--\n\n");

                        scanf("%d", &optionAluno);
                        getchar();

                        if (optionAluno == 0)
                        {
                            printf("Voltando ao menu principal ... \n");
                            outAluno = 1;
                            break;
                        }

                        printf("Digite a matrícula do aluno que deseja atualizar: ");
                        int matricula;
                        scanf("%d", &matricula);
                        getchar();

                        int encontrou = 0;

                        switch (optionAluno)
                        {
                        case 1:
                            for (int i = 0; i < qtdAluno; i++)
                            {
                                if (listaAluno[i].matricula == matricula)
                                {
                                    printf("Digite o novo nome do aluno: \n");
                                    fgets(listaAluno[i].nome, TAM_MAX_NOME, stdin);
                                    listaAluno[i].nome[strcspn(listaAluno[i].nome, "\n")] = '\0';
                                    printf("Nome atualizado com sucesso.\n");
                                    encontrou = 1;
                                    break;
                                }
                            }
                            break;

                        case 2:
                            for (int i = 0; i < qtdAluno; i++)
                            {
                                if (listaAluno[i].matricula == matricula)
                                {
                                    printf("Digite o novo CPF (Apenas números):\n");
                                    fgets(listaAluno[i].cpf, TAM_CPF, stdin);
                                    listaAluno[i].cpf[strcspn(listaAluno[i].cpf, "\n")] = '\0';
                                    printf("CPF atualizado com sucesso.\n");
                                    encontrou = 1;
                                    break;
                                }
                            }
                            break;

                        case 3:
                            for (int i = 0; i < qtdAluno; i++)
                            {
                                if (listaAluno[i].matricula == matricula)
                                {
                                    do
                                    {
                                        printf("Digite o novo sexo (M/F): \n");
                                        scanf(" %c", &listaAluno[i].sexo);
                                        listaAluno[i].sexo = toupper(listaAluno[i].sexo);
                                        getchar();
                                    } while (listaAluno[i].sexo != 'M' && listaAluno[i].sexo != 'F');
                                    printf("Sexo atualizado com sucesso.\n");
                                    encontrou = 1;
                                    break;
                                }
                            }
                            break;

                        case 4:
                            for (int i = 0; i < qtdAluno; i++)
                            {
                                if (listaAluno[i].matricula == matricula)
                                {
                                    do
                                    {
                                        printf("Digite a nova data de nascimento (dd mm aaaa):\n");
                                        scanf("%d %d %d", &listaAluno[i].data_aluno.dia, &listaAluno[i].data_aluno.mes, &listaAluno[i].data_aluno.ano);
                                        getchar();
                                        if (listaAluno[i].data_aluno.dia < 1 || listaAluno[i].data_aluno.dia > 31 ||
                                            listaAluno[i].data_aluno.mes < 1 || listaAluno[i].data_aluno.mes > 12 ||
                                            listaAluno[i].data_aluno.ano < 1900 || listaAluno[i].data_aluno.ano > 2025)
                                        {
                                            printf("Data inválida! Tente novamente.\n");
                                        }
                                    } while (listaAluno[i].data_aluno.dia < 1 || listaAluno[i].data_aluno.dia > 31 ||
                                             listaAluno[i].data_aluno.mes < 1 || listaAluno[i].data_aluno.mes > 12 ||
                                             listaAluno[i].data_aluno.ano < 1900 || listaAluno[i].data_aluno.ano > 2025);

                                    printf("Data de nascimento atualizada com sucesso.\n");
                                    encontrou = 1;
                                    break;
                                }
                            }
                            break;

                        default:
                            printf("Opção inválida!\n");
                            break;
                        }

                        if (!encontrou)
                        {
                            printf("Não existe aluno com essa matrícula!\n");
                        }
                    }
                    break;
                }

                case 4:
                {
                    for (int i = 0; i < qtdAluno; i++)
                    {
                        printf("- Matricula: %d - Nome: %s, CPF: %s, Sexo: %c , Data de nascimento: %d/%d/%d.\n",
                               listaAluno[i].matricula, listaAluno[i].nome,
                               listaAluno[i].cpf, listaAluno[i].sexo,
                               listaAluno[i].data_aluno.dia, listaAluno[i].data_aluno.mes, listaAluno[i].data_aluno.ano);
                    }

                    printf("Digite a matrícula do aluno para exclusão:\n");
                    int matricula;
                    scanf("%d", &matricula);

                    int encontrou_matricula = 0;
                    for (int i = 0; i < qtdAluno; i++)
                    {
                        if (listaAluno[i].matricula == matricula)
                        {
                            encontrou_matricula = 1;
                            for (int j = i; j < qtdAluno - 1; j++)
                            {
                                listaAluno[j] = listaAluno[j + 1];
                            }
                            qtdAluno--;
                            break;
                        }
                    }

                    if (encontrou_matricula)
                    {
                        printf("Aluno excluído com sucesso.\n");
                    }
                    else
                    {
                        printf("Não existe aluno com essa matrícula.\n");
                    }
                    break;
                }

                case 0:
                {
                    printf("Voltando ao menu principal ... \n");
                    outAluno = 1;
                    break;
                }

                default:
                {
                    printf("Opcao Invalida\n");
                }
                }
            }
            break;
        }

        case 2:
        { // MODULO PROdFRESSOR
            printf("MODULO PROFESSOR\n");
            break;
        }
        case 3:
        { // MODULO DISCIPLINA
            printf("MODULO DISCIPLINA\n");
            break;
        }
        case 0:
        { // MODULO SAIR
            printf("Saindo ... \n");
            out = 1;
            break;
        }
        default:
        {
            printf("-> Opcao invalida <-\n");
        }
        }
    }
    return 0;
}
