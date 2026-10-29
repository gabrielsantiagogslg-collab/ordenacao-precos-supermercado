#include <stdio.h>

// Estrutura que guarda o nome e o preço de cada produto
typedef struct {
    char nome[30];
    float preco;
} Produto;

 // Organiza os produtos do menor para o maior preço
void bubbleSort(Produto produtos[], int tamanho) {

    // Controla as passagens pela lista
    for (int i = 0; i < tamanho - 1; i++) {

        // Compara os preços dos produtos vizinhos
        for (int j = 0; j < tamanho - 1 - i; j++) {

            // Se o preço atual for maior, troca os produtos
            if (produtos[j].preco > produtos[j + 1].preco) {

                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}


 // Organiza os produtos usando o algoritmo Quick Sort
void quickSort(Produto produtos[], int inicio, int fim) {

    // Define os limites da parte da lista que será ordenada
    int i = inicio;
    int j = fim;

    // Escolhe o preço do produto central como pivô
    float pivo = produtos[(inicio + fim) / 2].preco;

    // Percorre a lista procurando produtos fora de posição
    while (i <= j) {

        // Avança enquanto encontrar preços menores que o pivô
        while (produtos[i].preco < pivo) {
            i++;
        }

        // Volta enquanto encontrar preços maiores que o pivô
        while (produtos[j].preco > pivo) {
            j--;
        }

        // Troca os produtos que estão do lado errado do pivô
        if (i <= j) {
            Produto temp = produtos[i];
            produtos[i] = produtos[j];
            produtos[j] = temp;

            i++;
            j--;
        }
    }

    // Ordena recursivamente a parte esquerda da lista
    if (inicio < j) {
        quickSort(produtos, inicio, j);
    }

    // Ordena recursivamente a parte direita da lista
    if (i < fim) {
        quickSort(produtos, i, fim);
    }
}

int main() {

    // Cadastro dos 10 produtos do supermercado
    Produto produtos[] = {
        {"Arroz", 25.90},
        {"Feijao", 8.50},
        {"Leite", 5.49},
        {"Cafe", 18.90},
        {"Acucar", 4.99},
        {"Oleo", 7.29},
        {"Macarrao", 6.50},
        {"Farinha", 5.99},
        {"Biscoito", 3.99},
        {"Sal", 2.50}
    };

    int tamanho = sizeof(produtos) / sizeof(produtos[0]);

    Produto produtosQuick[10];

    for (int i = 0; i < tamanho; i++) {
        produtosQuick[i] = produtos[i];
    }

    printf("=== PRECOS DOS PRODUTOS ===\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%-15s R$ %.2f\n",
               produtos[i].nome,
               produtos[i].preco);
    }

    printf("\n=== PRECOS ORDENADOS COM BUBBLE SORT ===\n");

    bubbleSort(produtos, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%-15s R$ %.2f\n",
               produtos[i].nome,
               produtos[i].preco);
    }

    printf("\n=== PRECOS ORDENADOS COM QUICK SORT ===\n");

    quickSort(produtosQuick, 0, tamanho - 1);

    for (int i = 0; i < tamanho; i++) {
        printf("%-15s R$ %.2f\n",
               produtosQuick[i].nome,
               produtosQuick[i].preco);
    }

    return 0;
}
