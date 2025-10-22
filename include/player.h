#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <memory>
#include "../include/board.h"

class Player
{
private:
    struct move
    {
        int m_row_from;
        char m_column_from;
        int m_row_to;
        char m_column_to;

        move(): m_row_from(-1), m_column_from('0'), m_row_to(-1), m_column_to('0') {}

        move( const int row_from, const char column_from, const int row_to, const char column_to ): 
        m_row_from(row_from), m_column_from(column_from), m_row_to(row_to), m_column_to(column_to) {}
    };

    move mv;

public:

    void get_input_from_user( Board& b )
    {
        std::cout << "input coordinate from u do move ( number and letter ) --> "; // do input and check to correct
        std::cin >> mv.m_row_from >> mv.m_column_from;

        if( !(mv.m_column_from >= 'A' && mv.m_column_from <= 'H') || !(mv.m_row_from >=0 && mv.m_row_from <= 8) )
        {
            std::cerr << "incorrect input for from move. Try again!" << std::endl;
            return;
        }

        std::cout << "input coordinate to u do move ( number and letter ) --> "; // do input and check to correct
        std::cin >> mv.m_row_to >> mv.m_column_to;

        if( !(mv.m_column_to >= 'A' && mv.m_column_to <= 'H') || !(mv.m_row_to >=0 && mv.m_row_to <= 8) )
        {
            std::cerr << "incorrect input for to move. Try again!" << std::endl;
            return;
        }

        // future: need do check for type of figure: if it damka, then she can move left right up down
        // if it default checker then she can move left right up but not down

        // if input correct, then we must update our board

        b.update( mv.m_row_from, mv.m_column_from, mv.m_row_to, mv.m_column_to );
    }
};

#endif