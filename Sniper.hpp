// Author - Dvir Sadon
#include "Soldier.hpp"
#include "Board.hpp"
#pragma once
using namespace std;

namespace WarGame
{
    class Sniper : public Soldier 
    {
        public:
            int dpa;

            Sniper(){ this->hp = 100; this->dpa = 50; }
            Sniper(int player) { this->player = player; }

            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
    };
}