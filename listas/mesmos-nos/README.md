#### Problema 

Implemente a função int mesmos_nos(TNoA *a1, TNoA *a2)  que recebe ponteiros para as raízes de duas árvores binárias, e testa se as árvores possuem os mesmos nós (mesmo que em posições diferentes nas árvores). 

Use o arquivo fornecido neste exercício, pois ele já contém o tratamento de entrada e de saída. 

#### Entrada: 
- duas strings que representam as árvores a serem testadas, usando a notação do percurso em profundidade ([ver slide para um exemplo](http://www.ic.uff.br/~vanessa/material/ed/03-ArvoresBinarias.pdf#page=52)). Cada árvore deve ser informada em uma linha. 

A árvore deve ser informada como se fosse uma árvore cheia (por exemplo, para uma árvore de dois níveis deve-se fornecer 3 nós). Caso algum desses nós seja NULL, usar * para representá-lo. 

**Exemplo**: caso queira informar uma árvore que tem raiz A, a raiz tem dois filhos B e C, o filho B tem um filho D e um filho NULL, e o filho C tem dois filhos E e F, a string que representa essa árvore é ABD*CEF. 

#### Saída:
- 1, caso as árvores possuam os mesmos nós
- 0, caso contrário

#### Exemplos:

|Entrada|Saída|
|---|---|
|ABC<BR/>ACB|1|
|A\*C<BR/>AC\*|1|
|EBDA\*\*\*<BR/>A\*\*\*BED|1|
|EBDA\*\*\*<BR/>A\*\*\*BEE|0|

#### Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
