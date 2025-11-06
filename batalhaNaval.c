#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Escrito por Igor Leite da Silva

#define NUM 10               // Costante implementada na matriz 'tabuleiro'
#define COLUNA 3             // Costante implementada na linha da matriz 'cone', 'cruz', 'octaedro'
#define LINHA 5              // Costante implementada na coluna da matriz 'cone', 'cruz', 'octaedro'

int main (){
    int tabuleiro[NUM][NUM];    // Declaração de uma matriz 10x10 tipo 'int'
    char linha[NUM];            // Declaração de um vetor tipo 'char'
    
    int cone[COLUNA][LINHA];    // Matrizes para o desafio nível mestre
    int cruz[COLUNA][LINHA];
    int octaedro[COLUNA][LINHA];

    // Parte de calculos
    // 'for' para guarda os valores de 0 em todos os elementos da tabela
    for (int i=0; i<NUM; i++){
        for (int j=0; j<NUM; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // 'for' para adicionar os valores na matriz posicionando corretamente na tabela
    // 'if' - Ele vai reconhecer se os valores de i e j estão batendo com a posição que eu quero por os meus valores
    for (int i=0; i<NUM; i++){
        for (int j=0; j<NUM; j++){
            // Vertical - Representado por '3'
            if (i == (0) && j == (0)){
                tabuleiro [i][j] = 3;       // Atribuindo valores a matriz
                tabuleiro [i+1][j] = 3;     // Os valores +n, servem para organizar as posições que os valores se encaixaram
                tabuleiro [i+2][j] = 3;
            }
            // Repetição estrutural do 'if' à cima
            // Orizontal - Representado por '3'
            if (i == (1) && j == (1)){
                tabuleiro [i][j] = 3; 
                tabuleiro [i][j+1] = 3;
                tabuleiro [i][j+2] = 3;

            }
            // Diagonal 1 - Representado por '3'
            if (i == (0) && j == (4)){
                tabuleiro [i][j] = 3;
                tabuleiro [i+1][j+1] = 3;
                tabuleiro [i+2][j+2] = 3;

            }
            // Diagonal 2 - Representado por '3'
            if (i == (0) && j == (9)){
                tabuleiro [i][j] = 3;
                tabuleiro [i+1][j-1] = 3;
                tabuleiro [i+2][j-2] = 3;
            }
        }
    }

    // Nível Mestre
    // 'for' de codificação das formas cone, cruz e octaedro
    for (int i=0; i<COLUNA; i++){
        for (int j=0; j<LINHA; j++){
            // Cone - Representado por '4'
            if (j >= 2 - i && j <= 2 + i){  // Ele centraliza a posição e vai gradualmente crescendo ate o fim da matriz
                cone[i][j] = 4;
            } else {
                cone[i][j] = 0;
            }

            //Cruz - Representado por '5'
            if (i == 1 || j == 2){          // Ele ira só salvar apenas quando a coluna for i = 1 e a liinha j = 2
                cruz[i][j] = 5;
            } else {
                cruz[i][j] = 0;
            }

            // Octaedro - Representado por '6'
            if  ((i <= 1 && j >= (2 - i) && j <= (2 + i)) || (i > 1 && j == 2)){  // Ele centraliza, depois almenta a posição
                octaedro[i][j] = 6;                                               // por fim diminue novamente
            } else {                                                              // Solução feita por pesquisas
                octaedro[i][j] = 0;
            }

            // Adição dos valores das formas na matriz principal 'tabuleiro'
            // Os valores +n, servem para organizar as posições que os valores se encaixaram
            tabuleiro [i+4][j] = cone[i][j];
            tabuleiro [i+4][j+5] = cruz[i][j];
            tabuleiro [i+7][j+2] = octaedro[i][j];
        }
    }

    // Parte da impreção
    // 'for' feito apenas para salvar e imprimir o alfabeto do vetor 'linha'
    printf ("   ");
    for (int i=0; i<NUM; i++){
        linha [i] = 'A' +i;     // A string somado com o valor 'i' modifica seu valor para o valor seguinte, no caso 'B' e assim por diante
        printf ("%c ", linha[i]);
    }

    printf ("\n");

    // 'for' de amostragem do código na impreção
    for (int i=0; i<NUM; i++){
        printf (" %d ", i);                     // Imprimir os números da fileira
        for (int j=0; j<NUM; j++){
            printf ("%d ", tabuleiro[i][j]);    // Imprimir os numeros do 'tabuleiro' em linhas
        }
        printf ("\n");
    }

    // Fim
    return 0;
}