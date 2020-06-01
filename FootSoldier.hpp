// Author - Dvir Sadon
#include "Soldier.hpp"
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

            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
    };
}