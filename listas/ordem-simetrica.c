#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PILHA 1000 // Tamanho máximo arbitrário para a pilha

// Estrutura do nó da árvore
typedef struct sNoA {
    int info;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

// Estrutura da Pilha
typedef struct {
    TNoA* itens[MAX_PILHA];
    int topo;
} Pilha;

void inicializa_pilha(Pilha *p) {
    p->topo = -1;
}

bool pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

void empilha(Pilha *p, TNoA *no) {
    if (p->topo < MAX_PILHA - 1) {
        p->topo++;
        p->itens[p->topo] = no;
    }
}

TNoA* desempilha(Pilha *p) {
    if (!pilha_vazia(p)) {
        TNoA *no = p->itens[p->topo];
        p->topo--;
        return no;
    }
    return NULL;
}


void ordem_simetrica_iterativa(TNoA *raiz) {
    Pilha p;
    inicializa_pilha(&p);
    
    TNoA *atual = raiz;

    while (atual != NULL || !pilha_vazia(&p)) {
        
        while (atual != NULL) {
            empilha(&p, atual);
            atual = atual->esq;
        }

        atual = desempilha(&p);
        
        printf("%d ", atual->info);

        atual = atual->dir;
    }
    printf("\n");
}