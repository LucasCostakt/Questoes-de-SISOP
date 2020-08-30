(1) O programa consiste em criar uma área de memória compartilhada que será utilizada por dois
processos. Um dos processos lê do teclado um texto (string) e a opção de conversão maiúscula
(uppercase) ou minúscula (lowercase), e envia ao outro processo através da memória compartilhada
essas duas informações. A memória compartilhada armazena o texto a ser convertido e a opção de
conversão e a indicação de que há um novo texto a ser convertido. O outro processo, uma vez que
detecte que há um novo texto a ser convertido na memória compartilhada, faz conversão desejada
diretamente na mesma área de memória compartilhada. Quando este processo termina a conversão
ele indica, também por uma variável na área de memória compartilhada, que o processo de
conversão terminou. O primeiro processo ao detectar que isso ocorreu, imprime o texto convertido
na tela. O programa somente faz uma leitura e conversão de texto, ou seja, após cada processo
encerrar suas tarefas ele encerra a execução.

(2) Faça dois programas distintos para testar a comunicação por fila (queues): um programa cliente
e um programa servidor. A comunicação entre os programas é feita por duas filas distintas, uma para
envio de requisições (chave de identificação REQ_QUEUE) e a outra para respostas (chave de
identificação RESP_QUEUE). O programa servidor é iniciado primeiro e espera pelas requisições
enviadas em REQ_QUEUE.

(3) O programa da questão (1) faz a comunicação entre os dois processos apenas uma vez por meio
da memória compartilhada. Para que as operações de leitura e conversão de texto executadas pelos
dois processos deste programa possam ser repetidas é necessário que o acesso à memória
compartilhada seja mutuamente exclusivo, ou seja, quando um processo está gravando informações
na memória compartilhada o outro processo não pode alterar ou até ler a memória compartilhada
para que não ocorram inconsistências. Assim, para permitir a repetição das operações de leitura e
conversão de texto implemente um mecanismo baseado em semáforos que garanta o acesso
mutuamente exclusivo da memória compartilhada. O programa segue em execução até o usuário
digitar uma linha vazia que não tem nenhum texto.