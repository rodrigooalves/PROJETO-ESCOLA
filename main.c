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

typedef struct {
    char nome[TAM_MAX_NOME];
    int matriculaProfessor; // Store professor's matricula
    int codigo;
    int semestre;
} Disciplina;

//##############################################
//MODULO - ALUNO
int cadastrarAluno(Aluno listaAluno[], int qtdAluno, int incrementadorMatricula){

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

void excluirProf(int qtdProf, Professor listaProfessor[], int encontrou_matricula)
{

    printf("Digite a matrícula do professor para exclusão:\n");
    int matricula;
    scanf("%d", &matricula);
    for (int i = 0; i < qtdProf; i++)
    {
        if (listaProfessor[i].matricula == matricula)
        {
            encontrou_matricula = 1;
            for (int j = i; j < qtdProf - 1; j++)
            {
                listaProfessor[j] = listaProfessor[j + 1];
            }
        }
    }
}

void listarSexo (int qtdAluno, Aluno listaAluno[]) {
    char sexo; 

    int encontrou = 0;

    printf("Digite o sexo para listar (M/F): ");
    scanf(" %c", &sexo); 
    getchar(); 

    if ( sexo != 'M' || sexo != 'F' || sexo != 'm' || sexo != 'f'){
        printf("Sexo invalido! Use M ou F.\n");
        return;
    }

        for (int i = 0; i < qtdAluno; i++){
            if (listaAluno[i].sexo == sexo ){
                printf("- %s\n", alunos[i].nome);
                encontrou =1; 
            }
        }
        if (!encontrou) {
            printf("Nenhum aluno encontrado para o sexo informado.\n");
    }
}
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
int menuAtualizarAluno() {

    int optionAluno;
    printf("#########################\n");
    printf("1 --> Atualizar Nome. <--\n");
    printf("2 --> Atualizar CPF. <--\n");
    printf("3 --> Atualizar Sexo. <--\n");
    printf("4 --> Atualizar Data de nascimento. <--\n");
    printf("0 --> Voltar para o PORTAL. <--\n\n");
    scanf("%d", &optionAluno);
    getchar();
    return optionAluno;
}
int atualizarNome(Aluno listaAluno[], int qtdAluno, int matricula) {
    int encontrou = 0;
    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].matricula == matricula) {
            printf("Digite o novo nome do aluno: \n");
            fgets(listaAluno[i].nome, TAM_MAX_NOME, stdin);
            listaAluno[i].nome[strcspn(listaAluno[i].nome, "\n")] = '\0';
            printf("Nome atualizado com sucesso.\n");
            encontrou = 1;
            return 1;  // Moved this before the break for better practice
        }  
    }
    
    if (!encontrou) {
        printf("Matrícula inválida, tente novamente...\n");
        return 0;
    }
    return 0;
}
int atualizarCPF(Aluno listaAluno[], int qtdAluno, int matricula) {
    int encontrou = 0;
    for (int i = 0; i < qtdAluno; i++){
        if (listaAluno[i].matricula == matricula){
            printf("Digite o novo CPF (Apenas números):\n");
            fgets(listaAluno[i].cpf, TAM_CPF, stdin);
            listaAluno[i].cpf[strcspn(listaAluno[i].cpf, "\n")] = '\0';
            printf("CPF atualizado com sucesso.\n");
            encontrou = 1;
            break;
        } 
    }
    return encontrou;
}
void listarAluno(int qtdAluno, Aluno listaAluno[]){
    for (int i = 0; i < qtdAluno; i++){
        printf("Matricula: %d - Nome: %s, CPF: %s, Sexo: %c , Data de nascimento: %d/%d/%d. \n", listaAluno[i].matricula, listaAluno[i].nome,
                listaAluno[i].cpf, listaAluno[i].sexo,
                listaAluno[i].data_aluno.dia, listaAluno[i].data_aluno.mes, listaAluno[i].data_aluno.ano);
    }
}


//##############################################
//MODULO - PROFESSOR


//##############################################
//MODULO - DISCIPLINAS

// void listarDisciplina(int qtdDisciplna, Disciplina listarDisciplina[]) {
//     for(int i = 0; i < qtdDisciplina; i++) {
//         printf("%d - %s. Professor: %s\n", listaDisciplina[i].codigo, listaDisciplina[i].nome, listaProfessor[i].nome);
//     }
// }




int main(){
    Aluno listaAluno[TAM_CADASTRO];         // VETOR ALUNOS
    Professor listaProfessor[TAM_CADASTRO]; // VETOR DISCPLINA
    Disciplina listaDisciplina[TAM_CADASTRO]; // VETOR DISCIPLINA

    int option;
    int out = 0;
    int qtdAluno = 0;
    int qtdProf = 0;
    int qtdDisciplina = 0;
    int incrementadorMatricula = 0;
    int incrementadorMatriculaProf = 0;
    int incrementadorCodigoDisciplina = 0;

    while (!out)
    {
        option = menuPrincipal();

        switch (option)
        {
        case 1: // MODULO ALUNO //
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
                {
                    int retorno = cadastrarAluno(listaAluno, qtdAluno, incrementadorMatricula);
                    if (retorno == 1)
                    {
                        printf("Cadastro concluido!\n");
                        ++incrementadorMatricula;
                        ++qtdAluno;
                    }
                    else
                    {
                        printf("Lista de aluno cheia. \n\n");
                    }

                    break;
                }
                case 2: // LISTAR ALUNO
                {
                    if (qtdAluno == 0){
                        printf("Nao ha aluno cadastrado!\n "); 
                        break;}
                    listarAluno(qtdAluno, listaAluno);
                    break;
                }
                case 3: // ATUALIZAR ALUNO
                {
                    if (qtdAluno == 0) {
                        printf("Nao ha alunos cadastrados! \n");
                        break;
                    }
                    
                    printf("# Atualizar Aluno: #\n");
                    printf("# Listando todos os alunos: #\n");
                    listarAluno(qtdAluno,listaAluno);

                    while (!outAluno){
                        optionAluno = menuAtualizarAluno();

                        if (optionAluno == 0){
                            printf("Voltando ao menu principal ... \n");
                            outAluno = 1;
                            break;
                        }

                        printf("Digite a matrícula do aluno que deseja atualizar: ");
                        int matricula;
                        scanf("%d", &matricula);
                        getchar();

                        int encontrou = 0;
                        
                        switch (optionAluno){
                            case 1: { // ATUALIZAR NOME
                            
                                int retorno = atualizarNome(listaAluno, qtdAluno, matricula);
                                if (retorno == 1) {
                                    printf("Atualização concluída!\n");
                                    encontrou = 1;
                                } else {
                                    printf("Atualização falhou.\n");
                                }
                                break;
                            }
                            case 2:{ // ATUALIZAR CPF
                            
                                int retorno = atualizarCPF(listaAluno, qtdAluno, matricula);
                                if (retorno == 1) {
                                    printf("Atualizacao concluida!\n");
                                    encontrou = 1;
                                } else {
                                    printf("Atualizacao falhou!\n");
                                }
                                break;
                            }
                            case 3:{  // ATUALIZAR SEXO
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
                            }
                            case 4:{  // ATUALIZAR DATA DE NASCIMENTO
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
                            }
                            default: {
                                printf("Opção inválida!\n");
                                break;
                            }

                            if (!encontrou){
                                printf("Não existe aluno com essa matrícula!\n");
                            }
                        }
                        break;
                    }

                case 4: // EXCLUSÃO
                {
                    if (qtdAluno == 0)
                    {
                        printf("Nao ha aluno cadastrado\n");
                        break;
                    }

                    listarAluno(qtdAluno, listaAluno);

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
            break;
            }
        }

        case 2: // MODULO PROFESSOR
        {        int main() {
            Aluno listaAluno[TAM_CADASTRO];         // VETOR ALUNOS
            Professor listaProfessor[TAM_CADASTRO]; // VETOR PROFESSORES
            Disciplina listaDisciplina[TAM_CADASTRO]; // VETOR DISCIPLINAS
        
            int option;
            int out = 0;
            int qtdAluno = 0;
            int qtdProf = 0;
            int qtdDisciplina = 0;
            int incrementadorMatricula = 0;
            int incrementadorMatriculaProf = 0;
            int incrementadorCodigoDisciplina = 0;
        
            while (!out) {
                option = menuPrincipal();
        
                switch (option) {
                    case 1: { // MODULO ALUNO
                        int optionAluno;
                        int outAluno = 0;
                        printf(" ---> PORTAL ALUNO <---\n");
        
                        while (!outAluno) {
                            optionAluno = menuAluno();
        
                            switch (optionAluno) {
                                case 1: { // CADASTRO ALUNO
                                    int retorno = cadastrarAluno(listaAluno, qtdAluno, incrementadorMatricula);
                                    if (retorno == 1) {
                                        printf("Cadastro concluido!\n");
                                        ++incrementadorMatricula;
                                        ++qtdAluno;
                                    } else {
                                        printf("Lista de aluno cheia. \n\n");
                                    }
                                    break;
                                }
                                case 2: { // LISTAR ALUNO
                                    if (qtdAluno == 0) {
                                        printf("Nao ha aluno cadastrado!\n ");
                                        break;
                                    }
                                    listarAluno(qtdAluno, listaAluno);
                                    break;
                                }
                                case 3: { // ATUALIZAR ALUNO
                                    if (qtdAluno == 0) {
                                        printf("Nao ha alunos cadastrados! \n");
                                        break;
                                    }
        
                                    printf("# Atualizar Aluno: #\n");
                                    printf("# Listando todos os alunos: #\n");
                                    listarAluno(qtdAluno, listaAluno);
        
                                    while (!outAluno) {
                                        optionAluno = menuAtualizarAluno();
        
                                        if (optionAluno == 0) {
                                            printf("Voltando ao menu principal ... \n");
                                            outAluno = 1;
                                            break;
                                        }
        
                                        printf("Digite a matrícula do aluno que deseja atualizar: ");
                                        int matricula;
                                        scanf("%d", &matricula);
                                        getchar();
        
                                        int encontrou = 0;
        
                                        switch (optionAluno) {
                                            case 1: { // ATUALIZAR NOME
                                                int retorno = atualizarNome(listaAluno, qtdAluno, matricula);
                                                if (retorno == 1) {
                                                    printf("Atualização concluída!\n");
                                                    encontrou = 1;
                                                } else {
                                                    printf("Atualização falhou.\n");
                                                }
                                                break;
                                            }
                                            case 2: { // ATUALIZAR CPF
                                                int retorno = atualizarCPF(listaAluno, qtdAluno, matricula);
                                                if (retorno == 1) {
                                                    printf("Atualizacao concluida!\n");
                                                    encontrou = 1;
                                                } else {
                                                    printf("Atualizacao falhou!\n");
                                                }
                                                break;
                                            }
                                            case 3: { // ATUALIZAR SEXO
                                                for (int i = 0; i < qtdAluno; i++) {
                                                    if (listaAluno[i].matricula == matricula) {
                                                        do {
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
                                            }
                                            case 4: { // ATUALIZAR DATA DE NASCIMENTO
                                                for (int i = 0; i < qtdAluno; i++) {
                                                    if (listaAluno[i].matricula == matricula) {
                                                        do {
                                                            printf("Digite a nova data de nascimento (dd mm aaaa):\n");
                                                            scanf("%d %d %d", &listaAluno[i].data_aluno.dia, &listaAluno[i].data_aluno.mes, &listaAluno[i].data_aluno.ano);
                                                            getchar();
                                                            if (listaAluno[i].data_aluno.dia < 1 || listaAluno[i].data_aluno.dia > 31 ||
                                                                listaAluno[i].data_aluno.mes < 1 || listaAluno[i].data_aluno.mes > 12 ||
                                                                listaAluno[i].data_aluno.ano < 1900 || listaAluno[i].data_aluno.ano > 2025) {
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
                                            }
                                            default: {
                                                printf("Opção inválida!\n");
                                                break;
                                            }
                                        }
        
                                        if (!encontrou) {
                                            printf("Não existe aluno com essa matrícula!\n");
                                        }
                                    }
                                    break;
                                }
                                case 4: { // EXCLUSÃO
                                    if (qtdAluno == 0) {
                                        printf("Nao ha aluno cadastrado\n");
                                        break;
                                    }
        
                                    listarAluno(qtdAluno, listaAluno);
        
                                    printf("Digite a matrícula do aluno para exclusão:\n");
                                    int matricula;
                                    scanf("%d", &matricula);
        
                                    int encontrou_matricula = 0;
                                    for (int i = 0; i < qtdAluno; i++) {
                                        if (listaAluno[i].matricula == matricula) {
                                            encontrou_matricula = 1;
                                            for (int j = i; j < qtdAluno - 1; j++) {
                                                listaAluno[j] = listaAluno[j + 1];
                                            }
                                            qtdAluno--;
                                            break;
                                        }
                                    }
        
                                    if (encontrou_matricula) {
                                        printf("Aluno excluído com sucesso.\n");
                                    } else {
                                        printf("Não existe aluno com essa matrícula.\n");
                                    }
                                    break;
                                }
                                case 0: {
                                    printf("Voltando ao menu principal ... \n");
                                    outAluno = 1;
                                    break;
                                }
                                default: {
                                    printf("Opcao Invalida\n");
                                }
                            }
                        }
                        break;
                    }
                    case 2: { // MODULO PROFESSOR
                        // Código do módulo professor
                        break;
                    }
                    case 3: { // MODULO DISCIPLINA
                        // Código do módulo disciplina
                        break;
                    }
                    case 0: { // MODULO SAIR
                        printf("Saindo ... \n");
                        out = 1;
                        break;
                    }
                    default: {
                        printf("-> Opcao invalida <-\n");
                    }
                }
            }
            return 0;
        }
            int optionprofessor;

            int outProf = 0;

            printf("---> PORTAL PROFESSOR <---\n");

            while (!outProf)
            {
                /* code */
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
                        printf("Nao ha professor cadastrados! \n");
                        break;
                    }

                    listarProf(qtdProf, listaProfessor);

                    int encontrou_matricula = 0;

                    excluirProf(qtdProf, listaProfessor, encontrou_matricula)

                        if (encontrou_matricula)
                    {
                        printf("Professor excluído com sucesso.\n");
                        qtdProf--;
                    }
                    else
                    {
                        printf("Não existe Professor com essa matrícula.\n");
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
                break;
            }
        }

        case 3: 
        { // MODULO DISCIPLINA
            int outDisciplina = 0;
            int optionDisc;
            while (!outDisciplina)
            {
                printf(" --> MODULO DISCIPLINA\n");
                printf("1 --> Cadastrar disciplina\n");
                printf("2 --> Listar disciplina\n");
                printf("3 --> Atualizar disciplina\n");
                printf("4 --> Excluir disciplina\n");
                printf("0 --> Voltar para o menu principal\n");
                printf("Escolha uma opcao\n");
                scanf("%d", &optionDisc);
                getchar();

                switch (optionDisc)
                {

                case 1:
                { // CADASTRAR DISCIPLINA
                    if (qtdDisciplina < TAM_CADASTRO)
                    {
                        printf("Digite o nome da discplina: \n");
                        fgets(listaDisciplina[qtdDisciplina].nome, TAM_MAX_NOME, stdin);
                        listaDisciplina[qtdDisciplina].nome[strcspn(listaDisciplina[qtdDisciplina].nome, "\n")] = '\0';

                        // validar o semestre
                        do
                        {
                            printf("Qual semestre esta a disciplina? ( DE 1 A 6 ):\n ");
                            scanf("%d", &listaDisciplina[qtdDisciplina].semestre);
                            getchar();

                            if (listaDisciplina[qtdDisciplina].semestre < 1 || listaDisciplina[qtdDisciplina].semestre > 6)
                            {
                                printf("Semestre invalido! Digite de 1 a 6\n");
                            }
                        } while (listaDisciplina[qtdDisciplina].semestre < 1 || listaDisciplina[qtdDisciplina].semestre > 6);

                        if (qtdProf == 0)
                        {
                            printf("Nao ha professores cadastrados \n");
                            break;
                        }

                        // LISTAR PROFESSORES DISPONIVEIS
                        for (int i = 0; i < qtdProf; i++)
                        {
                            printf("Id - %d, Nome %s\n", listaProfessor[i].matricula,
                                   listaProfessor[i].nome);
                        }

                        int encontrou = 0;

                        do
                        {
                            printf("Qual professor leciona está disciplina? Informe o ID. \n");
                            int matriculaProf;
                            scanf("%d", &matriculaProf);
                            getchar();
                            for (int i = 0; i < qtdProf; i++)
                            {
                                if (listaProfessor[i].matricula == matriculaProf)
                                {
                                    listaDisciplina[qtdDisciplina].matriculaProfessor = listaProfessor[i].matricula;
                                    encontrou = 1;
                                    break;
                                }
                            }
                            if (!encontrou)
                            {
                                printf("Professor não cadastrado\n");
                            }

                        } while (!encontrou);

                        listaDisciplina[qtdDisciplina].codigo = ++incrementadorCodigoDisciplina;
                        qtdDisciplina++;

                        // INCREMENTADOR
                    }
                    else
                    {
                        printf(" Lista de disciplina cheia. ");
                    }
                    break;
                    }
                    case 2: {
                        // listarDisciplina(qtdDisciplina, listaDisciplina);
                       
                    break;
                }

                case 0:
                {
                    outDisciplina = 1;
                    printf("Voltando para o menu principal ...\n");
                    break;
                }

                    default: {
                        printf("Opcao invalida... \n");
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
        case 0: // MODULO SAIR
        { 
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

