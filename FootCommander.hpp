// Author - Dvir Sadon
#pragma once
#include "Soldier.hpp"
#define MAX_HEALTHFC 150
#define DPAFC 20

namespace WarGame
{
    class FootCommander : public Soldier 
    {
        public:
            int dpa;

            FootCommander(){ this->hp = MAX_HEALTHFC; this->dpa = DPAFC; this->maxHP = MAX_HEALTHFC; }
            FootCommander(int player) { this->player = player; this->hp = MAX_HEALTHFC; this->dpa = DPAFC; this->maxHP = MAX_HEALTHFC; }

            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
    };
}