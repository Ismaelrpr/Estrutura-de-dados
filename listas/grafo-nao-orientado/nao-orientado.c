#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct vizinho {
    int id_vizinho;
    int peso;
    struct vizinho *prox;
}TVizinho;

typedef struct grafo{
    int id_vertice;
    int cor;
    TVizinho *prim_vizinho;
    struct grafo *prox;
}TGrafo;

TGrafo *insere_vertice(TGrafo *g, int id) {
    TGrafo *vertice = (TGrafo *) malloc(sizeof(TGrafo));
    vertice->id_vertice = id;
    vertice->cor = -1;
    vertice->prox = g;
    vertice->prim_vizinho = NULL;
    return vertice;
}

void libera_vizinho(TVizinho *vizinho) {
    if (vizinho != NULL) {
        libera_vizinho(vizinho->prox);
        free(vizinho);
    }
}

void libera_vertice(TGrafo *vertice) {
    if (vertice != NULL) {
        libera_vizinho(vertice->prim_vizinho);
        libera_vertice(vertice->prox);
        free(vertice);
    }
}

TGrafo *busca_vertice(TGrafo *vertice, int id) {
    while ((vertice != NULL) && (vertice->id_vertice != id)) {
        vertice = vertice->prox;
    }
    return vertice;
}

TVizinho *busca_vizinho(TVizinho *vizinho, int id) {
    while ((vizinho != NULL) && (vizinho->id_vizinho != id)) {
        vizinho = vizinho->prox;
    }
    return vizinho;
}

void insere_aresta(TGrafo *g, int origem, int destino, int peso) {
    TGrafo *pv1 = busca_vertice(g, origem);
    TGrafo *pv2 = busca_vertice(g, destino);
    if (pv1 != NULL && pv2 != NULL) {
        TVizinho *vizinho = (TVizinho *) malloc(sizeof(TVizinho));
        vizinho->id_vizinho = destino;
        vizinho->peso = peso;
        vizinho->prox = pv1->prim_vizinho;
        pv1->prim_vizinho = vizinho;
    }
}

void imprime(TGrafo *vertice) {
    while (vertice != NULL) {
        printf("Vertice: %d\n", vertice->id_vertice);
        printf("Vizinhos: ");
        TVizinho *vizinho = vertice->prim_vizinho;
        while (vizinho != NULL) {
            printf("%d ", vizinho->id_vizinho);
            vizinho = vizinho->prox;
        }
        printf("\n\n");
        vertice = vertice->prox;
    }
}

int ehNaoOrientado(TGrafo *g) {
    TGrafo *v_atual = g;
    
    // Percorre todos os vértices do grafo
    while (v_atual != NULL) {
        TVizinho *viz = v_atual->prim_vizinho;
        
        // Percorre todos os vizinhos (arestas que saem) do vértice atual
        while (viz != NULL) {
            // Busca o vértice de destino na lista do grafo
            TGrafo *v_destino = busca_vertice(g, viz->id_vizinho);
            
            if (v_destino != NULL) {
                // Procura a aresta de volta: saindo do destino e apontando para o atual
                TVizinho *viz_volta = busca_vizinho(v_destino->prim_vizinho, v_atual->id_vertice);
                
                // Falha se a aresta oposta não existir ou tiver um peso diferente
                if (viz_volta == NULL || viz_volta->peso != viz->peso) {
                    return 0; // Grafo não é não orientado
                }
            }
            
            viz = viz->prox;
        }
        v_atual = v_atual->prox;
    }
    
    return 1; // Todas as arestas passaram pelo teste
}

int main() {
    /* A função main lê os dados de entrada, cria o grafo e chama a função solicitada no problema
    * depois imprime o resultado
    * ELA NÃO DEVE SER MODIFICADA
    * */
    int num_vertices, num_arestas;
    int id;
    int origem, destino, peso;
    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int i;
    TGrafo *g = NULL;

    //le numero de vertices
    scanf("%d", &num_vertices);
    //le e cria os vertices
    for (i = 0; i < num_vertices; i++) {
        scanf("%s", l);
        id = atoi(l);
        g = insere_vertice(g, id);
    }

    //Le numero de arestas e depois le os dados de cada aresta
    //Cria as arestas no grafo
    scanf("%d", &num_arestas);
    for (i = 0; i < num_arestas; i++) {
        scanf("%s", l);
        //quebra a string de entrada
        ptr = strtok(l, delimitador);
        origem = atoi(ptr);
        ptr = strtok(NULL, delimitador);
        destino = atoi(ptr);
        ptr = strtok(NULL, delimitador);
        peso = atoi(ptr);
        insere_aresta(g, origem, destino, peso);
    }

    //imprime(g);

    printf("%d", ehNaoOrientado(g));
    libera_vertice(g);
}
