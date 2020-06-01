// Author - Dvir Sadon
#include "Soldier.hpp"
#pragma once 

namespace WarGame
{
    class FootSoldier : public Soldier 
    {
        public:
            int dpa;

            FootSoldier(){ this->hp = 100; this->dpa = 10; }
            FootSoldier(int player) { this->player = player;}

            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
    };
}