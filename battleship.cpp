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
    if(op[row][col]==Water)
    {
      myguesses[row][col]=Water;
      return true;
    }
    else if(op[row][col]==Boat)
    {
      myguesses[row][col]=Boat;

      /*
      for(int i=row-1;i<row+1;i++)
      {
        for(int x=col-1;x<col+1;x++)
        {
          if(i>=0&&i<FIELDSIZE&&x>=0&&x<FIELDSIZE)
          {
            myguesses[i][x]=Water;
          }
        }
      }
      */
      return true;
    }
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
