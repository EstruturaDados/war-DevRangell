#include <stdio.h>
#include <string.h>

/*
 * Struct Territorio:
 * Representa um território com nome, cor do exército
 * e quantidade de tropas associadas.
 */
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Vetor que armazena 5 territórios
    Territorio territorios[5];

    printf("=== Sistema de Cadastro de Territórios ===\n\n");

    /*
     * Cadastro dos territórios:
     * Utiliza um laço for para preencher os dados
     * de cada território informado pelo usuário.
     */
    for (int i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);

        printf("Digite o nome do território: ");
        scanf("%29s", territorios[i].nome);

        printf("Digite a cor do exército: ");
        scanf("%9s", territorios[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    /*
     * Exibição dos dados cadastrados:
     * Percorre o vetor e mostra as informações
     * de cada território cadastrado anteriormente.
     */
    printf("=== Territórios Registrados ===\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
        printf("------------------------------\n");
    }

    return 0;
}
