// Author - Dvir Sadon
#include "Soldier.hpp"
#include "Board.hpp"
#pragma once
using namespace std;

namespace WarGame
{
    class SniperCommander : public Soldier 
    {
        public:
            int dpa;

            SniperCommander(){ this->hp = 120; this->dpa = 100; }
            SniperCommander(int player) { this->player = player;}
            
            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
    };
}