#include <stdio.h>

int main()
{
    int ano = 2025;
    int nascimento, i, soma = 0;
    float media;
    int notas[5];
    
    notas[0] = 78;
    notas[1] = 50;
    notas[2] = 12;
    notas[3] = 40;
    notas[4] = 11;
    
    
    printf("Informe o seu ano de nascimento");
    
    scanf("%d", &nascimento);
    
    printf("o ano atual eh %d, olha isso %d\n", ano, ano - 15);
    printf("Sua idade eh aproximadamente %d\n", ano - nascimento);
    printf("Nota numero 2 = %d\n", notas[1]);
    printf("Aqui estao todas as notas\n");
    
    for(i=0; i<5; i++){
        printf("Nota(%d) = %d\n", i+1, notas[i]);
        soma = soma + notas[i];
    }
    printf("O total das notas eh = %d\n", soma);
    
    media = (float)soma / 5;
    printf("A media das notas eh = %lf", media);

    return 0;
}
