#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PILHA 1000

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

void inicializa_pilha(Pilha *p) { p->topo = -1; }

bool pilha_vazia(Pilha *p) { return p->topo == -1; }

void empilha(Pilha *p, TNoA *no) {
    if (p->topo < MAX_PILHA - 1) {
        p->topo++;
        p->itens[p->topo] = no;
    }
}

TNoA* desempilha(Pilha *p) {
    if (!pilha_vazia(p)) {
        return p->itens[p->topo--];
    }
    return NULL;
}

// Retorna o elemento do topo sem remover da pilha
TNoA* espiar_topo(Pilha *p) {
    if (!pilha_vazia(p)) {
        return p->itens[p->topo];
    }
    return NULL;
}


void pos_ordem_iterativa(TNoA *raiz) {
    Pilha p;
    inicializa_pilha(&p);
    
    TNoA *atual = raiz;
    TNoA *ultimo_visitado = NULL;

    while (atual != NULL || !pilha_vazia(&p)) {

        if (atual != NULL) {
            empilha(&p, atual);
            atual = atual->esq;
        } else {
            
            TNoA *no_topo = espiar_topo(&p);
            
            
            if (no_topo->dir != NULL && ultimo_visitado != no_topo->dir) {
                atual = no_topo->dir; // Muda a rota para a direita
            } else {
                
                printf("%d ", no_topo->info);
                ultimo_visitado = desempilha(&p); // Remove efetivamente da pilha
            }
        }
    }
    printf("\n");
}