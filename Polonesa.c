#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stNo {
  int info;
  struct stNo *est;
  struct stNo *dir;
} tNo ;

tNo *cria_no(void );
tNo *cria_arvore( int );
void pos_est (tNo *, int  );
void pos_dir (tNo *, int  );
void pre_ordem (tNo *);
void em_ordem (tNo *);
void pos_ordem (tNo *);
void visita (tNo *);

void main() {
  tNo *raiz, *p, *t;
  int letra;

  letra = getchar();
  raiz = cria_arvore(letra);
  if (raiz==NULL) exit(1);
  while (letra != '*') {
    t = raiz;
    p = raiz;
    printf("Li letra %c\n", letra);
    while (letra != p->info && t) {
      p = t;
      if (letra < p->info)
			t = p->est;
      else
			t = p->dir;
    }
    if (letra == p->info)
      printf("A letra %c ja existe na arvore.\n", letra);
    else {
      if (letra < p->info)
			pos_est(p, letra);
      else
			pos_dir(p, letra);
    }
    letra = getchar();
  }
  puts("Acabei de criar a arvore.");
  puts("\nImprimindo em Pre-ordem");
  pre_ordem(raiz);
  puts("\nImprimindo em Ordem");
  em_ordem(raiz);
  puts("\nImprimindo em Pos-ordem");
  pos_ordem(raiz);
}

tNo *cria_no( void ) {
  tNo *p;

  if ((p = (tNo *) malloc(sizeof(tNo))) == NULL)
    return NULL;
  else {
    p->est = NULL; p->dir = NULL;
    return p;
  }
 }


tNo *cria_arvore (int x) {
  tNo *p;

  p = cria_no ();
  if (p) {
    p->info = x;
    return p;
  }
  else {
    puts("Faltou espaco para alocar no.");
    return NULL;;
  }
}

void pos_est(tNo *p, int x) {
  tNo *t;

  if (p->est)
    puts("Operacao de insercao a esquerda ilegal.");
  else {
    t = cria_arvore(x);
    p->est = t;
  }
}


void pos_dir(tNo *p, int x) {
  tNo *t;

  if (p->dir)
    puts("Operacao de insercao a direita ilegal.");
  else {
    t = cria_arvore(x);
    p->dir = t;
  }
}

void pre_ordem (tNo *p) {
 	if (p) {
      visita(p);
      pre_ordem(p->est);
      pre_ordem(p->dir);
   }
}

void em_ordem (tNo *p) {
 	if (p) {
      em_ordem(p->est);
      visita(p);
      em_ordem(p->dir);
   }
}


void pos_ordem (tNo *p) {
 	if (p) {
      pos_ordem(p->est);
	  pos_ordem(p->dir);
      visita(p);
   }
}

void visita (tNo *p) {
 	printf("%c ", p->info);
}
