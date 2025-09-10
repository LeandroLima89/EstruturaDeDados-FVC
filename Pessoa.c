#include <stdio.h>

struct TPessoa{
    char nome [50];
    unsigned int cod;
};

void main(){
    struct TPessoa aluno[5];
    int i;

    printf("Informe os nomes dos alunos:\n");

    for (i=0; i<5; i++){
        gets(aluno[i].nome);
    }
    printf("\n");
    for (i=0; i<5; i++){
        printf("%s\n", aluno[i].nome);
    }

}
