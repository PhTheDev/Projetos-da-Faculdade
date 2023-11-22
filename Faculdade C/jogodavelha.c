#include <stdio.h>
#include <stdlib.h>

int main(){

    int l,c,linha,coluna,jogador,ganhou,jogadas,opcao;
    char jogo[3][3];

    do{
        jogador = 1;
        ganhou = 0;
        jogadas = 0;
        //inicia o tabuleiro do jogo
        for(l=0;l<3;l++){
            for(c=0;c<3;c++){
                jogo[l][c]= ' ';
            }
        }
        do{
            //imprimi o tabuleiro na tela
            printf("\n\n\t 0   1   2 \n\n");
            for(l=0;l<3;l++){
                for(c=0;c<3;c++){
                    if(c==0){
                        printf("\t");
                    }
                    printf(" %c ",jogo[l][c]);
                    if(c<2){
                        printf("|");
                    }
                    if(c==2){
                        printf("  %d",l);
                    }
                }
                if(l < 2){
                    printf("\n\t-----------");
                }
                printf("\n");
            }

            //le as coordenadas que o jogador digitar
            do{
            printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar: ", jogador);
            scanf("%d%d", &linha, &coluna);
            }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

            //salva as coordenadas salva qual foi o jogador
            if(jogador == 1){
                jogo[linha][coluna] = 'O';
                jogador++;
            }else {
                jogo[linha][coluna] = 'X';
                jogador = 1;
            }
            jogadas++;

            //verifica se alguem ganhou por linha
            if(jogo[0][0] =='O' && jogo[0][1] =='O' && jogo[0][2] =='O' ||
            jogo[1][0] =='O' && jogo[1][1] =='O' && jogo[1][2] =='O' ||
            jogo[2][0] =='O' && jogo[2][1] =='O' && jogo[2][2] =='O'){
                printf("\nParabens! O Jogador 1 venceu por linha!\n");
                ganhou = 1;
            }

            if(jogo[0][0] =='X' && jogo[0][1] =='X' && jogo[0][2] =='X' ||
            jogo[1][0] =='X' && jogo[1][1] =='X' && jogo[1][2] =='X' ||
            jogo[2][0] =='X' && jogo[2][1] =='X' && jogo[2][2] =='X'){
                printf("\nParabens! O Jogador 2 venceu por linha!\n");
                ganhou = 1;
            }

            //verifica se alguem ganhou por coluna
            if(jogo[0][0] =='O' && jogo[1][0] =='O' && jogo[2][0] =='O' ||
            jogo[0][1] =='O' && jogo[1][1] =='O' && jogo[2][1] =='O' ||
            jogo[0][2] =='O' && jogo[1][2] =='O' && jogo[2][2] =='O'){
                printf("\nParabens! O Jogador 1 venceu por coluna!\n");
                ganhou = 1;
            }

            if(jogo[0][0] =='X' && jogo[1][0] =='X' && jogo[2][0] =='X' ||
            jogo[0][1] =='X' && jogo[1][1] =='X' && jogo[2][1] =='X' ||
            jogo[0][2] =='X' && jogo[1][2] =='X' && jogo[2][2] =='X'){
                printf("\nParabens! O Jogador 2 venceu por coluna!\n");
                ganhou = 1;
            }

            //verifica se alguem ganhou por diagonal principal
            if(jogo[0][0] =='O' && jogo[1][1] =='O' && jogo[2][2] =='O'){
                printf("\nParabens! O Jogador 1 venceu por diagonal principal!\n");
                ganhou = 1;
            }

            if(jogo[0][0] =='X' && jogo[1][1] =='X' && jogo[2][2] =='X'){
                printf("\nParabens! O Jogador 2 venceu por diagonal principal!\n");
                ganhou = 1;
            }

            //verifica se alguem ganhou por diagonal secundaria
            if(jogo[0][2] =='O' && jogo[1][1] =='O' && jogo[2][0] =='O'){
                printf("\nParabens! O Jogador 1 venceu por diagonal secundaria!\n");
                ganhou = 1;
            }

            if(jogo[0][2] =='X' && jogo[1][1] =='X' && jogo[2][0] =='X'){
                printf("\nParabens! O Jogador 2 venceu por diagonal secundaria!\n");
                ganhou = 1;
            }
        }while(ganhou == 0 && jogadas < 9);
        // verifica se teve ganhador
        if(ganhou == 0){
            printf("\nO jogo finalizou sem ganhador!\n");
        }
        // verifica se o usuario que jogar novamente
        printf("\nDigite 1 para jogar novamente: \n");
        scanf("%d", &opcao);
        
    }while(opcao == 1);

    return 0;
}