#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct TElemento {
        int info;
        struct TElemento *prox;
};

char tela();
struct TElemento *cria_no();
void insere_no (struct TElemento *, int );
void remove_no (struct TElemento *, int);
void listar(struct TElemento *);

void main()
{
    struct TElemento *ptlista;
    char linha[80];
    char opcao;
    int sair = 0, valor;

    ptlista = cria_no();
    ptlista->prox=ptlista;


    do {
           opcao = tela();
           switch (opcao) {
                  case 'i':
                       puts("Qual dado a inserir?");
                       gets(linha);
                       sscanf(linha, "%d", &valor);
                       insere_no(ptlista, valor);
                       break;
                  case 'r':
                       puts("Qual dado a remover?");
				   gets(linha);
                       sscanf(linha, "%d", &valor);
                       remove_no(ptlista, valor);
                       break;
                  case 'l':
                       listar(ptlista);
                       break;
                  case 's':
                       sair = 1;
                       break;
                  default:
					   puts("Opcao invalida.");
					   break;
           }
    } while (!sair);
}


char tela () {

     char opcao, linha[80];

     puts("Qual a sua opcao?");
     puts("[L]istar, [I]nserir, [R]emover, [S]air");
     gets(linha);
     sscanf(linha, "%c", &opcao);
     return tolower(opcao);
}

void listar (struct TElemento *ptlista) {

     int i=0;
     struct TElemento *pont;

     pont = ptlista->prox;
     while (pont != ptlista) {
           printf("Elemento %d = %d\n", i++, pont->info);
           pont = pont->prox;
     }
}


void insere_no (struct TElemento *ptlista, int valor) {

     struct TElemento *pont, *ant, *p;

    ant = ptlista;
    pont = ptlista->prox;
    ptlista->info = valor;

    while (pont->info < valor) {
             ant = pont;
             pont = pont->prox;
    }

    if (pont->info == valor && pont != ptlista)
       puts("Elemento ja existe na tabela.");
    else {
         p = cria_no();
         p->info = valor;
         p->prox = pont;
         ant->prox = p;
     }
}

void remove_no (struct TElemento *ptlista, int valor) {
     struct TElemento *pont, *ant;

    ant = ptlista; pont = ptlista->prox;
    ptlista->info = valor;

    while (pont->info < valor) {
          if (pont->info < valor) {
             ant = pont;
             pont = pont->prox;
          }
    }

    if (pont->info == valor && pont != ptlista) {
       ant->prox = pont->prox;
       free(pont);
    }
    else puts("Elemento nao existe na tabela.");
}

struct TElemento *cria_no() {

       struct TElemento *p;

       if (( p = (struct TElemento *) malloc(sizeof(struct TElemento)) ) == NULL )
       {
            puts("Nao ha espaco.");
            exit(1);
       }
       p->info = -1;
       p->prox = NULL;
       return p;
}
