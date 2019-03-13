/**
 * Code to determine if the given sudoko is valid.
 * @file   sudoko.c
 * @author Naveen Gunasekaran
 */

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
static char array[9] = {0};
bool flag;

char* clear_array (char *arr)
{   
    for (int i =0; i < 9; i++)
    {
        arr[i] = 0;
    }
    return arr;
}

bool check_array (char *arr)
{   
    flag = true;
    for (int i =0; i < 9; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            if ((arr[i] == arr[j]) && (arr[i] != '.'))
            {
                flag = false;
                break;
            }            
        }
        if (flag == false)
        {
            return flag;
        }
    }
    return flag;
}

bool isValidSudoku(char board[][9], int boardRowSize, int boardColSize) 
{
    flag = true;
    char *array_test;
    array_test = array;

    for (int row = 0; row < boardRowSize; row++)
    {
        array_test = clear_array (array); 
        int index = 0;
        for (int column = 0; column < boardColSize; column++)
        {
            array_test[index] = board[row][column];
            index ++;
        }
        
        flag = check_array(array_test);
        if (flag == false)
        {
            return false;
        }
    }
    
    for (int column = 0; column < boardColSize; column++)
    {
        array_test = clear_array (array);
        int index = 0;
        for (int row = 0; row < boardRowSize; row++)
        {
            array_test[index] = board[row][column];
            index ++;
        }
       
        flag = check_array(array_test);
        if (flag == false)
        {
            return false;
        }
    }
      
    for (int inner = 0; inner < 9; inner += 3)
    {
        int limit_r = inner + 3;
        for (int outer = 0; outer < 9; outer += 3)
        {
            int index = 0;
            array_test = clear_array (array);
            int limit = outer + 3;
            for (int row = inner; row < limit_r; row++)
            {
                for (int column = outer; column < limit; column++)
                {
                    array_test[index] = board[row][column];
                    index ++;
                }
            }
        
            flag = check_array(array_test);
            
            if (flag == false)
            {
                return false;
            }
        }
    }
       
    
    return true;   
}

int main()
{
  char array [9][9] = {{'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}};

    bool f;
    f = isValidSudoku (array, 9, 9);
    printf ("RESULT: ");
    printf(f ? "true" : "false");
    printf ("\n");
  
    return 0;
}

