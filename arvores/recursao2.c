#include <stdio.h>
#include <stdlib.h>

//Soma de numeros

int somatoria(int n){

    if (n < 10){
        return n;
    }else{
        int ultimo = n%10;
        int resto = n/10;
        n = resto;

       return ultimo + somatoria(n);


    }



}

int main(){

    int n;

    printf("Digite os numeros que voce quer somar: ");
    scanf ("%d", &n);

    int somaFinal = somatoria(n);
    printf ("%d", somaFinal);
    return 0;
}