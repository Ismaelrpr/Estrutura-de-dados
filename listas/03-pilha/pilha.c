#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* push(TLista* topo, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = valor;
    novo->prox = topo;   /* o novo nó aponta para o antigo topo */
    topo = novo;          /* o novo nó passa a ser o topo */
    return topo;
}


TLista* pull(TLista* topo, int* valor) {
    if (topo == NULL) {
        printf("Erro: pilha vazia\n");
        *valor = -1;
        return NULL;
    }
    TLista* removido = topo;
    *valor = removido->info;
    topo = removido->prox;   /* o segundo elemento passa a ser o topo */
    free(removido);
    return topo;
}

void imprime_lista(TLista *li) {
    TLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("%d ", p->info);
}

int main (void) {
    TLista* pilha = NULL;
    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;
    int qtd_pull;

    scanf("%s", l);
    ptr = strtok(l, delimitador);
    while (ptr != NULL) {
        valor = atoi(ptr);
        pilha = push(pilha, valor);
        ptr = strtok(NULL, delimitador);
    }

    /* lê quantos elementos devem ser desempilhados */
    scanf("%d", &qtd_pull);
    for (int i = 0; i < qtd_pull && pilha != NULL; i++)
        pilha = pull(pilha, &valor);

    imprime_lista(pilha);

    return 0;
}
