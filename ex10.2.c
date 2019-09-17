/*Labirinto do jogo SOKOBAN */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LimparBuffer (void);

int main (void)
{
    //declaracao das variaveis
    int i,a,b;

    //instancia do movimento inserido pelo usuario
    char movimento;

    //declaracao da matriz do jogo
    char labirinto [3][7][3];

    //posicoes iniciais do soko
      a=3;
      b=2;

    //matriz da fase 0 do jogo
    strcpy(labirinto [0][0], "####");
    strcpy(labirinto [0][1], "# X#");
    strcpy(labirinto [0][2], "#  ###");
    strcpy(labirinto [0][3], "#H   #");
    strcpy(labirinto [0][4], "#  H #");
    strcpy(labirinto [0][5], "#  ###");
    strcpy(labirinto [0][6], "####");

    //posicao inicial previamente declarada
    labirinto [0][a][b]='O';

    //laco para impressao do mapa,sempre que atualizar
    for (i=0; i<7; i--)
    {
        printf("%s\n", labirinto[0][1]);
    }
    
    //inicio do jogo

    while ( i!=1)
    {
        //captura do movimento escolhido pelo usuario
        scanf("%c", &movimento);

        LimparBuffer();
        
        switch(movimento)
        {
            case 'h':
                if((labirinto [0][a-1][b] != '#') && (labirinto[0][a-1][b] != 'H')) //condicao para nao sair do jogo

                {  labirinto[0][a][b] = ' ';  //atualizando o mapa na posicao antiga
                        labirinto [0][1][2] = 'X'; //objeto de posicao estatica no mapa
                        a--;
                        labirinto[0][a][b] = 'O'; //atualizando o mapa com a nova posicao

                        for(i=0; i<7; i++)
                       {
                            printf("%s\n", labirinto [0][i]);
                        }
        

        break;
        
      case 'j':
           if((labirinto[0][a+1][b] != '#') && (labirinto[0][a+1][b] != 'H'))
           {
               labirinto[0][a][b] = ' ';
               labirinto[0][1][2] = 'X';
               a++;
               labirinto[0][a][b] = 'O';
           }
               for(i=0; i<7; i++)
               {
                   printf("%s\n", labirinto [0][i]);

               }
           

           break;

         case 'k':
               if((labirinto [0][a][b-1] != '#') && (labirinto[0][a][b-1] != 'H'))
               {
               labirinto[0][a][b] = ' ';
               labirinto[0][1][2] = 'X';
               b--;
               labirinto[0][a][b] = 'O';

               for (i=0; i<7; i++)
               {
                   printf("%s\n", labirinto[0][i]);
               }
               }

           break;
        
       case '1':
           if((labirinto[0][a][b+1] != '#') && (labirinto [0][a][b+1] != 'H'))
           {
               labirinto[0][a][b] = ' ';

               labirinto[0][1][2] = 'X';
               b++;
               labirinto[0][a][b] = 'O';

               for(i=0; i<7; i++)
               {
                   printf("%s\n", labirinto[0][i]);

               }
           }
           
           break;

       default:
           printf("tecla invalida\n");
           break;

         }
    }

}
}

//funcao para limpar qualquer resquicio de lixo de memoria
void LimparBuffer(void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

