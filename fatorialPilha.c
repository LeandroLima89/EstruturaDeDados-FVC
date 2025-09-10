#include<stdio.h>

int fatorial (int n);

void main(){
    int numero;
    printf("Informe um numero inteiro positivo: ");
    scanf("%d", &numero);
    printf("\nO fatorial de %d e %d", numero, fatorial(numero));
}

int fatorial(int n){
    if(n == 0){
        return 1;
    }else{
        int resultado = n * fatorial(n - 1);
        return resultado;
    }
}
