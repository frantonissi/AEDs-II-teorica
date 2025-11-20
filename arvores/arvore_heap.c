#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7

typedef struct MinHeap {
    int* harr;       // O array que armazena os elementos
    int capacity;    // O tamanho máximo (MAX_SIZE)
    int heap_size;   // O número atual de elementos
} MinHeap;


MinHeap *inicializacao(int capacity){

    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h -> harr = (int*)malloc(sizeof(int));
    h -> capacity = capacity;
    h -> heap_size = 0;
    return h;

}

int parent(int i){

    return (i - 1)/2;

}

int left_Chield(int i){

    return 2 * i + 1;

}

int right_Chield(int i){

    return 2 * i + 2;

}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert_MinHeap(MinHeap *h, int k){

    if (h -> heap_size == h -> capacity){
        printf("\nOverflow: Could not insert Key\n");
        return;
    }
    h -> heap_size++;
    int i = h -> heap_size - 1;
    h -> harr[i] = k;

    while (i != 0 && h -> harr[parent(i)] > h -> harr[i]){
        swap(&h->harr[i], &h->harr[parent(i)]);
        i = parent(i);
    }


}

int extractMin(MinHeap *h) {
    if (h->heap_size <= 0) return -1; // Erro: Heap vazia
    if (h->heap_size == 1) {
        h->heap_size--;
        return h->harr[0];
    }

    // 1. Salva o menor (Raiz)
    int root = h->harr[0];

    // 2. Coloca o último elemento na Raiz
    h->harr[0] = h->harr[h->heap_size - 1];
    h->heap_size--;

    // 3. Heapify Down (Conserta descendo)
    int i = 0;
    while (left_Chield(i) < h->heap_size) {
        
        int menor = left_Chield(i); // Assume que a esquerda é menor

        // Se direita existe E é menor que a esquerda, atualiza
        if (right_Chield(i) < h->heap_size && h->harr[right_Chield(i)] < h->harr[left_Chield(i)]) {
            menor = right_Chield(i);
        }

        // Se o Pai for maior que o Menor Filho, troca
        if (h->harr[i] > h->harr[menor]) {
            swap(&h->harr[i], &h->harr[menor]);
            i = menor; // Continua descendo
        } else {
            break; // Pai achou o lugar certo
        }
    }

    return root;
}

    

int main() {
    printf("--- Teste do Min Heap ---\n");

    // Cria uma heap com capacidade para 11 elementos
    MinHeap* h = inicializacao(11);

    // Inserindo valores fora de ordem
    printf("Inserindo: 3, 2, 15, 5, 4, 45\n");
    insert_MinHeap(h, 3);
    insert_MinHeap(h, 2);
    insert_MinHeap(h, 15);
    insert_MinHeap(h, 5);
    insert_MinHeap(h, 4);
    insert_MinHeap(h, 45);

    printf("\nAgora removendo (ExtractMin)...\n");

    printf("Valores removidos: ");
    // Removemos todos até esvaziar
    while (h->heap_size > 0) {
        printf("%d ", extractMin(h));
    }
    printf("\n");

    // Limpa memória
    free(h->harr);
    free(h);
    
    return 0;
}