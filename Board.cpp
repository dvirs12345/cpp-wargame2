// Author - Dvir Sadon

#include <iostream> 
#include "Board.hpp"
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

namespace WarGame
{
    enum MoveDIR { Up, Down, Right, Left };


    /* Operators [] */
    Soldier*& Board::operator[](std::pair<int,int> location) 
    { 
        return board[location.first][location.second];
    }
    Soldier* Board::operator[](std::pair<int,int> location) const 
    {
        return board[location.first][location.second];
    }

    /* Move */
    void Board::move(unsigned int player_number, std::pair<int,int> source, MoveDIR direction) 
    {
        std::pair<int, int> dest;
        Soldier* sol = (*this)[{source.first, source.second}];

        // Check if within the boundries of the board
        if((source.first <= 0 && direction == Up) || (source.second <= 0 && direction == Left))
            throw std::invalid_argument("Invalid Destination");
        
        else if((source.first >= board.size()-1 && direction == Down) || (source.second >= board[0].size() && direction == Right))
            throw std::invalid_argument("Invalid Destination");

        // Check if there is A soldier in the source position
        if(sol == nullptr)
            throw std::invalid_argument("No Soldier In The Source");
        
        // Check if the soldier is the right player's
        else if(sol->player != player_number)
            throw std::invalid_argument("The soldier is not the player's");
        
        // Set the value of the new 
        if(direction == Down)
            dest = make_pair(source.first+1, source.second);
        
        else if(direction == Up)
            dest = make_pair(source.first-1, source.second); 
        
        else if(direction == Left)
            dest = make_pair(source.first, source.second-1);
        
        else if(direction == Right)
            dest = make_pair(source.first, source.second+1);

        Soldier* sol2 = (*this)[{dest.first, dest.second}];
        // Check if destination is full
        if(sol2 == nullptr)
            throw std::invalid_argument("Destination is already full");

        (*this)[source] = nullptr;
        (*this)[dest] = sol;
        sol->MAction(board, dest);
    }

    /* has soldiers */
    bool Board::has_soldiers(unsigned int player_number) const 
    { 
        for(int i= 0; i< board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j) 
            {
                Soldier* sol = (*this)[{i, j}];
                if (sol != nullptr && sol->player == player_number)
                    return true;
            }
        return false;
    }
}