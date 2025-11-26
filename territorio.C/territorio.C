#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    Estrutura Territorio:
    Representa um território com:
    - nome: nome do território
    - cor: cor do exército
    - tropas: quantidade de tropas disponíveis
*/
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

/*
    Função: cadastrarTerritorios
    Objetivo: preencher os dados dos territórios dinamicamente alocados.
    Recebe o ponteiro para o mapa (vetor de Territorio) e a quantidade a cadastrar.
*/
void cadastrarTerritorios(Territorio *mapa, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Cadastro do território %d:", i + 1);

        printf("Digite o nome do território: ");
        scanf("%29s", mapa[i].nome);

        printf("Digite a cor do exército: ");
        scanf("%9s", mapa[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);

        printf("");
    }
}

/*
    Função: exibirTerritorios
    Objetivo: exibir todos os territórios cadastrados com formatação clara.
*/
void exibirTerritorios(Territorio *mapa, int quantidade) {
    printf("=== Territórios Registrados ===");
    for (int i = 0; i < quantidade; i++) {
        printf("Território %d:", i + 1);
        printf("Nome: %s", mapa[i].nome);
        printf("Cor do exército: %s", mapa[i].cor);
        printf("Tropas: %d", mapa[i].tropas);
        printf("-------------------------------");
    }
}

/*
    Função: atacar
    Objetivo: simular uma batalha entre dois territórios usando ponteiros.
    - Cada lado rola um dado (1 a 6)
    - Se o atacante vencer: defensor muda de cor e perde metade das tropas (arredondamento para baixo)
    - Se perder: atacante perde uma tropa
    Todas as alterações são feitas através dos ponteiros recebidos.
*/
void atacar(Territorio *atacante, Territorio *defensor) {
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("%s (%s) atacou %s (%s)!", atacante->nome, atacante->cor, defensor->nome, defensor->cor);
    printf("Dado do atacante: %d", dadoAtacante);
    printf("Dado do defensor: %d", dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Resultado: O atacante venceu!");

        /* transfere a cor e reduz as tropas do defensor */
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = defensor->tropas / 2; // metade das tropas

        printf("%s agora controla o território %s! Tropas restantes no defensor: %d", atacante->cor, defensor->nome, defensor->tropas);
    } else {
        printf("Resultado: O defensor resistiu!");

        if (atacante->tropas > 0) {
            atacante->tropas -= 1; // atacante perde uma tropa
            printf("O atacante perdeu 1 tropa. Tropas restantes do atacante: %d", atacante->tropas);
        }
    }
}

/*
    Função: atribuirMissao
    Objetivo: sorteia uma missão do vetor missoes e copia para destino.
    destino deve ter memória alocada pelo chamador.
*/
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int idx = rand() % totalMissoes;
    strcpy(destino, missoes[idx]);
}

/*
    Função: verificarMissao
    Objetivo: verifica se a missão do jogador foi cumprida.
    Para flexibilizar, recebe também a cor do jogador (corJogador) para saber qual cor verificar.
    Retorna 1 se cumprida, 0 caso contrário.
    Implementamos verificações simples para as missões predefinidas.
*/
int verificarMissao(char* missao, Territorio* mapa, int tamanho, char* corJogador) {
    // Missões implementadas (textos exatos usados abaixo):
    // "Conquistar 3 territórios"
    // "Eliminar todas as tropas da cor vermelha"
    // "Controlar 50% dos territórios"
    // "Ter ao menos 10 tropas no total"
    // "Controlar o território Fortaleza"

    // 1) Conquistar 3 territórios
    if (strstr(missao, "Conquistar 3") != NULL) {
        int cont = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) cont++;
        }
        return (cont >= 3) ? 1 : 0;
    }

    // 2) Eliminar todas as tropas de uma cor específica (ex.: vermelha)
    if (strstr(missao, "Eliminar todas as tropas da cor") != NULL) {
        // extrair a cor alvo a partir da string
        char corAlvo[10];
        // assumimos formato: "Eliminar todas as tropas da cor <nome>"
        const char *ptr = strstr(missao, "cor");
        if (ptr) {
            ptr += 4; // pula "cor "
            strncpy(corAlvo, ptr, 9);
              corAlvo [9]