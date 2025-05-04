#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM_CADASTRO 4
#define TAM_MAX_NOME 99
#define TAM_CPF 12

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int matricula;
    char nome[TAM_MAX_NOME];
    char sexo;
    char cpf[TAM_CPF];
    Data data_aluno;
} pessoa;

// STRUCT ALUNO
typedef struct
{
    int matricula;
    char nome[TAM_MAX_NOME];
    char sexo;
    char cpf[TAM_CPF];
    Data data_aluno;
} Aluno;

typedef struct
{
    int matricula;
    char nome[TAM_MAX_NOME];
    char sexo;
    char cpf[TAM_CPF];
    Data data_professor;
} Professor;
typedef struct
{
    int codigo;
    char nome[TAM_MAX_NOME];
    int semestre;
    int matriculaProfessor;
    Aluno alunosMatriculados[TAM_CADASTRO];
    int qtdAlunos;
} Disciplina;

// Funções Aluno
int cadastrarAluno(Aluno listaAluno[], int qtdAluno, int incrementadorMatricula)
{

    // nome OK, matricula(id), sexo OK, data de nascimento OK.
    // CADASTRO DO NOME
    if (qtdAluno < TAM_CADASTRO)
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

        listaAluno[qtdAluno].matricula = incrementadorMatricula + 1;
        return 1;
    }
    else
    {
        return 0;
    }
}
void listarAluno(int qtdAluno, Aluno listaAluno[])
{
    for (int i = 0; i < qtdAluno; i++)
    {
        printf("Matricula: %d - Nome: %s, CPF: %s, Sexo: %c , Data de nascimento: %d/%d/%d. \n", listaAluno[i].matricula, listaAluno[i].nome,
               listaAluno[i].cpf, listaAluno[i].sexo,
               listaAluno[i].data_aluno.dia, listaAluno[i].data_aluno.mes, listaAluno[i].data_aluno.ano);
    }
}
void atualizarAluno(int qtdAluno, Aluno listaAluno[])
{
    int outAluno = 0;
    int optionAluno;

    printf("-> Atualizar Aluno: \n");
    listarAluno(qtdAluno, listaAluno);

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
        case 1: // ATUALIZAR NOME
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
            if (!encontrou)
            {
                printf("Matricula invalida, tente novamente... ");
            }
            break;

        case 2: // ATUALIZAR CPF
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

        case 3: // ATUALIZAR SEXO
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

        case 4: // ATUALIZAR DATA DE NASCIMENTO
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
}
int excluirAluno(int qtdAluno, Aluno listaAluno[])
{
    if (qtdAluno == 0)
    {
        printf("Não há alunos cadastrados no sistema!\n");
        return 0;
    }

    printf("\n--- LISTA DE ALUNOS ---\n");
    listarAluno(qtdAluno, listaAluno);

    int matricula;
    printf("\nDigite a matrícula do aluno que deseja excluir: ");
    scanf("%d", &matricula);

    int encontrou = 0;

    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].matricula == matricula)
        {
            encontrou = 1;

            printf("\nALUNO ENCONTRADO:\n");
            printf("Nome: %s\n", listaAluno[i].nome);
            printf("Matrícula: %d\n", listaAluno[i].matricula);

            printf("\nTem certeza que deseja excluir este aluno? (1-Sim / 0-Não): ");
            int confirmacao;
            scanf("%d", &confirmacao);

            if (confirmacao == 1)
            {
                for (int j = i; j < qtdAluno - 1; j++)
                {
                    listaAluno[j] = listaAluno[j + 1];
                }
                printf("Aluno excluído com sucesso!\n");
                return qtdAluno - 1;
            }
            else
            {
                printf("Exclusão cancelada.\n");
                return qtdAluno;
            }
        }
    }

    // Se não encontrou o aluno
    if (!encontrou)
    {
        printf("Nenhum aluno encontrado com a matrícula %d!\n", matricula);
    }

    return qtdAluno;
}

// Funções Professor
int cadastrarProf(Professor listaProfessor[], int qtdProf, int incrementadorMatriculaProf)
{
    if (qtdProf < TAM_CADASTRO)
    {
        printf("Digite o nome do Professor: \n");
        fgets(listaProfessor[qtdProf].nome, TAM_MAX_NOME, stdin);
        listaProfessor[qtdProf].nome[strcspn(listaProfessor[qtdProf].nome, "\n")] = '\0';

        // CADASTRO CPF

        printf("Digite o CPF: (APENAS NUMEROS)\n");
        fgets(listaProfessor[qtdProf].cpf, TAM_CPF, stdin);
        listaProfessor[qtdProf].cpf[strcspn(listaProfessor[qtdProf].cpf, "\n")] = '\0';
        getchar();

        // CADASTRO SEXO
        do
        {
            printf("Digite o sexo (M/F): \n");
            scanf(" %c", &listaProfessor[qtdProf].sexo);
            listaProfessor[qtdProf].sexo = toupper(listaProfessor[qtdProf].sexo);
            getchar();
        } while ((listaProfessor[qtdProf].sexo) != 'M' && (listaProfessor[qtdProf].sexo) != 'F');

        // CADASTRO DATA DE NASCIMENTO
        do
        {
            printf("Digite a data de nascimento: (Digite nesse formato: dd mm aaaa) \n");
            scanf("%d %d %d", &listaProfessor[qtdProf].data_professor.dia, &listaProfessor[qtdProf].data_professor.mes,
                  &listaProfessor[qtdProf].data_professor.ano);

            if (listaProfessor[qtdProf].data_professor.dia < 1 || listaProfessor[qtdProf].data_professor.dia > 31 ||
                listaProfessor[qtdProf].data_professor.mes < 1 || listaProfessor[qtdProf].data_professor.mes > 12 ||
                listaProfessor[qtdProf].data_professor.ano < 1900 || listaProfessor[qtdProf].data_professor.ano > 2025)
            {
                printf("Data invalida!, digite novamente. \n");
            }
        } while (listaProfessor[qtdProf].data_professor.dia < 1 || listaProfessor[qtdProf].data_professor.dia > 31 ||
                 listaProfessor[qtdProf].data_professor.mes < 1 || listaProfessor[qtdProf].data_professor.mes > 12 ||
                 listaProfessor[qtdProf].data_professor.ano < 1900 || listaProfessor[qtdProf].data_professor.ano > 2025);

        listaProfessor[qtdProf].matricula = incrementadorMatriculaProf + 1;
        return 1;
    }
    else
    {
        return 0;
    }
}
void listarProf(int qtdProf, Professor listaProfessor[])
{

    for (int i = 0; i < qtdProf; i++)
    {
        printf("Matricula: %d - Nome: %s, CPF: %s, Sexo: %c , Data de nascimento: %d/%d/%d. \n", listaProfessor[i].matricula, listaProfessor[i].nome,
               listaProfessor[i].cpf, listaProfessor[i].sexo,
               listaProfessor[i].data_professor.dia, listaProfessor[i].data_professor.mes, listaProfessor[i].data_professor.ano);
    }
}
void attProf(int qtdProf, Professor listaProfessor[])
{
    int atualizando = 1;
    int optionprofessor;

    while (atualizando)
    {

        if (qtdProf == 0)
        {
            printf("Nao ha professor cadastrados! \n");
            break;
        }

        printf("#########################\n");
        printf("1 --> Atualizar Nome. <--\n");
        printf("2 --> Atualizar CPF. <--\n");
        printf("3 --> Atualizar Sexo. <--\n");
        printf("4 --> Atualizar Data de nascimento. <--\n");
        printf("0 --> Voltar para o PORTAL. <--\n\n");

        scanf("%d", &optionprofessor);
        getchar();

        if (optionprofessor == 0)
        {
            printf("Voltando ao menu principal ... \n");
            atualizando = 0;
            break;
        }

        printf("Digite a matrícula do Professor que deseja atualizar: ");
        int matricula;
        scanf("%d", &matricula);
        getchar();

        int encontrou = 0;

        switch (optionprofessor)
        {
        case 1:
            for (int i = 0; i < qtdProf; i++)
            {
                if (listaProfessor[i].matricula == matricula)
                {
                    printf("Digite o novo nome do Professor: \n");
                    fgets(listaProfessor[i].nome, TAM_MAX_NOME, stdin);
                    listaProfessor[i].nome[strcspn(listaProfessor[i].nome, "\n")] = '\0';
                    printf("Nome atualizado com sucesso.\n");
                    encontrou = 1;
                    break;
                }
            }
            break;

        case 2:
            for (int i = 0; i < qtdProf; i++)
            {
                if (listaProfessor[i].matricula == matricula)
                {
                    printf("Digite o novo CPF (Apenas números):\n");
                    fgets(listaProfessor[i].cpf, TAM_CPF, stdin);
                    listaProfessor[i].cpf[strcspn(listaProfessor[i].cpf, "\n")] = '\0';
                    printf("CPF atualizado com sucesso.\n");
                    encontrou = 1;
                    break;
                }
            }
            break;

        case 3: // ATUALIZAÇÃO SEXO
            for (int i = 0; i < qtdProf; i++)
            {
                if (listaProfessor[i].matricula == matricula)
                {
                    do
                    {
                        printf("Digite o novo sexo (M/F): \n");
                        scanf(" %c", &listaProfessor[i].sexo);
                        listaProfessor[i].sexo = toupper(listaProfessor[i].sexo);
                        getchar();
                    } while (listaProfessor[i].sexo != 'M' && listaProfessor[i].sexo != 'F');
                    printf("Sexo atualizado com sucesso.\n");
                    encontrou = 1;
                    break;
                }
            }
            break;

        case 4:
            for (int i = 0; i < qtdProf; i++)
            {
                if (listaProfessor[i].matricula == matricula)
                {
                    do
                    {
                        printf("Digite a nova data de nascimento (dd mm aaaa):\n");
                        scanf("%d %d %d", &listaProfessor[i].data_professor.dia, &listaProfessor[i].data_professor.mes, &listaProfessor[i].data_professor.ano);
                        getchar();
                        if (listaProfessor[i].data_professor.dia < 1 || listaProfessor[i].data_professor.dia > 31 ||
                            listaProfessor[i].data_professor.mes < 1 || listaProfessor[i].data_professor.mes > 12 ||
                            listaProfessor[i].data_professor.ano < 1900 || listaProfessor[i].data_professor.ano > 2025)
                        {
                            printf("Data inválida! Tente novamente.\n");
                        }
                    } while (listaProfessor[i].data_professor.dia < 1 || listaProfessor[i].data_professor.dia > 31 ||
                             listaProfessor[i].data_professor.mes < 1 || listaProfessor[i].data_professor.mes > 12 ||
                             listaProfessor[i].data_professor.ano < 1900 || listaProfessor[i].data_professor.ano > 2025);

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
            printf("Não existe profesor com essa matrícula!\n");
        }

        if (optionprofessor != 0)
        {
            printf("\n Deseja atualizar outro campo? (1- SIM / 0 - NAO): ");
            scanf(" %d", &atualizando);
            getchar();
        }
    }
}
int excluirProf(int qtdProf, Professor listaProfessor[])
{
    printf("Digite a matricula do professor para exclusão:\n");
    int matricula;
    scanf("%d", &matricula);

    for (int i = 0; i < qtdProf; i++)
    {
        if (listaProfessor[i].matricula == matricula)
        {
            for (int j = i; j < qtdProf - 1; j++)
            {
                listaProfessor[j] = listaProfessor[j + 1];
            }
            return qtdProf - 1;
        }
    }

    return -1;
}

// Funções Disciplina

int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, int *incrementadorCodigoDisciplina, Professor listaProfessor[], int qtdProf)
{
    if (qtdDisciplina >= TAM_CADASTRO)
    {
        printf("Lista de disciplinas cheia.\n");
        return 0;
    }

    printf("\n--- Cadastro de Disciplina ---\n");

    // Nome da disciplina
    printf("Digite o nome da disciplina: ");
    fgets(listaDisciplina[qtdDisciplina].nome, TAM_MAX_NOME, stdin);
    listaDisciplina[qtdDisciplina].nome[strcspn(listaDisciplina[qtdDisciplina].nome, "\n")] = '\0';

    // Semestre
    do
    {
        printf("Qual semestre está a disciplina? (1 a 6): ");
        scanf("%d", &listaDisciplina[qtdDisciplina].semestre);
        getchar();
        if (listaDisciplina[qtdDisciplina].semestre < 1 || listaDisciplina[qtdDisciplina].semestre > 6)
        {
            printf("Semestre inválido! Digite de 1 a 6.\n");
        }
    } while (listaDisciplina[qtdDisciplina].semestre < 1 || listaDisciplina[qtdDisciplina].semestre > 6);

    // Professor
    if (qtdProf == 0)
    {
        printf("Não há professores cadastrados.\n");
        return 0;
    }

    printf("\nProfessores disponíveis:\n");
    for (int i = 0; i < qtdProf; i++)
    {
        printf("Matrícula: %d - Nome: %s\n", listaProfessor[i].matricula, listaProfessor[i].nome);
    }

    int encontrou = 0, matriculaProf;
    do
    {
        printf("Digite a matrícula do professor da disciplina: ");
        scanf("%d", &matriculaProf);
        getchar();
        for (int i = 0; i < qtdProf; i++)
        {
            if (listaProfessor[i].matricula == matriculaProf)
            {
                listaDisciplina[qtdDisciplina].matriculaProfessor = matriculaProf;
                encontrou = 1;
                break;
            }
        }
        if (!encontrou)
        {
            printf("Professor não encontrado. Tente novamente.\n");
        }
    } while (!encontrou);

    listaDisciplina[qtdDisciplina].codigo = (*incrementadorCodigoDisciplina)++;
    listaDisciplina[qtdDisciplina].qtdAlunos = 0;
    printf("\nDisciplina cadastrada com sucesso!\n");
    printf("Código: %d - Nome: %s\n", listaDisciplina[qtdDisciplina].codigo, listaDisciplina[qtdDisciplina].nome);

    return 1;
}

void listarDisciplinas(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[])
{
    if (qtdDisciplina == 0)
    {
        printf("\nNão há disciplinas cadastradas!\n");
        return;
    }

    printf("\n--- Lista de Disciplinas ---\n");
    for (int i = 0; i < qtdDisciplina; i++)
    {
        printf("Código: %d - %s (Semestre: %d)\n",
               listaDisciplina[i].codigo,
               listaDisciplina[i].nome,
               listaDisciplina[i].semestre);

        // Encontrar professor
        for (int j = 0; j < TAM_CADASTRO; j++)
        {
            if (listaProfessor[j].matricula == listaDisciplina[i].matriculaProfessor)
            {
                printf("Professor: %s\n", listaProfessor[j].nome);
                break;
            }
        }
        printf("Alunos matriculados: %d/%d\n\n", listaDisciplina[i].qtdAlunos, TAM_CADASTRO);
    }
}

void listarDisciplinaCompleta(Disciplina disciplina, Professor listaProfessor[], int qtdProf)
{
    printf("\n--- Detalhes da Disciplina ---\n");
    printf("Código: %d\n", disciplina.codigo);
    printf("Nome: %s\n", disciplina.nome);
    printf("Semestre: %d\n", disciplina.semestre);

    // Professor
    int profEncontrado = 0;
    for (int i = 0; i < qtdProf; i++)
    {
        if (listaProfessor[i].matricula == disciplina.matriculaProfessor)
        {
            printf("Professor: %s (Matrícula: %d)\n",
                   listaProfessor[i].nome,
                   listaProfessor[i].matricula);
            profEncontrado = 1;
            break;
        }
    }
    if (!profEncontrado)
    {
        printf("Professor não encontrado!\n");
    }

    // Alunos
    printf("\nAlunos matriculados (%d/%d):\n", disciplina.qtdAlunos, TAM_CADASTRO);
    if (disciplina.qtdAlunos == 0)
    {
        printf("Nenhum aluno matriculado.\n");
    }
    else
    {
        for (int i = 0; i < disciplina.qtdAlunos; i++)
        {
            printf("- %s (Matrícula: %d)\n",
                   disciplina.alunosMatriculados[i].nome,
                   disciplina.alunosMatriculados[i].matricula);
        }
    }
}

void inserirAlunoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Aluno listaAluno[], int qtdAluno)
{
    if (qtdDisciplina == 0)
    {
        printf("\nNão há disciplinas cadastradas!\n");
        return;
    }

    if (qtdAluno == 0)
    {
        printf("\nNão há alunos cadastrados!\n");
        return;
    }

    // Listar disciplinas
    printf("\nDisciplinas disponíveis:\n");
    for (int i = 0; i < qtdDisciplina; i++)
    {
        printf("Código: %d - %s (Vagas: %d/%d)\n",
               listaDisciplina[i].codigo,
               listaDisciplina[i].nome,
               TAM_CADASTRO - listaDisciplina[i].qtdAlunos,
               TAM_CADASTRO);
    }

    // Selecionar disciplina
    int codigoDisciplina;
    printf("\nDigite o código da disciplina: ");
    scanf("%d", &codigoDisciplina);
    getchar();

    int discIndex = -1;
    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (listaDisciplina[i].codigo == codigoDisciplina)
        {
            discIndex = i;
            break;
        }
    }

    if (discIndex == -1)
    {
        printf("\nDisciplina não encontrada!\n");
        return;
    }

    // Verificar vagas
    if (listaDisciplina[discIndex].qtdAlunos >= TAM_CADASTRO)
    {
        printf("\nEsta disciplina já está lotada! (Máximo: %d alunos)\n", TAM_CADASTRO);
        return;
    }

    // Listar alunos
    printf("\nAlunos disponíveis:\n");
    for (int i = 0; i < qtdAluno; i++)
    {
        printf("Matrícula: %d - %s\n", listaAluno[i].matricula, listaAluno[i].nome);
    }

    // Selecionar aluno
    int matriculaAluno;
    printf("\nDigite a matrícula do aluno: ");
    scanf("%d", &matriculaAluno);
    getchar();

    // Verificar se aluno já está matriculado
    for (int i = 0; i < listaDisciplina[discIndex].qtdAlunos; i++)
    {
        if (listaDisciplina[discIndex].alunosMatriculados[i].matricula == matriculaAluno)
        {
            printf("\nEste aluno já está matriculado nesta disciplina!\n");
            return;
        }
    }

    // Encontrar aluno
    int alunoIndex = -1;
    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].matricula == matriculaAluno)
        {
            alunoIndex = i;
            break;
        }
    }

    if (alunoIndex == -1)
    {
        printf("\nAluno não encontrado!\n");
        return;
    }

    // Matricular aluno
    listaDisciplina[discIndex].alunosMatriculados[listaDisciplina[discIndex].qtdAlunos] = listaAluno[alunoIndex];
    listaDisciplina[discIndex].qtdAlunos++;

    printf("\nAluno matriculado com sucesso!\n");
    printf("Disciplina: %s\n", listaDisciplina[discIndex].nome);
    printf("Aluno: %s (Matrícula: %d)\n", listaAluno[alunoIndex].nome, listaAluno[alunoIndex].matricula);
}

void excluirAlunoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina)
{
    if (qtdDisciplina == 0)
    {
        printf("\nNão há disciplinas cadastradas!\n");
        return;
    }

    // Listar disciplinas
    printf("\nDisciplinas disponíveis:\n");
    for (int i = 0; i < qtdDisciplina; i++)
    {
        printf("Código: %d - %s\n", listaDisciplina[i].codigo, listaDisciplina[i].nome);
    }

    // Selecionar disciplina
    int codigoDisciplina;
    printf("\nDigite o código da disciplina: ");
    scanf("%d", &codigoDisciplina);
    getchar();

    int discIndex = -1;
    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (listaDisciplina[i].codigo == codigoDisciplina)
        {
            discIndex = i;
            break;
        }
    }

    if (discIndex == -1)
    {
        printf("\nDisciplina não encontrada!\n");
        return;
    }

    if (listaDisciplina[discIndex].qtdAlunos == 0)
    {
        printf("\nNão há alunos matriculados nesta disciplina!\n");
        return;
    }

    // Listar alunos matriculados
    printf("\nAlunos matriculados:\n");
    for (int i = 0; i < listaDisciplina[discIndex].qtdAlunos; i++)
    {
        printf("Matrícula: %d - %s\n",
               listaDisciplina[discIndex].alunosMatriculados[i].matricula,
               listaDisciplina[discIndex].alunosMatriculados[i].nome);
    }

    // Selecionar aluno para remover
    int matriculaAluno;
    printf("\nDigite a matrícula do aluno a ser removido: ");
    scanf("%d", &matriculaAluno);
    getchar();

    // Procurar aluno
    int alunoIndex = -1;
    for (int i = 0; i < listaDisciplina[discIndex].qtdAlunos; i++)
    {
        if (listaDisciplina[discIndex].alunosMatriculados[i].matricula == matriculaAluno)
        {
            alunoIndex = i;
            break;
        }
    }

    if (alunoIndex == -1)
    {
        printf("\nAluno não encontrado nesta disciplina!\n");
        return;
    }

    // Remover aluno
    for (int i = alunoIndex; i < listaDisciplina[discIndex].qtdAlunos - 1; i++)
    {
        listaDisciplina[discIndex].alunosMatriculados[i] = listaDisciplina[discIndex].alunosMatriculados[i + 1];
    }
    listaDisciplina[discIndex].qtdAlunos--;

    printf("\nAluno removido com sucesso!\n");
}

int excluirDisciplina(Disciplina listaDisciplina[], int qtdDisciplina)
{
    if (qtdDisciplina == 0)
    {
        printf("\nNão há disciplinas cadastradas!\n");
        return qtdDisciplina;
    }

    // Listar disciplinas
    printf("\nDisciplinas cadastradas:\n");
    for (int i = 0; i < qtdDisciplina; i++)
    {
        printf("Código: %d - %s\n", listaDisciplina[i].codigo, listaDisciplina[i].nome);
    }

    // Selecionar disciplina
    int codigoDisciplina;
    printf("\nDigite o código da disciplina a ser excluída: ");
    scanf("%d", &codigoDisciplina);
    getchar();

    // Procurar disciplina
    int discIndex = -1;
    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (listaDisciplina[i].codigo == codigoDisciplina)
        {
            discIndex = i;
            break;
        }
    }

    if (discIndex == -1)
    {
        printf("\nDisciplina não encontrada!\n");
        return qtdDisciplina;
    }

    // Confirmar exclusão
    printf("\nTem certeza que deseja excluir a disciplina %s? (1-Sim / 0-Não): ", listaDisciplina[discIndex].nome);
    int confirmacao;
    scanf("%d", &confirmacao);
    getchar();

    if (confirmacao != 1)
    {
        printf("\nOperação cancelada.\n");
        return qtdDisciplina;
    }

    // Remover disciplina
    for (int i = discIndex; i < qtdDisciplina - 1; i++)
    {
        listaDisciplina[i] = listaDisciplina[i + 1];
    }

    printf("\nDisciplina excluída com sucesso!\n");
    return qtdDisciplina - 1;
}

// Funções Menu
int menuPrincipal()
{
    int option;
    printf("--------> MENU ESCOLA <-------\n");
    printf("##############################\n");
    printf(" 1 -> Portal do Aluno. <-\n");
    printf(" 2 -> Portal do Professor. <- \n");
    printf(" 3 -> Portal da Disciplina. <-\n");
    printf(" 4 -> Relatorios. <-\n");
    printf(" 0 -> Sair do Programa. <-\n\n");
    scanf("%d", &option);
    return option;
}
int menuAluno()
{
    int optionAluno;
    printf("#########################\n");
    printf("1 --> Cadastrar aluno. <--\n");
    printf("2 --> Listar aluno. <--\n");
    printf("3 --> Atualizar aluno. <--\n");
    printf("4 --> Excluir aluno. <--\n");
    printf("0 --> Voltar para o PORTAL. <--\n\n");
    scanf("%d", &optionAluno);
    getchar();
    return optionAluno;
}
int menuDisciplina()
{
    int option;
    printf("\n--> MODULO DISCIPLINA <--\n");
    printf("#########################\n");
    printf("1 --> Cadastrar disciplina\n");
    printf("2 --> Listar disciplinas\n");
    printf("3 --> Listar disciplina detalhada\n");
    printf("4 --> Inserir aluno em disciplina\n");
    printf("5 --> Remover aluno de disciplina\n");
    printf("6 --> Excluir disciplina\n");
    printf("0 --> Voltar para o menu principal\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);
    getchar();
    return option;
}
int menuRelatorios()
{
    int option;
    printf("\n--> MENU DE RELATORIOS <--\n");
    printf("##########################\n");
    printf("1  --> Listar Alunos\n");
    printf("2  --> Listar Professores\n");
    printf("3  --> Listar Disciplinas (sem alunos)\n");
    printf("4  --> Listar uma disciplina (com alunos)\n");
    printf("5  --> Listar Alunos por sexo\n");
    printf("6  --> Listar Alunos ordenados por Nome\n");
    printf("7  --> Listar Alunos ordenados por Data de Nascimento\n");
    printf("8  --> Listar Professores por sexo\n");
    printf("9  --> Listar Professores ordenados por Nome\n");
    printf("10 --> Listar Professores ordenados por Data de Nascimento\n");
    printf("11 --> Aniversariantes do mês\n");
    printf("12 --> Buscar pessoas por nome\n");
    printf("13 --> Listar Alunos com menos de 3 disciplinas\n");
    printf("14 --> Listar Disciplinas com mais de 2 vagas ocupadas\n");
    printf("0  --> Voltar para o menu principal\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);
    getchar();
    return option;
}

// Funções Lista

void listarAlunosPorSexo(Aluno listaAluno[], int qtdAluno)
{
    if (qtdAluno == 0)
    {
        printf("\nNão há alunos cadastrados!\n");
        return;
    }

    char sexo;
    printf("\nDigite o sexo para filtrar (M/F): ");
    scanf(" %c", &sexo);
    getchar();
    sexo = toupper(sexo);

    if (sexo != 'M' && sexo != 'F')
    {
        printf("Sexo inválido! Use M ou F.\n");
        return;
    }

    printf("\n--- Alunos do sexo %c ---\n", sexo);
    int encontrou = 0;
    for (int i = 0; i < qtdAluno; i++)
    {
        if (toupper(listaAluno[i].sexo) == sexo)
        {
            printf("Matrícula: %d - Nome: %s\n",
                   listaAluno[i].matricula, listaAluno[i].nome);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhum aluno encontrado com esse sexo.\n");
    }
}

void listarAlunosPorNome(Aluno listaAluno[], int qtdAluno)
{
    if (qtdAluno == 0)
    {
        printf("\nNão há alunos cadastrados!\n");
        return;
    }

    // Criar cópia para ordenação
    Aluno copia[TAM_CADASTRO];
    for (int i = 0; i < qtdAluno; i++)
    {
        copia[i] = listaAluno[i];
    }

    // Ordenação por nome (bubble sort)
    for (int i = 0; i < qtdAluno - 1; i++)
    {
        for (int j = 0; j < qtdAluno - i - 1; j++)
        {
            if (strcmp(copia[j].nome, copia[j + 1].nome) > 0)
            {
                Aluno temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("\n--- Alunos ordenados por nome ---\n");
    for (int i = 0; i < qtdAluno; i++)
    {
        printf("%s (Matrícula: %d)\n", copia[i].nome, copia[i].matricula);
    }
}

void listarAlunosPorNascimento(Aluno listaAluno[], int qtdAluno)
{
    if (qtdAluno == 0)
    {
        printf("\nNão há alunos cadastrados!\n");
        return;
    }

    // Criar cópia para ordenação
    Aluno copia[TAM_CADASTRO];
    for (int i = 0; i < qtdAluno; i++)
    {
        copia[i] = listaAluno[i];
    }

    // Ordenação por data (bubble sort)
    for (int i = 0; i < qtdAluno - 1; i++)
    {
        for (int j = 0; j < qtdAluno - i - 1; j++)
        {
            // Compara ano
            if (copia[j].data_aluno.ano > copia[j + 1].data_aluno.ano ||
                // Se ano igual, compara mês
                (copia[j].data_aluno.ano == copia[j + 1].data_aluno.ano &&
                 copia[j].data_aluno.mes > copia[j + 1].data_aluno.mes) ||
                // Se ano e mês iguais, compara dia
                (copia[j].data_aluno.ano == copia[j + 1].data_aluno.ano &&
                 copia[j].data_aluno.mes == copia[j + 1].data_aluno.mes &&
                 copia[j].data_aluno.dia > copia[j + 1].data_aluno.dia))
            {
                Aluno temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("\n--- Alunos ordenados por data de nascimento ---\n");
    for (int i = 0; i < qtdAluno; i++)
    {
        printf("%02d/%02d/%04d - %s (Matrícula: %d)\n",
               copia[i].data_aluno.dia, copia[i].data_aluno.mes, copia[i].data_aluno.ano,
               copia[i].nome, copia[i].matricula);
    }
}

void listarProfessoresPorSexo(Professor listaProfessor[], int qtdProf)
{
    if (qtdProf == 0)
    {
        printf("\nNão há professores cadastrados!\n");
        return;
    }

    char sexo;
    printf("\nDigite o sexo para filtrar (M/F): ");
    scanf(" %c", &sexo);
    getchar();
    sexo = toupper(sexo);

    if (sexo != 'M' && sexo != 'F')
    {
        printf("Sexo inválido! Use M ou F.\n");
        return;
    }

    printf("\n--- Professores do sexo %c ---\n", sexo);
    int encontrou = 0;
    for (int i = 0; i < qtdProf; i++)
    {
        if (toupper(listaProfessor[i].sexo) == sexo)
        {
            printf("Matrícula: %d - Nome: %s\n",
                   listaProfessor[i].matricula, listaProfessor[i].nome);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhum professor encontrado com esse sexo.\n");
    }
}

void listarProfessoresPorNome(Professor listaProfessor[], int qtdProf)
{
    if (qtdProf == 0)
    {
        printf("\nNão há professores cadastrados!\n");
        return;
    }

    // Criar cópia para ordenação
    Professor copia[TAM_CADASTRO];
    for (int i = 0; i < qtdProf; i++)
    {
        copia[i] = listaProfessor[i];
    }

    // Ordenação por nome (bubble sort)
    for (int i = 0; i < qtdProf - 1; i++)
    {
        for (int j = 0; j < qtdProf - i - 1; j++)
        {
            if (strcmp(copia[j].nome, copia[j + 1].nome) > 0)
            {
                Professor temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("\n--- Professores ordenados por nome ---\n");
    for (int i = 0; i < qtdProf; i++)
    {
        printf("%s (Matrícula: %d)\n", copia[i].nome, copia[i].matricula);
    }
}

void listarProfessoresPorNascimento(Professor listaProfessor[], int qtdProf)
{
    if (qtdProf == 0)
    {
        printf("\nNão há professores cadastrados!\n");
        return;
    }

    // Criar cópia para ordenação
    Professor copia[TAM_CADASTRO];
    for (int i = 0; i < qtdProf; i++)
    {
        copia[i] = listaProfessor[i];
    }

    // Ordenação por data (bubble sort)
    for (int i = 0; i < qtdProf - 1; i++)
    {
        for (int j = 0; j < qtdProf - i - 1; j++)
        {
            if (copia[j].data_professor.ano > copia[j + 1].data_professor.ano ||
                (copia[j].data_professor.ano == copia[j + 1].data_professor.ano &&
                 copia[j].data_professor.mes > copia[j + 1].data_professor.mes) ||
                (copia[j].data_professor.ano == copia[j + 1].data_professor.ano &&
                 copia[j].data_professor.mes == copia[j + 1].data_professor.mes &&
                 copia[j].data_professor.dia > copia[j + 1].data_professor.dia))
            {
                Professor temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("\n--- Professores ordenados por data de nascimento ---\n");
    for (int i = 0; i < qtdProf; i++)
    {
        printf("%02d/%02d/%04d - %s (Matrícula: %d)\n",
               copia[i].data_professor.dia, copia[i].data_professor.mes, copia[i].data_professor.ano,
               copia[i].nome, copia[i].matricula);
    }
}

void listarAniversariantesMes(Aluno listaAluno[], int qtdAluno, Professor listaProfessor[], int qtdProf)
{
    int mes;
    printf("\nDigite o mês (1-12): ");
    scanf("%d", &mes);
    getchar();

    if (mes < 1 || mes > 12)
    {
        printf("Mês inválido!\n");
        return;
    }

    printf("\n--- Aniversariantes do mês %d ---\n", mes);

    // Alunos
    printf("\nAlunos:\n");
    int encontrouAluno = 0;
    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].data_aluno.mes == mes)
        {
            printf("%02d/%02d - %s (Matrícula: %d)\n",
                   listaAluno[i].data_aluno.dia, listaAluno[i].data_aluno.mes,
                   listaAluno[i].nome, listaAluno[i].matricula);
            encontrouAluno = 1;
        }
    }
    if (!encontrouAluno)
    {
        printf("Nenhum aluno encontrado.\n");
    }

    // Professores
    printf("\nProfessores:\n");
    int encontrouProf = 0;
    for (int i = 0; i < qtdProf; i++)
    {
        if (listaProfessor[i].data_professor.mes == mes)
        {
            printf("%02d/%02d - %s (Matrícula: %d)\n",
                   listaProfessor[i].data_professor.dia, listaProfessor[i].data_professor.mes,
                   listaProfessor[i].nome, listaProfessor[i].matricula);
            encontrouProf = 1;
        }
    }
    if (!encontrouProf)
    {
        printf("Nenhum professor encontrado.\n");
    }
}

void buscarPessoaPorNome(Aluno listaAluno[], int qtdAluno, Professor listaProfessor[], int qtdProf)
{
    if (qtdAluno == 0 && qtdProf == 0)
    {
        printf("\nNão há pessoas cadastradas!\n");
        return;
    }

    char nomeBusca[TAM_MAX_NOME];
    printf("\nDigite pelo menos 3 letras do nome: ");
    fgets(nomeBusca, TAM_MAX_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    if (strlen(nomeBusca) < 3)
    {
        printf("Digite pelo menos 3 caracteres!\n");
        return;
    }

    printf("\n--- Resultados da busca por '%s' ---\n", nomeBusca);

    // Buscar alunos
    printf("\nAlunos:\n");
    int encontrouAluno = 0;
    for (int i = 0; i < qtdAluno; i++)
    {
        if (strstr(listaAluno[i].nome, nomeBusca) != NULL)
        {
            printf("- %s (Matrícula: %d)\n", listaAluno[i].nome, listaAluno[i].matricula);
            encontrouAluno = 1;
        }
    }
    if (!encontrouAluno)
    {
        printf("Nenhum aluno encontrado.\n");
    }

    // Buscar professores
    printf("\nProfessores:\n");
    int encontrouProf = 0;
    for (int i = 0; i < qtdProf; i++)
    {
        if (strstr(listaProfessor[i].nome, nomeBusca) != NULL)
        {
            printf("- %s (Matrícula: %d)\n", listaProfessor[i].nome, listaProfessor[i].matricula);
            encontrouProf = 1;
        }
    }
    if (!encontrouProf)
    {
        printf("Nenhum professor encontrado.\n");
    }
}

void listarAlunosPoucasDisciplinas(Aluno listaAluno[], int qtdAluno, Disciplina listaDisciplina[], int qtdDisciplina)
{
    if (qtdAluno == 0)
    {
        printf("\nNão há alunos cadastrados!\n");
        return;
    }

    printf("\n--- Alunos com menos de 3 disciplinas ---\n");

    for (int i = 0; i < qtdAluno; i++)
    {
        int count = 0;

        // Contar em quantas disciplinas o aluno está matriculado
        for (int j = 0; j < qtdDisciplina; j++)
        {
            for (int k = 0; k < listaDisciplina[j].qtdAlunos; k++)
            {
                if (listaDisciplina[j].alunosMatriculados[k].matricula == listaAluno[i].matricula)
                {
                    count++;
                    break; // Sai do loop interno se encontrou em uma disciplina
                }
            }
        }

        if (count < 3)
        {
            printf("%s (Matrícula: %d) - %d disciplina(s)\n",
                   listaAluno[i].nome, listaAluno[i].matricula, count);
        }
    }
}

void listarDisciplinasLotadas(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[])
{
    if (qtdDisciplina == 0)
    {
        printf("\nNão há disciplinas cadastradas!\n");
        return;
    }

    printf("\n--- Disciplinas com mais de 2 vagas ocupadas ---\n");

    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (listaDisciplina[i].qtdAlunos > 2)
        {
            printf("\n%s (Código: %d)\n", listaDisciplina[i].nome, listaDisciplina[i].codigo);
            printf("Semestre: %d\n", listaDisciplina[i].semestre);

            // Encontrar professor
            for (int j = 0; j < TAM_CADASTRO; j++)
            {
                if (listaProfessor[j].matricula == listaDisciplina[i].matriculaProfessor)
                {
                    printf("Professor: %s\n", listaProfessor[j].nome);
                    break;
                }
            }

            printf("Alunos matriculados: %d/%d\n",
                   listaDisciplina[i].qtdAlunos, TAM_CADASTRO);
        }
    }
}

int main()
{
    Aluno listaAluno[TAM_CADASTRO];           // VETOR ALUNOS
    Professor listaProfessor[TAM_CADASTRO];   // VETOR DISCPLINA
    Disciplina listaDisciplina[TAM_CADASTRO]; // VETOR DISCIPLINA

    int option;
    int out = 0;
    int qtdAluno = 0;
    int qtdProf = 0;
    int qtdDisciplina = 0;
    int incrementadorMatricula = 0;
    int incrementadorMatriculaProf = 0;
    int incrementadorCodigoDisciplina = 1;

    while (!out)
    {
        option = menuPrincipal();

        switch (option)
        {
        case 1: // MODULO ALUNO
        {
            int optionAluno;
            int outAluno = 0;
            printf(" ---> PORTAL ALUNO <---\n");

            while (!outAluno)
            {
                optionAluno = menuAluno();

                switch (optionAluno)
                {
                case 1: // CADASTRO ALUNO
                    if (qtdAluno < TAM_CADASTRO)
                    {
                        int retorno = cadastrarAluno(listaAluno, qtdAluno, incrementadorMatricula);
                        if (retorno == 1)
                        {
                            printf("Cadastro concluido!\n");
                            ++incrementadorMatricula;
                            ++qtdAluno;
                        }
                    }
                    else
                    {
                        printf("Lista de aluno cheia. \n\n");
                    }
                    break;

                case 2: // LISTAR ALUNO
                    if (qtdAluno == 0)
                    {
                        printf("Nao ha aluno cadastrado!\n ");
                    }
                    else
                    {
                        listarAluno(qtdAluno, listaAluno);
                    }
                    break;

                case 3: // ATUALIZAR ALUNO
                    if (qtdAluno == 0)
                    {
                        printf("Nao ha alunos cadastrados! \n");
                    }
                    else
                    {
                        atualizarAluno(qtdAluno, listaAluno);
                    }
                    break;

                case 4: // EXCLUSÃO
                    if (qtdAluno == 0)
                    {
                        printf("Nao ha alunos cadastrados!\n");
                    }
                    else
                    {
                        qtdAluno = excluirAluno(qtdAluno, listaAluno);
                    }
                    break;

                case 0: // SAIR DO PORTAL ALUNO
                    printf("Voltando ao menu principal ... \n");
                    outAluno = 1;
                    break;

                default:
                    printf("Opcao Invalida\n");
                    break;
                }
            }
            break;
        }

        case 2: // MODULO PROFESSOR
        {
            int optionprofessor;

            int outProf = 0;

            printf("---> PORTAL PROFESSOR <---\n");

            while (!outProf)
            {
                printf("#########################\n");
                printf("1 --> Cadastrar professor. <--\n");
                printf("2 --> Listar professor. <--\n");
                printf("3 --> Atualizar professor. <--\n");
                printf("4 --> Excluir professor. <--\n");
                printf("0 --> Voltar para o PORTAL. <--\n\n");
                scanf("%d", &optionprofessor);
                getchar();

                switch (optionprofessor)
                {
                case 1:
                {
                    int retornoProf = cadastrarProf(listaProfessor, qtdProf, incrementadorMatriculaProf);

                    if (retornoProf == 1)
                    {
                        printf("Cadastro concluido!\n");
                        qtdProf++;
                        incrementadorMatriculaProf++;
                    }
                    else
                    {
                        printf("Lista de professores cheia. \n\n");
                    }
                    break;
                }
                case 2:
                {
                    if (qtdProf == 0)
                    {
                        printf("Nao ha professor cadastrados! \n");
                        break;
                    }

                    listarProf(qtdProf, listaProfessor);
                    break;
                }
                case 3:
                {

                    if (qtdProf == 0)
                    {
                        printf("Nao ha professor cadastrados! \n");
                        break;
                    }

                    printf("-> Atualizar Prefessor: \n");
                    printf("#### Todos os Professores\n");
                    listarProf(qtdProf, listaProfessor);
                    attProf(qtdProf, listaProfessor);
                    break;
                }
                case 4: // EXcluir professor
                {

                    if (qtdProf == 0)
                    {
                        printf("Nao ha professor cadastrados!\n");
                        break;
                    }

                    listarProf(qtdProf, listaProfessor);

                    int novoQtd = excluirProf(qtdProf, listaProfessor);

                    if (novoQtd == -1)
                    {
                        printf("Não existe Professor com essa matrícula.\n");
                    }
                    else
                    {
                        printf("Professor excluído com sucesso.\n");
                        qtdProf = novoQtd;
                    }
                    break;
                }
                case 0: //
                {
                    printf("Voltando ao menu principal ... \n");
                    outProf = 1;
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

        case 3: // MODULO DISCIPLINA
        {
            int outDisciplina = 0;
            while (!outDisciplina)
            {
                int optionDisc = menuDisciplina();

                switch (optionDisc)
                {
                case 1: // CADASTRAR DISCIPLINA
                    if (qtdDisciplina < TAM_CADASTRO)
                    {
                        if (cadastrarDisciplina(listaDisciplina, qtdDisciplina, &incrementadorCodigoDisciplina, listaProfessor, qtdProf))
                        {
                            qtdDisciplina++;
                        }
                    }
                    else
                    {
                        printf("Lista de disciplinas cheia!\n");
                    }
                    break;

                case 2: // LISTAR DISCIPLINAS
                    listarDisciplinas(listaDisciplina, qtdDisciplina, listaProfessor);
                    break;

                case 3: // LISTAR DISCIPLINA DETALHADA
                    if (qtdDisciplina > 0)
                    {
                        printf("\nDigite o código da disciplina: ");
                        int codigo;
                        scanf("%d", &codigo);
                        getchar();

                        int encontrou = 0;
                        for (int i = 0; i < qtdDisciplina; i++)
                        {
                            if (listaDisciplina[i].codigo == codigo)
                            {
                                listarDisciplinaCompleta(listaDisciplina[i], listaProfessor, qtdProf);
                                encontrou = 1;
                                break;
                            }
                        }
                        if (!encontrou)
                        {
                            printf("Disciplina não encontrada!\n");
                        }
                    }
                    else
                    {
                        printf("Não há disciplinas cadastradas!\n");
                    }
                    break;

                case 4: // INSERIR ALUNO EM DISCIPLINA
                    inserirAlunoDisciplina(listaDisciplina, qtdDisciplina, listaAluno, qtdAluno);
                    break;

                case 5: // REMOVER ALUNO DE DISCIPLINA
                    excluirAlunoDisciplina(listaDisciplina, qtdDisciplina);
                    break;

                case 6: // EXCLUIR DISCIPLINA
                    qtdDisciplina = excluirDisciplina(listaDisciplina, qtdDisciplina);
                    break;

                case 0: // VOLTAR
                    outDisciplina = 1;
                    printf("Voltando para o menu principal...\n");
                    break;

                default:
                    printf("Opção inválida!\n");
                    break;
                }
            }
            break;
        }
        case 4: // RELATÓRIOS
        {
            int outRelatorios = 0;
            while (!outRelatorios)
            {
                int opcao = menuRelatorios();

                switch (opcao)
                {
                case 1: // Listar Alunos
                    listarAluno(qtdAluno, listaAluno);
                    break;

                case 2: // Listar Professores
                    listarProf(qtdProf, listaProfessor);
                    break;

                case 3: // Listar Disciplinas (sem alunos)
                    listarDisciplinas(listaDisciplina, qtdDisciplina, listaProfessor);
                    break;

                case 4: // Listar uma disciplina (com alunos)
                    if (qtdDisciplina > 0)
                    {
                        printf("\nDigite o código da disciplina: ");
                        int codigo;
                        scanf("%d", &codigo);
                        getchar();

                        int encontrou = 0;
                        for (int i = 0; i < qtdDisciplina; i++)
                        {
                            if (listaDisciplina[i].codigo == codigo)
                            {
                                listarDisciplinaCompleta(listaDisciplina[i], listaProfessor, qtdProf);
                                encontrou = 1;
                                break;
                            }
                        }
                        if (!encontrou)
                        {
                            printf("Disciplina não encontrada!\n");
                        }
                    }
                    else
                    {
                        printf("Não há disciplinas cadastradas!\n");
                    }
                    break;

                case 5: // Listar Alunos por sexo
                    listarAlunosPorSexo(listaAluno, qtdAluno);
                    break;

                case 6: // Listar Alunos por nome
                    listarAlunosPorNome(listaAluno, qtdAluno);
                    break;

                case 7: // Listar Alunos por nascimento
                    listarAlunosPorNascimento(listaAluno, qtdAluno);
                    break;

                case 8: // Listar Professores por sexo
                    listarProfessoresPorSexo(listaProfessor, qtdProf);
                    break;

                case 9: // Listar Professores por nome
                    listarProfessoresPorNome(listaProfessor, qtdProf);
                    break;

                case 10: // Listar Professores por nascimento
                    listarProfessoresPorNascimento(listaProfessor, qtdProf);
                    break;

                case 11: // Aniversariantes do mês
                    listarAniversariantesMes(listaAluno, qtdAluno, listaProfessor, qtdProf);
                    break;

                case 12: // Buscar pessoas por nome
                    buscarPessoaPorNome(listaAluno, qtdAluno, listaProfessor, qtdProf);
                    break;

                case 13: // Alunos com menos de 3 disciplinas
                    listarAlunosPoucasDisciplinas(listaAluno, qtdAluno, listaDisciplina, qtdDisciplina);
                    break;

                case 14: // Disciplinas com mais de 2 vagas ocupadas
                    listarDisciplinasLotadas(listaDisciplina, qtdDisciplina, listaProfessor);
                    break;

                case 0: // Voltar
                    outRelatorios = 1;
                    printf("Voltando para o menu principal...\n");
                    break;

                default:
                    printf("Opção inválida!\n");
                    break;
                }
            }
            break;
        }
        }
    }
    return 0;
}
