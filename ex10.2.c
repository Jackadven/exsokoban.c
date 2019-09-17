/***************************************************************************
 *   ex10.c                                   Version 20190912.090014      *
 *                                                                         *
 *   PROGRAMA QUE DECLARE UMA MATRIZ 3D DE STRINGS PARA LABIRINTO DO JOGO  *
 *   SOKOBAN, COM MOVIMENTACAO NAS TECLAS, <H>,<J>,<K> e <L>.              *
 *                                                                         *
 *   Copyright (C) 2019         by: Jefferson Queiroz Da Costa             *
 *                                  Leandro Dantas Lima                    *
 *                                  Arthur Caldas Trigueiro                *
 *                                  Adalto Nathan Gomes De Lima            *
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the authors, please write to:                              *
 *                                                                         *
 *   Jefferson Queiroz Da Costa                                            *
 *   Email: jeffersonadven7@gmail.com                                      *
 *   Webpage: http://beco.poli.br/jackadven                                *
 *   Phone: (87) 99951-1215                                                *
 *                                                                         *
 *   Leandro Dantas Lima                                                   *
 *   Email: leandroautocontrole@gmail.com                                  *
 *   Webpage: http://beco.poli.br/leandroautocontrole                      *
 *   Phone: (81) 98861-9469                                                *
 *                                                                         *
 *   Arthur Caldas Trigueiro                                               *
 *   Email: arthurcaldas99@gmail.com                                       *
 *   Webpage: http://beco.poli.br/arthurcaldas99                           *
 *   Phone: (81) 987302181                                                 *
 *                                                                         *
 *   Adalto Nathan Gomes de Lima                                           *
 *   Email: an.tec.pec@gmail.com                                           *
 *   Webpage: http://beco.poli.br/angdl                                    *
 *   Phone: (81) 98344-2019                                                *
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $gcc ex10.c -o ex10.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h>
#include <string.h> /* Strings functions definitions */

/* ---------------------------------------------------------------------- */

void LimparBuffer (void);

int main (void)
{
    /* declaracao das variaveis */
    int i,a,b;

    /* instancia do movimento inserido pelo usuario */
    char movimento;

    /* declaracao da matriz do jogo */
    char labirinto [3][7][3];

    /* posicoes iniciais do soko */
      a=3;
      b=2;

    /* matriz da fase 0 do jogo */
    strcpy(labirinto [0][0], "####");
    strcpy(labirinto [0][1], "# X#");
    strcpy(labirinto [0][2], "#  ###");
    strcpy(labirinto [0][3], "#H   #");
    strcpy(labirinto [0][4], "#  H #");
    strcpy(labirinto [0][5], "#  ###");
    strcpy(labirinto [0][6], "####");

    /* posicao inicial previamente declarada */
    labirinto [0][a][b]='O';

    /* laco para impressao do mapa,sempre que atualizar */
    /* for (i=0; i<7; i--)
    {
        printf("%s\n", labirinto[0][1]);
    } */
    
    /* inicio do jogo */

    while ( i!=1)
    {
        /* captura do movimento escolhido pelo usuario */
        scanf("%c", &movimento);

        LimparBuffer();
        
        switch(movimento)
        {
            case 'h':
                if((labirinto [0][a-1][b] != '#') && (labirinto[0][a-1][b] != 'H')) /* condicao para nao sair do jogo */

                {  labirinto[0][a][b] = ' ';  /* atualizando o mapa na posicao antiga */
                        labirinto [0][1][2] = 'X'; /* objeto de posicao estatica no mapa */
                        a--;
                        labirinto[0][a][b] = 'O'; /* atualizando o mapa com a nova posicao */

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

/* funcao para limpar qualquer resquicio de lixo de memoria */
void LimparBuffer(void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

