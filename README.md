# 42-Labs:
## Sobre
O desafio consiste em criar dois programas que irão comprimir e descomprimir um texto via memória compartilhada. O primeiro, denominado encoder, irá usar o algoritmo de huffman para comprimir o texto e compartilhar os dados no bloco de memória compartilhada. O segundo denominado decoder, fará a leitura da memória para o descomprimir.

## Codificação Huffman

Os algoritmos de codificação Huffman são extensivamente utilizados em comunicações digitais para a compressão de dados. Por meio dessa compressão é possível reduzir significativamente o tamanho dos arquivos, possibilitando a redução de gastos com armazenamento de dados e tornando os sistemas mais rápidos e eficientes.

# Shared Memory:

A memória compartilhada fornece o mais rápido método de comunicação entre processos, porque processa leitura e escrita mensagens na velocidade das transferências de memória.

Como o kernel não sincroniza os acessos à memória compartilhada, você deve fornecer 
sua própria sincronização.  Por exemplo, um processo não deve ler da memória até que os dados sejam gravados lá, e dois processos não devem gravar no mesmo local de memória ao mesmo tempo.  Uma estratégia comum para evitar essas condições de corrida é usar semáforos.

## Como usar
1- clonar o projeto computador
`````````````````````````
git clone https://github.com/42sp/42labs-selection-process-v4-shelsonx.git
`````````````````````````
## 2 - Entrar no diretório dos programas

o ideal seria abrir dois terminais para que cada programa fosse executado em seu próprio terminal.
O primeiro compila e executa o decoder, que vai ficar esperando uma entrada. 
O segundo compila e executa o encoder que vai comprimir e compartilhar os dados.

    2.1 entrar no diretório decoder e compilar 
        2.1.1 
            $ cd decoder
        2.1.2 
            $ make
        2.1.3
            $ ./decoder
        
    2.2 entrar no diretório encoder e compilar
        2.2.1
            $ cd encoder
        2.2.2
            $ ./encoder ../files/file

## Considerações finais
O desafio foi bastante intenso, com muitos conceitos novos para serem aprendidos e aplicados em tão pouco tempo. Foi necessária muita dedicação e colaboração, para conseguir chegar ao final do desafio. Fico realmente impressionado e feliz com o quanto que conseguimos aprender em tão pouco tempo, com este desafio e a ajuda da comunidade.
