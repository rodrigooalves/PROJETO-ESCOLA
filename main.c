#include <stdio.h>
#include <string.h>
#define TAM_ALUNO 3
#define TAM_MAX_NOME 99
typedef struct {
    char nome[TAM_MAX_NOME];
    int idade;
    int matricula;
    char sexo;
    int active;
}Aluno;


int main () {
    Aluno listAluno[TAM_ALUNO]; //VETOR ALUNOS
    int option;
    //int listAluno[TAM_ALUNO]; //VETOR ALUNOS
    int out = 0;
    int qtdAluno;

    while(!out) {
        printf("--------> MENU ESCOLA <-------\n");    
        printf("##############################\n");    
        printf(" 1 -> Portal do Aluno. <-\n");    
        printf(" 2 -> Portal do Professor. <- \n");    
        printf(" 3 -> Portal da Disciplina. <-\n");    
        printf(" 0 -> Sair do Programa. <-\n\n"); 
        scanf("%d", &option);

        switch(option) {
            case 1: { //MODULO ALUNO
                int optionAluno; 
                int outAluno = 0;
                printf(" ---> PORTAL ALUNO <---\n");

                while(!outAluno){
                    printf("#########################\n");
                    printf("1 --> Cadastrar aluno. <--\n");
                    printf("2 --> Listar aluno. <--\n");
                    printf("3 --> Atualizar aluno. <--\n");
                    printf("4 --> Excluir aluno. <--\n");
                    printf("0 --> Voltar para o PORTAL. <--\n\n");
                    scanf("%d",&optionAluno);
                    
                    switch(optionAluno){
                        case 1: {
                                // FUNÇÃO DE CADASTRAR
                            break;
                        }
                        case 2: {
                                // FUNÇÃO DE LISTAR
                            break;
                        }
                        case 3: {
                            // ATUALIZAR ALUNO
                            printf("-> Atualizar Aluno: \n");
                            break;
                        }
                        case 4: {
                            // EXCLUIR ALUNO
                            printf("-> Excluir aluno: \n");
                            printf("-->Digite a matricula: \n");
                            int matricula;
                            int found = 0;
                            scanf("%d", &matricula);
                            if( matricula < 0){
                                printf("##Matricula inválida ## \n");
                            } else {
                                for ( int i = 0; i < qtdAluno; i++) {
                                    if(matricula == listAluno[i].matricula) {
                                        listAluno[i].active = -1;
                                        found = 1;
                                        break;
                                    }
                                        if( found == 1){
                                            printf("Matricula excluida com sucesso!");
                                        }
                                }
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
            case 2: { // MODULO PROdFRESSOR
                printf("MODULO PROFESSOR\n");
                break;
            }
            case 3: { // MODULO DISCIPLINA
                printf("MODULO DISCIPLINA\n");
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