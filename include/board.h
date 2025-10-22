#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <iostream>

#include "../include/cheker.h"

void swap( checker& obj1, checker& obj2 )
{
    auto temp = obj1;
    // swapping figures and colors and statuses
    obj1.setFigure( obj2.getFigure() );
    obj1.setColor ( obj2.getColor()  );
    obj1.setStatus( obj2.getStatus() );

    obj2.setFigure( temp.getFigure() );
    obj2.setColor ( temp.getColor()  );
    obj2.setStatus( temp.getStatus() );

    return;
}

class Board
{
private:
    enum { Size = 8 };

    checker board[Size][Size]; // gaming board

    void init_board()
    {
        int i,j;

        for( i = 0; i < Size; i++ )
        {
            for( j = 0; j < Size; j++ )
            {
                if( i == 1 || i == 2 )
                {
                    board[i][j].setColor('R');
                    board[i][j].setFigure('*');
                }
                else if( i == 5 || i == 6 )
                {
                    board[i][j].setColor('W');
                    board[i][j].setFigure('*');
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
                if( board[i][j].getColor() == 'R' )
                {
                    std::cout << "\033[31m";
                    std::cout << board[i][j].getFigure() << " ";
                    std::cout << "\033[0m";
                }
                else if ( board[i][j].getColor() == 'W' )
                {
                    std::cout << board[i][j].getFigure() << " ";
                }
                else
                {
                    std::cout << board[i][j].getFigure() << " ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    void update( const int row_from, const char column_from, const int row_to, const char column_to )
    {
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

        std::cout << std::endl;

        // todoo: need to check type of checker: damka or basic

        if( board[row_from-1][col_from].getStatus() ) // if this damka then we have 4 moves ( great )
        {
            // check what we not do diagonal move

            if( abs(row_from - row_to) >= 1 && abs(col_from - col_to) >= 1 )
            {
                std::cerr << "u can`t do this move into this game! ( damka diagonal move )" << std::endl;
                return;
            }
        }
        else if( !board[row_from-1][col_from].getStatus() ) // else if this basic checker then we have 3 moves ( have problems )
        {
            // check what not do diagonal move and back move and distance == 1

            if( abs(row_from - row_to) >= 1 && abs(col_from - col_to) >= 1 ) // diagonal ( great )
            {
                std::cerr << "u can`t do this move into this game! ( default checker diagonal move )" << std::endl;
                return;
            }

            if( ( row_to - row_from  != 1 && col_from - col_to == 0 ) || ( abs(col_from - col_to) != 1 && row_from - row_to == 0) ) // move back + distance > 1
            {
                std::cerr << "u can`t do this move into this game ( default checker basic move )!" << std::endl;
                return;
            }
        }

        if( board[row_from-1][col_from].getColor() == 'W' && row_to == 1 )
        {
            if( !board[row_from-1][col_from].getStatus() )
            {
                board[row_from-1][col_from].setStatus(true);
                board[row_from-1][col_from].setFigure('D');
            }
        }
        else if( board[row_from-1][col_from].getColor() == 'R' && row_to == 8 )
        {
            if( !board[row_from-1][col_from].getStatus() )
            {
                board[row_from-1][col_from].setStatus(true);
                board[row_from-1][col_from].setFigure('D');
            }
        }

        swap(board[row_from-1][col_from], board[row_to-1][col_to]);
    }
};

#endif