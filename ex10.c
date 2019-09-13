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

#define MAP_WIDTH  6  /*Eixo X */
#define MAP_HEIDTH  7 /*Eixo Y */
#define STAGE  1 /*Fases do jogo*/

/* ---------------------------------------------------------------------- */
/* Funcao: Imprimir a matriz 3d e movimentar-se nela
 * 
 * Entrada: Movimetacao do usuario
 *
 * Saida: Printar a matriz 3d
 * 
 *  ######## nao deveria ter o return SUCCESS tambem nao? ##########
 */

int main(void)
{
    /* local declarations */
    /*int i;  general index */
    int x; /*Eixo X*/
    int y; /*Eixo Y*/
    
    /*Declaracao da matriz apartir dos valores dos defines*/
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

    /* Laco para impressao do mapa:
     * -O laco mais interno imprime cada um dos caracteres da string,
     *  a qual representa o eixo X;
     *
     *  . X comeca referenciando o primeiro elemento da string e o imprime; 
     *  . Apos isso ele adiciona 1 a variavel que representa o eixo X e
     *    imprime o proxoimo elemento da string, repetindo ate x < 6;
     *
     * -O o primeiro laco ou laco mais externo representa o eixo y;
     *  . Ele e' responsavel por conter o loco que faz a impressao de 
     *    todos os caracteres do eixo x;
     *  . Ele e' responsavel por pular uma linha no eixo y apos a impressao
     *    dos elementos do eixo x;
     *  . Apos isso o y incrementa mmais 1 e retorna todo o proceso de 
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

    return EXIT_SUCCESS;
}



/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

