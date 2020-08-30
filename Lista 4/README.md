(1) Em relação aos algoritmos de alocação de memória:
a) Explique o funcionamento dos seguintes algoritmos de alocação de memória: First-Fit,
Best-Fit e Worst-Fit

b) Em um determinado instante de tempo a memória de uma máquina apresenta as seguintes
partições livres : 100K, 500K, 200K, 300K e 600K (nesta ordem). Quais partições ocuparão
processos de 212K, 417K, 112K e 426k (considerando que são submetidos a execução nesta
ordem) para cada um dos três algoritmos de alocação de memória?

c) De acordo com a análise deste caso específico qual é o melhor algoritmo?

(2) Uma memória virtual tem tamanho de página de 4096 bytes, 8 páginas virtuais e 4 páginas
físicas na memória principal. A Tabela de Páginas está configurada como segue:
Página Virtual Página Física

0 1
1 3
2 NP
3 NP
4 2
5 NP
6 0
7 NP
com NP = Não Presente na memória principal.

Faça uma lista dos intervalos de endereço virtual que causarão falta de página. Considere
endereçamento a byte.

(3) Com base na descrição da memória virtual e da tabela de páginas apresentada na questão 2,
responda quais são os endereços físicos de memória principal correspondentes aos seguintes
endereços virtuais:
0, 8191, 20050, 17100 e 16384.

(4) Um sistema que emprega memória virtual utilizando paginação está executando um programa
de tamanho de 8 Kbytes. A máquina possui uma memória física de 3 Kbytes e trabalha com páginas
e quadros (frames) de 1 Kbyte. Na execução deste programa foi gerada a seguinte sequência de
referências de páginas:

5 1 3 5 2 5 1 5 4 3 2 2 1 3 2 1

Supondo que a memória principal esteja inicialmente vazia indique quais páginas estarão residentes
na memória principal após cada referência de página se a política de substituição for: (a) LRU e (b)
FIFO. Qual a melhor política entre FIFO e LRU para estas referências ? Justifique sua resposta.
Observação: indique com um * a página a ser substituída na próxima requisição em caso de ocorrer
uma falta de página (page fault).

(5) Em relação à memória virtual por paginação, responda:
a) O que é falta de página e quando ela ocorre?

b) Quais os usos que o Sistema Operacional poderia das a um bit de proteção contra escrita
que pudesse ser associado às páginas da Tabela de Páginas? Discuta.