# Lanchonete_univale

Aqui está uma descrição para o seu projeto de controle de vendas para GitHub:
Controle de Vendas para Lanchonete

Este é um projeto em C que simula o sistema de controle de vendas de uma lanchonete. O programa permite o cadastro de lanches, exibição do cardápio e registro de vendas, utilizando um arquivo para salvar e ler os dados dos produtos cadastrados. Este sistema simples foi desenvolvido com o objetivo de praticar o uso de manipulação de arquivos, funções e estruturas de controle em C.
Funcionalidades:

    Cadastrar Lanche: Permite adicionar novos lanches ao cardápio com descrição e preço.
    Lançar Venda: Registra a venda de um lanche, calculando o total a ser pago de acordo com a quantidade solicitada.
    Listar Cardápio: Exibe o cardápio com todos os lanches disponíveis, mostrando o preço de cada um.
    Persistência de Dados: Salva o cardápio em um arquivo de texto (Cardapio.txt) e carrega os dados sempre que o programa é iniciado.

Como Executar:

    Compile o programa usando um compilador C, por exemplo, com o GCC:

    bash

gcc -o controle_vendas controle_vendas.c

Execute o programa:

bash

    ./controle_vendas

Estrutura do Projeto:

    controle_vendas.c: Código-fonte principal do projeto.
    Cardapio.txt: Arquivo gerado pelo programa para armazenar os lanches cadastrados.

Observações:

    O cardápio é salvo automaticamente após cada cadastro de lanche.
    O sistema permite até 50 lanches cadastrados.
    Para garantir a usabilidade do programa, é necessário utilizar um terminal que suporte a função system("clear") para limpar a tela.

Tecnologias Utilizadas:

    Linguagem C
    Manipulação de arquivos com funções da biblioteca padrão C (fopen, fclose, fscanf, fprintf).
    Controle de fluxo com if, switch, do-while.
    Funções para modularização do código.

Objetivo do Projeto:

O objetivo deste projeto é praticar o desenvolvimento de sistemas simples em C, focando em manipulação de arquivos e criação de um fluxo básico de um sistema de vendas. Ele serve como uma boa introdução para quem está começando a programar em C e quer entender como construir aplicações que interagem com o usuário e mantêm dados persistentes.
