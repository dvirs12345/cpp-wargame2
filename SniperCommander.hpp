// Author - Dvir Sadon
#include "Soldier.hpp"
#include "Board.hpp"
#define MAX_HEALTHSC 120
#define DPASC 0
#pragma once
using namespace std;

namespace WarGame
{
    class SniperCommander : public Soldier 
    {
        public:
            int dpa;

            SniperCommander(){ this->hp = MAX_HEALTHSC; this->dpa = DPASC; this->maxHP = MAX_HEALTHSC; }
            SniperCommander(int player) { this->player = player; this->hp = MAX_HEALTHSC; this->dpa = DPASC; this->maxHP = MAX_HEALTHSC; }
            
            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
    };
}