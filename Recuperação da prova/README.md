Exercícios de Recuperação

(1) (1 ponto) Apresente o exemplo de um sistema ou aplicação composto de vários processos
concorrentes onde o chaveamento não-preemptivo é necessário ou vantajoso.

(2) (2 pontos) Desenvolva os programas concorrentes a seguir:

(a) Desenvolva um programa que cria 512 processos, cada processo imprime a mensagem “Estou
vivo!\n” e depois dorme por 20 segundos.


(b) Essa questão é similar a questão 7 da prova: escreva um programa em C que crie quatro
processos filhos de um único processo pai. O processo pai primeiro imprime uma mensagem inicial
“Processo PAI iniciado” e depois cria os três processos. Após criar os três processos filhos, o
processo pai espera pela finalização destes processos e então imprime a mensagem “Processo PAI
encerrado”. Cada um dos processos filhos imprime uma mensagem “Processo FILHO N iniciado”,
onde N é o número do processo filho, depois dorme por N*10 segundos e imprime “Processo
FILHO N encerrado”. Porém nessa implementação deve ser usado o seguinte trecho de código,
que se situa antes da rotina main():
```c
int nfilho;
void proc_filho()
{
printf("Processo FILHO %d iniciado\n",nfilho);
printf("Vair dormir por %d segundos\n",nfilho*10);
sleep(nfilho*10);
printf("Processo FILHO %d encerrado\n",nfilho);
}
```
Somente a rotina proc_filho() definida acima deve ser executada no código fonte de cada processo
filho. O valor da variável global nfilho deve ser atribuído de forma apropriada pelo processo PAI,
para garantir que cada processo filho imprima a informação correta sobre seu número do processo
(1, 2, 3 ou 4).
