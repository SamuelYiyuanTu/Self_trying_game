#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main (int argc, char* argv[]){

    if (argc > 4) 
    {
        printf(" 1.Too many arguments entered\n");
        printf(" 2.Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    }
    else if (argc < 4 ) 
    {
        printf (" 1.Not enough arguments entered \n");
        printf(" 2.Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    }
    else 
    {
        int row = atoi(argv[1]);
        int col = atoi(argv[2]);
        int num = atoi(argv[3]);

//**************allocate memory for table*****************************//
        char ** table = (char**)malloc((row+1)*sizeof(int*));
        for (int i = 0; i < row+1; i++)
            table[i] = (char*)malloc((col+1)*sizeof(char));


        for (int i = 0; i < row+1; i++)
        {
            for (int j = 0; j < col+1; j++)
            {
                table[i][j] = '*';
            }// inner for loop
        }// outter for loop

//***********************set up table******************************//
        
        int temp = row-1;
        for (int i = 0; i < row; i++)
        {
            table[i][0] = temp + '0';
            temp--;
        }

        table[row][0] = ' ';

        temp = 0;
        for (int i = 1; i < col+1; i++)
        {

            table[row][i] = temp + '0';
            temp++;
        }
//*******************done setting tables up *********************//

    int input = 0; 
    int count = 0;
    char player;
    int control[row+1];

    if (row > 1)
    {
        for (int i = 0; i < row; i++)
            control[i] = row - 1;

    }

    else if (row == 1)
        {
            for (int i = 0; i < 2; i++)
                control[i] = 1;
        }
    
    while (1)
    {

        for (int i = 0; i < row+1; i++)
        {
            for (int j = 0; j < col+1; j++)
            {
                printf("%c", table[i][j]);
            }// inner for loop
            printf("\n");
        }// outter for loop

        do
        {
            printf("Enter a column between 0 and %d to play in: ", col-1);
            scanf("%d", &input);
        } while(input < 0 || input >= col || control[input] <= 0 );

        if ((count%2) == 0) player = 'X';
        else player = 'O';

        if (table[control[input]][input+1] == '*')
        {
            table[control[input]][input+1] = player;
        }
        else
        {
            table[--control[input]][input+1] = player;
        }
        
         count++;
         printf("count = %d \n", count);
        if (count == row*col) 
            {
                for (int i = 0; i < row+1; i++)
                    {
                        for (int j = 0; j < col+1; j++)
                        {
                            printf("%c", table[i][j]);
                        }// inner for loop
                            printf("\n");
                    }// outter for loop
                printf("Tie game\n"); 
                return 0;
            }

        bool ansX = 0, ansO = 0;
        int dx[4] = {0,1,1,1};
        int dy[4] = {1,1,0,-1};

        if(count > num-1)
         {
            //printf("**********\n");   
            for (int i = 0; i < row; i++)
            {    
                for (int j = 1; j <= col; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int countX = 0, countO = 0;
                        for(int l = 0; l < num; l++)
                        {
                            int x = i + dx[k]*l;
                            int y = j + dy[k]*l;
                            //printf ("x = %d, y = %d \n", x, y);
                            if (x >= row || x < 0 || y > col || y < 1) break;
                            if (table[x][y] == 'X') countX++;
                            if (table[x][y] == 'O') countO++; 
                        }
                        if (countX == num) 
                            {
                                ansX = true; 
                                for (int i = 0; i < row+1; i++)
                                {
                                    for (int j = 0; j < col+1; j++)
                                    {
                                        printf("%c", table[i][j]);
                                    }// inner for loop
                                        printf("\n");
                                }// outter for loop
                                printf("player 1 wins!\n"); 
                                return 0;
                            }
                        if (countO == num) 
                            {
                                ansO = true; 
                                for (int i = 0; i < row+1; i++)
                                {
                                    for (int j = 0; j < col+1; j++)
                                    {
                                        printf("%c", table[i][j]);
                                    }// inner for loop
                                        printf("\n");
                                }// outter for loop
                                printf("player 2 wins!\n");
                                return 0;
                            }
                    }
                        
                }
            }

         } // if statement  
    }// while loop
    }// else function
    
return 0;
}


















