// Author - Dvir Sadon
#include "Soldier.hpp"
#include "Board.hpp"
#define MAX_HEALTHSC 120
#define DPASC 100
#define SNIPER_TYPE 2
#pragma once
using namespace std;

namespace WarGame
{
    class SniperCommander : public Soldier 
    {
        public:
            int dpa;

            SniperCommander(){ this->hp = MAX_HEALTHSC; this->dpa = DPASC; this->maxHP = MAX_HEALTHSC; this->type = 0; }
            SniperCommander(int player) { this->player = player; this->hp = MAX_HEALTHSC; this->dpa = DPASC; this->maxHP = MAX_HEALTHSC; this->type = 0; }
            
            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                for(int i= 0; i < board.size(); ++i)
                    for(int j = 0; j < board[0].size(); ++j)
                        if(board[i][j] != nullptr && board[i][j]->player == this->player && board[i][j]->type == SNIPER_TYPE)
                            board[i][j]->MAction(board, make_pair(i,j));
            }
    };
}