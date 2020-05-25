// Author - Dvir Sadon

#include "Board.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace WarGame
{
    enum MoveDIR { Up, Down, Right, Left };


    /* Operators [] */
    Soldier*& Board::operator[](std::pair<int,int> location) 
    { 
        static Soldier s1;
        Soldier *s2 = &s1;
        static Soldier*& s3 = s2; 
        return s3;
    }
    Soldier* Board::operator[](std::pair<int,int> location) const 
    {
        return new Soldier();
    }

    /* Move */
    void Board::move(unsigned int player_number, std::pair<int,int> source, MoveDIR direction) { ; }

    /* has soldiers */
    bool Board::has_soldiers(unsigned int player_number) const { return false; }
}