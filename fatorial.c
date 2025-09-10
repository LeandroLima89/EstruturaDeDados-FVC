#include<stdio.h>

void main(){
    int x, i, fatorial;

    fatorial = 1;

    printf("Digite o numero para fatorar: ");
    scanf("%d", &x);

    for(i = 1; i <= x ; i++){
        fatorial = fatorial * i;
    }
    printf("Fatorial de %d e %d", x, fatorial );
}
