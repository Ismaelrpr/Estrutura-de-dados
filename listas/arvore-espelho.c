TNoA *espelha(TNoA *raiz) {
    if (raiz == NULL)
        return NULL;

    /* troca os filhos esquerdo e direito do nó atual */
    TNoA *temp = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = temp;

    /* aplica a mesma troca recursivamente nas subárvores
     * (que já estão nas posições trocadas) */
    espelha(raiz->esq);
    espelha(raiz->dir);

    return raiz;
}