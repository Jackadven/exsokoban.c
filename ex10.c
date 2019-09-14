/***************************************************************************
 *   ex10.c                                   Version 20190912.090014      *
 *                                                                         *
 *   PROGRAMA QUE DECLARE UMA MATRIZ 3D DE STRINGS PARA LABIRINTO DO JOGO  *
 *   SOKOBAN, COM MOVIMENTACAO NAS TECLAS, <H>,<J>,<K> e <L>.              *
 *                                                                         *
 *   Copyright (C) 2019         by: Jefferson Queiroz Da Costa             *
 *                                  Leandro Dantas Lima                    *
 *                                  Arthur Caldas Trigueiro                *
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
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $gcc ex10.c -o ex10.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <string.h> /* Strings functions definitions */

/* ---------------------------------------------------------------------- */
/* prototypes */

#define MAP_WIDTH  7  /*Eixo X */
#define MAP_HEIDTH  8 /*Eixo Y */
#define STAGE  1 /*Fases do jogo*/

/* ---------------------------------------------------------------------- */
/* Funcao: Imprimir a matriz 3d do prototipo do jogo sokoban e movimentar-se nela.
 * 
 * Entrada: Teclas <H>, <J>, <K> ou <L> fornecidas pelo usuario.
 *
 * Saida: Printar a matriz 3d na tela; return_SUCCESS.
 *  
 */

int main(void)
{
    /* local declarations */
    int x; /*Eixo X*/
    int y; /*Eixo Y*/
    char h, H, j, J, k, K, l, L;   /* declaracao das teclas de acao */
    
    /*Declaracao da matriz a partir dos valores dos defines*/
    char map [MAP_HEIDTH][MAP_WIDTH]=
    {   
        "####  ",
        "# X#  ",
        "#  ###",
        "#HO  #",
        "#  H #",
        "#X ###",
        "####  "
    
    }; 

    
    
    /* ###### LACO PARA IMPRESSAO DO MAPA ######
     *
     * - O laco mais interno imprime cada um dos caracteres da string,
     *   o qual representa o eixo X;
     *
     *  . X comeca referenciando o primeiro elemento da string e o imprime; 
     *  . Apos isso ele adiciona 1(um) a variavel que representa o eixo X e
     *    imprime o proximo elemento da string, repetindo ate x < 6;
     *
     * - O primeiro laco ou laco mais externo representa o eixo y;
     *  . Ele e' responsavel por conter o laco que faz a impressao de 
     *    todos os caracteres do eixo x;
     *  . Ele e' responsavel por pular uma linha no eixo y apos a impressao
     *    dos elementos do eixo x;
     *  . Apos isso o y incrementa mmais 1(um) e retorna todo o proceso de 
     *    impressao do primero laco, ate y < 7 que seria a ultima linha do 
     *    eixo y. 
     */   
     
    for(y = 0; y < 7; y++)
    {

        for(x = 0; x < 6; x++)
    
        {
            printf("%c", map [y][x]);
    
        }
        printf("\n");

    }


    char tecla;
    printf("\nDIGITE UMA TECLA DE MOVIMENTACAO <H> - up, <J> - down, <K> - left ou <L> - right: ");
    scanf("%c", &tecla);

    if (tecla == h || H)
        printf("VOCE MOVEU O SOKO PARA CIMA!\n\n");
    

    /* para cada acao teremos que construir um novo mapa ou moveremos as posicoes automaticamente no mapa/matriz inicial? */

    /* char map [MAP_HEIDTH][MAP_WIDTH]=
                {
                    "####  ",
                    "# X#  ",
                    "# O###",
                    "#H   #",
                    "#  H #",
                    "#X ###",
                    "####  "
        
        
                    }; */
          
    return EXIT_SUCCESS;
}



/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

