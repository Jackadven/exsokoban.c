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
#include <string.h> /* Strings functions definitions */

/* ---------------------------------------------------------------------- */
/* prototypes */

#define MAP_WIDTH 7
#define MAP_HEIGHT 8
#define PLAYER_POSITION pos_y * MAP_WIDTH + pos_x

/* ---------------------------------------------------------------------- */
/* Funcao: Imprimir a matriz 3d do prototipo do jogo sokoban e movimentar-se nela.
 * 
 * Entrada: Teclas <H>, <J>, <K> ou <L> fornecidas pelo usuario.
 *
 * Saida: Printar a matriz 3d na tela; return_SUCCESS.
 *  
 */

char map[] = {

    "####  \n"
    "# x#  \n"
    "#  ###\n"
    "#HO  #\n"
    "#  H #\n"
    "#x ###\n"
    "####  \n"

};

int dest_squares[7];                                          /* array to store cell indexes for 'x' cells */

int GetDestSquares()                                          /* init 'x' cells indexes */
{
    int count, cell;                                          /* 'x' cell number, current cell index */

    for(int row = 0; row < MAP_HEIGHT; row++)                 /* loop ower map rows */
    {
        for(int col = 0; col < MAP_WIDTH; col++)              /* loop ower map columns */

    
        {
            cell = row * MAP_WIDTH + col;                     /* init current cell index */
                                               
            if(map[cell] == 'x' || map[cell] == 'V')          /* if 'x' cell is emty or with box on it */
                dest_squares[count++] = cell;                 /* store it in array */
        }
    }

    return count - 1;                                         /* return number of 'x' cells */
}

void GetPosition(int *pos_x, int *pos_y)
{
    int cell;                                                 /* current cell index */

    for(int row = 0; row < MAP_HEIGHT; row++)                 /* loop ower map rows */
    {
        for(int col = 0; col < MAP_WIDTH; col++)              /* loop ower map columns */
        {
            cell = row * MAP_WIDTH + col;                     /* init current cell index */
                                                                    
            if(map[cell] == 'O')                              /* if current cell on the map contains player */
        
            {
                *pos_x = col;                                 /* store player's x coordinate */
                *pos_y = row;                                 /* store player's y coordinate */
        
            }
    
    
        }
    }


}

void MoveCharacter(int pos_x, int pos_y, int offset)
{
    if(map[PLAYER_POSITION + offset] != '#')                  /* if player doesn't hit the wall */
    {
        if(((map[PLAYER_POSITION + offset] == 'H') ||         /* if player hits the box */
            (map[PLAYER_POSITION + offset] == 'V')) &&        /* or the box on 'x' cell */
            (map[PLAYER_POSITION + offset * 2] != '#' ||      /* and box doesn't hit a wall */
             map[PLAYER_POSITION + offset * 2] != 'H' ||      /* or another box */
             map[PLAYER_POSITION + offset * 2] != 'V'))       /* or box on 'x' cell */
    
        {
            map[PLAYER_POSITION] = ' ';                       /* clear previous player's position */
            pos_x += offset;                                  /* update player's coordinate */

            if(map[PLAYER_POSITION + offset] == ' ')          /* if the square next to the box is empty */
                map[PLAYER_POSITION + offset] = 'H';          /* push the box */

            else if(map[PLAYER_POSITION + offset] == 'x')     /* if the square next to the box is 'x' */
                map[PLAYER_POSITION + offset] = 'V';          /* mark the box is on it's place */

            else
        
            {
                map[PLAYER_POSITION - offset] = 'O';          /* if box hits the wall or another box */
                return;                                       /* don't push it any further */
        
            }

            map[PLAYER_POSITION] = 'O';                       /* draw the player in the new position */
    
        }

        else                                                  /* if the square next to the player is empty */
        {
            map[PLAYER_POSITION] = ' ';                       /* clear previous player position */
            pos_x += offset;                                  /* update player's coordinate */
            map[PLAYER_POSITION] = 'O';                       /* draw the player in the new position */
        }


    }   


}

int main()
{
    int key;                                                  /* user input key */
    int pos_x, pos_y;                                         /*  player's coordinates */
    int dest_count;                                           /*  'x' cells counter */

    int dest_num = GetDestSquares();                          /* get number of 'x' cells */

    printf("%s\n", map);                                      /* print map */

    while(key != 27)                                          /* game loop */
    {  
        GetPosition(&pos_x, &pos_y);                          /* get player's coordinates */
                                                       
        key = getchar();                                      /* get user input */

        switch(key)
    
        {
            /* move character up */
            case 'h':
                MoveCharacter(pos_x, pos_y, - MAP_WIDTH - 1); 
                break;
                
            /* move character down */
            case 'j':
                MoveCharacter(pos_x, pos_y, MAP_WIDTH + 1);
                break; 
                
            /* move character left */
            case 'k':
                MoveCharacter(pos_x, pos_y, -1);
                break; 
            
            /* move character right */
            case 'l':
                MoveCharacter(pos_x, pos_y, 1);
                break; 
        
    
        }
        
        dest_count = 0;                                       /* reset 'x' cells counter */
        
        for(int i = 0; i < 7; i++)                            /* for all destination squares */
        {            
            if(map[dest_squares[i]] == 'V') dest_count++;     /* increase 'x' cells counter if box is on 'x' cell */
    
            if(map[dest_squares[i]] == ' ')                   /* if 'x' cell has been erased */
                map[dest_squares[i]] = 'x';                   /* restore it */
        
        
        }
        
        printf("%s\n", map);                                  /* print map */
        
        /* if all boxes are on it's places break out of game loop */
        if(dest_num == dest_count)
        {
            printf("You win!\n");
            key = 27;
        
        
        }        
    }


    return 0;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

