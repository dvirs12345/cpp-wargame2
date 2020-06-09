// Author - Dvir Sadon
#include "Soldier.hpp"
#include "Board.hpp"
#define MAX_HEALTHPC 200
#define PARAMEDIC_TYPE 3 
#pragma once
using namespace std;

namespace WarGame
{
    class ParamedicCommander : public Soldier 
    {
        public:

            ParamedicCommander(){ this->hp = MAX_HEALTHPC; this->maxHP = MAX_HEALTHPC; this->type = 0; }
            ParamedicCommander(int player) { this->player = player; this->hp = MAX_HEALTHPC; this->maxHP = MAX_HEALTHPC; this->type = 0; }
            
            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                for(int i= 0; i < board.size(); ++i)
                    for(int j = 0; j < board[0].size(); ++j)
                        if(board[i][j] != nullptr && board[i][j]->player == this->player && board[i][j]->type == PARAMEDIC_TYPE)
                            board[i][j]->MAction(board, make_pair(i,j));
            }
    };
}