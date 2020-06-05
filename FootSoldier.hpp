// Author - Dvir Sadon
#include "Soldier.hpp"
#include <math.h> 
#define MAX_HEALTHFS 100
#define DPAFS 10
#pragma once 

namespace WarGame
{
    class FootSoldier : public Soldier 
    {
        public:
            int dpa;

            FootSoldier(){ this->hp = MAX_HEALTHFS; this->dpa = DPAFS; this->maxHP = MAX_HEALTHFS; }
            FootSoldier(int player) { this->player = player; this->hp = MAX_HEALTHFS; this->dpa = DPAFS; this->maxHP = MAX_HEALTHFS; }

            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> dest_location) override
            {
                Soldier** close = closest(board, board[dest_location.first][dest_location.second]->player, dest_location);
                (*close)->hp = (*close)->hp - this->dpa; // Shoot!
            }

        private:
            Soldier** closest(std::vector<std::vector<Soldier*>> &board, int playernum, pair<int, int> loc1)
            {
                int min = distance({0, 0}, {board.size(), board[0].size()})+1; // Bigger than the diagnal
                int temp;
                Soldier** sol;
                for(int i= 0; i < board.size(); ++i)
                {
                    for(int j = 0; j < board[0].size(); ++j)
                    {
                        if(board[i][j] != nullptr)
                        {
                            temp = distance({i, j}, {loc1.first, loc1.second});
                            if(temp <= min && board[i][j]->player != playernum)
                            {
                                min = temp;
                                *sol = board[i][j];
                            }
                        } 
                    }  
                }
                return sol;
            }

            int distance(pair<int, int> location1, pair<int, int> location2)
            {
                return sqrt((location1.first-location2.first)*(location1.first-location2.first) + 
                    (location1.second-location2.second)*(location1.second-location2.second));
            }
    };
}