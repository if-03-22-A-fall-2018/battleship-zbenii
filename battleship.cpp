/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

#include "battleship.h"

CellContent my[FIELDSIZE][FIELDSIZE];
CellContent op[FIELDSIZE][FIELDSIZE];
CellContent myguesses[FIELDSIZE][FIELDSIZE];

void load_game(){
  FILE *my_fd = fopen("battleship.my", "r");
  FILE *op_fd = fopen("battleship.op", "r");

  for(int i=0;i<FIELDSIZE;i++)
  {
    for(int x=0;x<FIELDSIZE;x++)
    {
      fread(&my[i][x],sizeof(CellContent),1,my_fd);
    }
  }

  for(int i=0;i<FIELDSIZE;i++)
  {
    for(int x=0;x<FIELDSIZE;x++)
    {
      fread(&op[i][x],sizeof(CellContent),1,op_fd);
    }
  }

  for(int i=0;i<FIELDSIZE;i++)
  {
    for(int x=0;x<FIELDSIZE;x++)
    {
      myguesses[i][x]=Unknown;
    }
  }

  fclose(my_fd);
  fclose(op_fd);
}

CellContent get_shot(int row, int col){
  if((row>=0&&row<FIELDSIZE)&&(col>=0&&col<FIELDSIZE))
  {
    return my[row][col];
  }
  return OutOfRange;
}

bool shoot(int row, int col){
  if((row>=0&&row<FIELDSIZE)&&(col>=0&&col<FIELDSIZE))
  {
    for(int i=-1;i<=1;++i)
    {
      for(int x=-1;x<=1;++x)
      {
        if(row+i>-1&&row+i<FIELDSIZE&&col+x>-1&&col+x<FIELDSIZE)
        {
          myguesses[row+i][col+x]=op[row+i][col+x];
        }
      }
    }
    return true;
  }
  return false;
}


CellContent get_my_guess(int row, int col){
  if((row>=0&&row<FIELDSIZE)&&(col>=0&&col<FIELDSIZE))
  {
    return myguesses[row][col];
  }
  return OutOfRange;
}
