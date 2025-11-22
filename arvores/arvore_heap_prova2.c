#include <stdlib.h>
#include <stdio.h>

typedef struct heap{
    int *item;
    int capacidade;
    int tamanho_heap;
}heap;

heap *novo_Item(int capacidade){
    heap* novo_Item = (heap*)malloc(sizeof(heap));
    novo_Item -> item = (int*)malloc(sizeof(int));
    novo_Item -> capacidade = capacidade;
    novo_Item -> tamanho_heap = 0;
}

int pai(int i){
    return (i - 1)/2;
}

int filho_esquerda(int i){
    return (2 * i) + 1;
}

int filho_direita (int i){
    return (2 * i) + 2;
}

void troca(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insercao_Max(heap *raiz, int valor){

    if (raiz -> tamanho_heap == raiz -> capacidade){
        printf("nao pode inserir nada kkkkkk");
    }

    raiz -> tamanho_heap++;
    int i = raiz -> tamanho_heap - 1;
    raiz -> item[i] = valor;

    while ((i != 0) && (raiz -> item[pai(i)] < raiz -> item[i]))
    {
        troca(&raiz -> item[i], raiz -> item[pai(i)]); //primeiro o filho, depois o pai
        i = pai(i);
    }
    

}

void insercao_Min(heap *raiz, int valor){
    if ( raiz -> tamanho_heap == raiz -> capacidade){
        printf ("Nao vai inserir");
    }

    raiz -> tamanho_heap++;
    int i = raiz -> tamanho_heap - 1;
    raiz -> item[i] = valor;

    while ((i != 0) && (raiz -> item[pai(i)] > raiz -> item[i]))
    {
        troca(&raiz -> item[i], raiz -> item[pai(i)]); //primeiro o filho, depois o pai
        i = pai(i);
    }
    
}

int extracao_Max(heap *raiz){

    if (raiz == NULL){
        return -1;
    }

    

}