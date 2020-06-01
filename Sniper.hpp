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

            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
    };
}