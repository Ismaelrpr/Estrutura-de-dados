#### Problema 

Implemente a função int ehZigueZague(TNoA *raiz), que recebe um ponteiro para a raiz de uma árvore binária e retorna um inteiro (1 se a árvore é zigue-zague, 0 caso contrário). 

Use o arquivo fornecido nesse exercício, pois ele já contém o tratamento de entrada e saída. 

#### Entrada: 
- uma string que representa a árvore a ser analisada, usando a notação do percurso em profundidade ([ver slide para um exemplo](http://www.ic.uff.br/~vanessa/material/ed/03-ArvoresBinarias.pdf#page=52)). Os valores dos nós devem ser informados separados por um traço, sem espaço em branco entre o valor do nó e o traço. 

A árvore deve ser informada como se fosse uma árvore cheia (por exemplo, para uma árvore de dois níveis deve-se fornecer 3 nós). Caso algum desses nós seja NULL, usar * para representá-lo. 

**Exemplo**: caso queira informar uma árvore que tem raiz 400, a raiz tem dois filhos 300 e 500, o filho 300 tem um filho 150 e um filho NULL, e o filho 500 tem dois filhos 450 e 700, a string que representa essa árvore é 400-300-150-\*-500-450-700. 

#### Saída:
- inteiro (1 se a árvore é zigue-zague, 0 caso contrário)

#### Exemplos:

|Entrada|Saída|
|---|---| 
|100-200-20|0|
|400-\*-\*-\*-500-450-\*|1|
|400-300-150-\*-200-\*-\*-\*-\*-\*-\*-\*-\*-\*-\*|1|

#### Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
- Como o traço é usado para separar os valores, os nós da árvore devem ter valores inteiros não negativos
