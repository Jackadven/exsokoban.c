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

#define MAP_WIDTH = 10
#define MAP_HEIDTH = 10
#define STAGE = 1

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
    int i; /* general index */
    char map [STAGE][MAP_HEIDTH][MAP_WIDTH]=
    {   
        "####  ",
        "# X#  ",
        "#  ###",
        "#HO  #",
        "#  H #",
        "#X ###",
        "####  "
    };
    
    
        printf("%s", map);
    
  
    return EXIT_SUCCESS;
}



/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

