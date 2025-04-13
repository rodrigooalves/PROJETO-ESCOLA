#include <stdio.h>
#include <string.h>
#define TAM_ALUNO 4
#define TAM_MAX_NOME 99
#define TAM_CPF 11

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

//STRUCT ALUNO
typedef struct {
	int matricula;
	char nome[TAM_MAX_NOME];
	char sexo;
	char cpf[TAM_CPF];
	Data data_aluno;

} Aluno;

int main () {
	Aluno listaAluno[TAM_ALUNO]; //VETOR ALUNOS
	int option;
	int out = 0;
	int qtdAluno = 0;
	int incrementadorMatricula = 0;

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

			while(!outAluno) {
				printf("#########################\n\n");
				printf("1 --> Cadastrar aluno. <--\n");
				printf("2 --> Listar aluno. <--\n");
				printf("3 --> Atualizar aluno. <--\n");
				printf("4 --> Excluir aluno. <--\n");
				printf("0 --> Voltar para o PORTAL. <--\n\n");
				scanf("%d",&optionAluno);
				getchar();

				switch(optionAluno) {
				case 1: {

					// nome OK, matricula(id), sexo OK, data de nascimento OK.
					//CADASTRO DO NOME
					if(qtdAluno < TAM_ALUNO ) {
						printf("Digite o nome do aluno: \n");
						fgets(listaAluno[qtdAluno].nome, TAM_MAX_NOME, stdin);
						listaAluno[qtdAluno].nome[strcspn(listaAluno[qtdAluno].nome, "\n")] = '\0';

						// CADASTRO CPF
						printf("Digite o CPF: (APENAS NUMEROS)\n");
						fgets(listaAluno[qtdAluno].cpf, TAM_CPF, stdin);
						listaAluno[qtdAluno].cpf[strcspn(listaAluno[qtdAluno].cpf, "\n")] = '\0';
						getchar();


						// CADASTRO SEXO
						printf("Digite o sexo (M/F): \n");
						scanf(" %c", &listaAluno[qtdAluno].sexo);
						getchar();


						// CADASTRO DATA DE NASCIMENTO


						do {
							printf("Digite a data de nascimento: (dd mm aaaa) \n");
							scanf("%d %d %d", &listaAluno[qtdAluno].data_aluno.dia, &listaAluno[qtdAluno].data_aluno.mes, &listaAluno[qtdAluno].data_aluno.ano);

							if(listaAluno[qtdAluno].data_aluno.dia < 1 || listaAluno[qtdAluno].data_aluno.dia > 31
							        || listaAluno[qtdAluno].data_aluno.mes < 1 || listaAluno[qtdAluno].data_aluno.mes > 12
							        && listaAluno[qtdAluno].data_aluno.ano < 1900 || listaAluno[qtdAluno].data_aluno.ano > 2025) {
								printf("Data invalida!, digite novamente. \n");
							}
						} while (listaAluno[qtdAluno].data_aluno.dia < 1 || listaAluno[qtdAluno].data_aluno.dia > 31 ||
						         listaAluno[qtdAluno].data_aluno.mes < 1 || listaAluno[qtdAluno].data_aluno.mes > 12 ||
						         listaAluno[qtdAluno].data_aluno.ano < 1900 || listaAluno[qtdAluno].data_aluno.ano > 2025);
						listaAluno[qtdAluno].matricula = ++incrementadorMatricula; // incrementador + 1 C) a mesma coisa
						qtdAluno ++;
						printf("Cadastro concluido!\n");

					} else {
						printf("Lista de aluno cheia. \n\n");
					}

					break;
				}
				case 2: {
					for (int i = 0; i < qtdAluno; i++) {
						printf("Matricula: %d - Nome: %s, CPF: %s, Sexo: %c , Data de nascimento: %d/%d/%d. \n", listaAluno[i].matricula, listaAluno[i].nome,
						       listaAluno[i].cpf, listaAluno[i].sexo,
						       listaAluno[i].data_aluno.dia, listaAluno[i].data_aluno.mes, listaAluno[i].data_aluno.ano);
					}
					break;
				}
				case 3: {
					// ATUALIZAR ALUNO
					printf("-> Atualizar Aluno: \n");
					break;
				}
				case 4: {
					// EXCLUIR ALUNO
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