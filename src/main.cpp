#include "../include/board.h"
#include "../include/player.h"
#include "../include/cheker.h"

int main()
{
    Board board;
    Player p;
    
    while( true )
    {
        board.print(); // 1) print board
        p.get_input_from_user(board); // 2) get input
        // 3) ai do move
        // 4) update board and print
    }

    return 0;
}