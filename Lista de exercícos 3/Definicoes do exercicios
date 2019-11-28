Lista de Exercícios 3 – Exercícios sobre Threads
(1) Desenvolva um programa que cria n threads, onde n é um número informado pelo usuário.
Após obter o valor n do usuário o programa principal imprime uma mensagem que irá criar n
threads e então cria as threads. Cada uma das threads criadas seleciona uma quantidade aleatória t
de segundos, t entre 5 e 20 segundos, imprime uma mensagem que irá dormir por t segundos, dorme
(sleep()) por esse tempo, depois imprime uma mensagem que já acordou e encerra a thread. O
programa principal (que agora é a thread principal) espera por todas as threads criadas se
encerrarem usando a função join(). Depois ele imprime uma mensagem que isso ocorreu e encerra
sua execução.

(2) Implemente o programa (3) da lista de exercícios 2 usando threads. Note que para controle de
acesso da memória compartilhada entre as threads, que agora simplesmente é a memória do
processo que iniciou as threads, pode-se utilizar os mutexes.


(3) Faça um sistema de atendimento de solicitações de criação de threads pelo usuário composto de
dois programas distintos: um programa de interface de usuário e um programa servidor que executa
as solicitações. O programa de interface de usuário oferece opções de entrada onde o usuário
fornece as seguintes informações: o nome da nova thread, quanto tempo essa thread vai rodar
(quantos segundos) e que mensagens devem ser impressas no início e no fim da execução da thread.
Quando o usuário finaliza a entrada dessas informações elas são repassadas ao programa executor
por meio de pipes ou de filas de mensagens (escolha uma das duas opções).
O programa executor recebe essas informações e cria uma nova thread passando no argumento de
entrada da thread um apontador para uma struct que contém as informações de como a thread
deverá proceder. Logo após criar a thread o programa executor envia uma resposta ao programa de
interface de usuário (também por pipe ou fila de mensagens) avisando que a thread foi criada (ou
informando que houve algum problema, se isso ocorrer). Depois disso o programa executor volta a
esperar novas solicitações do programa de interface de usuário. O programa de interface de usuário
espera pela resposta do programa executor, escreve essa mensagem na tela e depois volta a esperar
novas solicitações do usuário.
Cada nova thread criada pelo programa executor deve primeiro imprimir: seu nome, a mensagem
inicial definida pelo usuário e o número de segundos que irá dormir no terminal onde o executor
está rodando. Depois essa thread dorme pelo número de segundo definido pelo usuário. Ao final
desse tempo essa thread imprime a mensagem final definida pelo usuário e encerra sua execução.
