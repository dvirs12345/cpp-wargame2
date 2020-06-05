// Author - Dvir Sadon
#include "Soldier.hpp"
#include "Board.hpp"
#define MAX_HEALTHS 100
#define DPAS 50
#pragma once
using namespace std;

namespace WarGame
{
    class Sniper : public Soldier 
    {
        public:
            int dpa;

            Sniper(){ this->hp = MAX_HEALTHS; this->dpa = DPAS; this->maxHP = MAX_HEALTHS; }
            Sniper(int player) { this->player = player;  this->hp = MAX_HEALTHS; this->dpa = DPAS; this->maxHP = MAX_HEALTHS; }

            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> dest_location) override
            {
                auto close = strongest(board, board[dest_location.first][dest_location.second]->player, dest_location);
                board[close.first][close.second]->hp = board[close.first][close.second]->hp - this->dpa; // Shoot!
                //(*close)->hp = (*close)->hp - this->dpa; 
            }
        
        private:
            pair<int, int> strongest(std::vector<std::vector<Soldier*>> &board, int playernum, pair<int, int> loc1)
            {
                int max = 0;
                int temp;
                pair<int, int> sol;
                for(int i= 0; i < board.size(); ++i)
                {
                    for(int j = 0; j < board[0].size(); ++j)
                    {
                        if(board[i][j] != nullptr)
                        {
                            temp = board[i][j]->hp;
                            if(temp >= max && board[i][j]->player != playernum)
                            {
                                max = temp;
                                sol.first = i;
                                sol.second = j;
                            }
                        } 
                    }  
                }
                return sol;
            }
    };
}