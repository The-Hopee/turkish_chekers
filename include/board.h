#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <iostream>

class Board
{
private:
    enum { Size = 8 };

    char board[Size][Size]; // gaming board

    void init_board()
    {
        int i,j;

        for( i = 0; i < Size; i++ )
        {
            for( j = 0; j < Size; j++ )
            {
                if( i == 1 || i == 2 || i == 5 || i == 6 )
                {
                    board[i][j] = '*';
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }
    }

public:
    Board()
    {
        init_board();
    }
    
    ~Board() = default;

    void print() const
    {
        int i,j;

        std::cout << "  A B C D E F G H" << std::endl;

        for( i = 0; i < Size; i++ )
        {
            std::cout << i + 1 << " ";
            for( j = 0; j < Size; j++ )
            {
                if( i == 1 || i == 2)
                {
                    std::cout << "\033[31m";
                }
                else if ( i == 5 || i == 6 )
                {
                    std::cout << "\033[0m";
                }
                std::cout << board[i][j] << " ";
                std::cout << "\033[0m";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    void update( const int row_from, const char column_from, const int row_to, const char column_to )
    {
        // step 1: find correct index into matrix;
        int col_from = -1;
        switch (column_from)
        {
        case 'A':
            col_from = 0;
            break;
        case 'B':
            col_from = 1;
            break;
        case 'C':
            col_from = 2;
            break;
        case 'D':
            col_from = 3;
            break;
        case 'E':
            col_from = 4;
            break;
        case 'F':
            col_from = 5;
            break;
        case 'G':
            col_from = 6;
            break;
        case 'H':
            col_from = 7;
            break;
        default:
            break;
        }

        int col_to = -1;

        switch (column_to)
        {
        case 'A':
            col_to = 0;
            break;
        case 'B':
            col_to = 1;
            break;
        case 'C':
            col_to = 2;
            break;
        case 'D':
            col_to = 3;
            break;
        case 'E':
            col_to = 4;
            break;
        case 'F':
            col_to = 5;
            break;
        case 'G':
            col_to = 6;
            break;
        case 'H':
            col_to = 7;
            break;
        default:
            break;
        }

        std::cout << row_from-1 << " " << col_from << " " << row_to-1 << " " << col_to << std::endl;
 
        board[row_from-1][col_from] = ' ';
        board[row_to-1][col_to] = '*';

        std::cout << "data: " <<  board[row_from-1][col_from] << " " << board[row_to-1][col_to] << std::endl;
    }
};

#endif