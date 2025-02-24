#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações da carta
typedef struct {
    char estado[30];
    int codigo;
    char nome[50];
    unsigned long int populacao; // Agora a população é unsigned long int
    float pib;
    float area;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder; // Adicionamos o campo super_poder
} CartaCidade;

// Função para calcular as propriedades derivadas da carta
void calcularPropriedades(CartaCidade *cidade) {
    if (cidade->area > 0) {
        cidade->densidade_populacional = (float)cidade->populacao / cidade->area;
    } else {
        cidade->densidade_populacional = 0;
    }

    if (cidade->populacao > 0) {
        cidade->pib_per_capita = cidade->pib / (float)cidade->populacao;
    } else {
        cidade->pib_per_capita = 0;
    }
}

// Função para calcular o Super Poder da carta
void calcularSuperPoder(CartaCidade *cidade) {
    cidade->super_poder = (float)cidade->populacao + cidade->area + cidade->pib + cidade->pontos_turisticos + cidade->pib_per_capita;
    if (cidade->densidade_populacional > 0) {
        cidade->super_poder += 1.0f / cidade->densidade_populacional;
    }
}

// Função para cadastrar uma nova carta
void cadastrarCarta(CartaCidade *cidade) {
    char buffer[100];

    printf("\nDigite o estado: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(cidade->estado, buffer);

    printf("Digite o codigo da cidade: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%d", &cidade->codigo);

    printf("Digite o nome da cidade: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(cidade->nome, buffer);

    printf("Digite a populacao: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%lu", &cidade->populacao);

    printf("Digite o PIB da cidade: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%f", &cidade->pib);

    printf("Digite a area da cidade: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%f", &cidade->area);

    printf("Digite o numero de pontos turisticos: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%d", &cidade->pontos_turisticos);

    calcularPropriedades(cidade);
    calcularSuperPoder(cidade);
}

// Função para exibir as informações da carta
void exibirCarta(CartaCidade cidade) {
    printf("\n--- Carta da Cidade ---\n");
    printf("Estado: %s\n", cidade.estado);
    printf("Codigo: %d\n", cidade.codigo);
    printf("Nome: %s\n", cidade.nome);
    printf("Populacao: %lu\n", cidade.populacao);
    printf("PIB: %.2f\n", cidade.pib);
    printf("Area: %.2f km²\n", cidade.area);
    printf("Pontos Turisticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidade_populacional);
    printf("PIB per capita: %.2f\n", cidade.pib_per_capita);
    printf("Super Poder: %.2f\n", cidade.super_poder);
}

// Função para comparar duas cartas e exibir os resultados
void compararCartas(CartaCidade carta1, CartaCidade carta2) {
    printf("\nComparacao de Cartas:\n");

    printf("Populacao: ");
    if (carta1.populacao > carta2.populacao) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }

    printf("Area: ");
    if (carta1.area > carta2.area) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }

    printf("PIB: ");
    if (carta1.pib > carta2.pib) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }

    printf("Pontos Turisticos: ");
    if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }

    printf("Densidade Populacional: ");
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }

    printf("PIB per Capita: ");
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }

    printf("Super Poder: ");
    if (carta1.super_poder > carta2.super_poder) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }
}

int main() {
    CartaCidade carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("Cadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    compararCartas(carta1, carta2);

    return 0;
}
