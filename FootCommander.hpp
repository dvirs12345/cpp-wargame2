// Author - Dvir Sadon
#pragma once
#include "Soldier.hpp"
#define MAX_HEALTHFC 150
#define DPAFC 20
#define FOOT_TYPE 1

namespace WarGame
{
    class FootCommander : public Soldier 
    {
        public:
            int dpa;

            FootCommander(){ this->hp = MAX_HEALTHFC; this->dpa = DPAFC; this->maxHP = MAX_HEALTHFC; this->type = 0; }
            FootCommander(int player) { this->player = player; this->hp = MAX_HEALTHFC; this->dpa = DPAFC; this->maxHP = MAX_HEALTHFC; this->type = 0; }

            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                for(int i= 0; i < board.size(); ++i)
                    for(int j = 0; j < board[0].size(); ++j)
                        if(board[i][j] != nullptr && board[i][j]->player == this->player && board[i][j]->type == FOOT_TYPE)
                            board[i][j]->MAction(board, make_pair(i,j));
            }
    };
}