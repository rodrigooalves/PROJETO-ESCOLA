#include <stdio.h>
#define TAM_ALUNO 3

int main () {
    int option;
    //int listAluno[TAM_ALUNO]; //VETOR ALUNOS
    int out = 0;

    
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
                            // LISTAR ATUALIZAR
                            break;
                        }
                        case 4: {
                            // EXCLUIR ALUNO
                            break;
                        }
                        case 0: {
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
            case 2: { // MODULO PROFRESSOR

                break;
            }
            case 3: { // MODULO DISCIPLINA

                break;
            }
            case 0: { // MODULO SAIR
                printf("Voltando ao menu principal ... \n");
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