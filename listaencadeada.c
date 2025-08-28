#include <stdio.h>
#define <stdio.h>
#include <ctype.h>

struct TElemento{
    int info;
    struct TElemento *prox;

};

char tela();
struct TElemento *cria_no();
void insere_no(struct TElemento *, int);
void remove_no(struct TEelemento *, int);
void listar(struct TElemento *);

void main(){

}

char tela(){
    char opcao, linha[80];
    puts("Qual a sua opcao?");
    puts("[L]istar, [I]nserir, [R]emover, [S]air");
    gets(linha);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}
void listar(struct TElemento *ptlista){
    int i = 0;
    struct TElemento *pont;
    pont = ptlista->prox;
    while(pont != ptlista){
        printf("elemento %d = %d\n", i++, pont->info);
        pont = pont->prox;
    }
}
struct TElemento *cria_no(){
    struct TElemento *pont;

    pont = (struct TElemento *) malloc(sizeof(struct TElemento));
    if(pont == NULL){
        puts("Nao existe mais memoria no computador!");
        exit(1);
    }
    pont->info = -1;
    pont->prox = NULL;
    return pont;
};
