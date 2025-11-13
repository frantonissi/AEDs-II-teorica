#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7

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

void insert(int a[], int data , int *n){

    if(*n >= MAX_SIZE){

        printf("Heap cheia\n");
        return;

    }
    a[*n] = data;
    *n = *n + 1;

    int i = *n - 1;

    while (i != 0 && a[parent(i)] < a[i]){

        swap(&a[parent(i)], &a[1]){
            i = parent(i);

        }

    }

}

int main(){


    return 0;
}