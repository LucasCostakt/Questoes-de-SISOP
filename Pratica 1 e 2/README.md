Atividades Práticas 01
1) Crie uma máquina virtual do VirtualBox que será usada como máquina convidada (guest) onde o
Sistema Operacional (SO) Linux será posteriormente instalado. Configurações básicas da máquina
convidada no VirtualBox para as máquinas do laboratório: selecionar SO Ubuntu 64 bits; Memória
RAM 2 (ou 4) GB; Disco HD: 12 (ou 16) GB; Memória de vídeo 32Mb.


2) Baixar a distribuição Ubuntu 18.04 do SO Linux e instalar esse sistema na máquina convidada
previamente criada no VirtualBox.


3) A instalação do Linux pode ser feita sem acesso da máquina convidada à rede de computador
conectada a máquina hospedeira (host) que é a máquina física existente no laboratório.


4) Instale o SO Linux com usuário: aluno e senha: aluno.


5) Após a instalação execute o Ubuntu e:


5.1) Habilite a conexão de rede (selecione o ícone de rede no cando direito inferior da janela
do VirtualBox e habilite a ligação da rede da máquina convidada à máquina hospedeira)


5.2) Selecione a aplicação de “Software Update” do Ubuntu e selecione como repositório
dos softwares do Ubunto o servidor dos EUA.


5.3) Após a atualização das listas de software do Ubuntu, instale as ferramentas básicas de
compilação de programas C usando o comando:
sudo apt-get install build-essential


6) Para testar a instalação dessas ferramentas abra um terminal de linha de comandos, compile e
execute o programa mundo-cruel.c disponível na página do Moodle. A compilação deste programa
pode ser feita pelo comando:
gcc mundo-cruel.c -o mundo-cruel
executado no diretório do usuário. Se não ocorrer nenhum erro o arquivo executável resultante da
compilação pode ser carregado e executado pelo Linux usando o comando:
./mundo-cruel


Atividades Práticas 02
1) Abra um terminal de comandos compile o arquivo fonte C registro-universal.c, disponível no
Moodle.

2) No mesmo terminal da compilação execute o programa resultante. Também abra um novo
terminal de comandos e execute o este mesmo executável.

3) Abra um terceiro terminal de comandos. Execute o comando de visualização de processos do
Linux:
ps aux
Este programa irá mostrar os dois processos executando o programa registro-universal. Analise as
informações geradas pelo programa ps, depois feche os dois terminais extras e deixe apenas uma
janela de terminal de comandos.


4) Na janela de terminal compile o programa gerador-naturais.c.


5) A opção de linha de comando & permite carregar um programa para ser executado e que retorna
ao controle do terminal de comandos, deixando o programa que foi carregado em execução
simultânea com o terminal de comandos. Use a opção & digitada ao fim da linha de comando, como
no exemplo abaixo:
./gerador-naturais &
para criar vários processos distintos, cada um com uma instância do programa gerador-naturais em
execução concorrente (simultânea) com as demais instâncias.


6) Abra um novo terminal de comandos e usando o comando ps analise as informações sobre os
processos gerados no passo anterior.