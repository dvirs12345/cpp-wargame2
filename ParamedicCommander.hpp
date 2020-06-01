// Author - Dvir Sadon
#include "Soldier.hpp"
#include "Board.hpp"
#define MAX_HEALTHPC 200
#pragma once
using namespace std;

namespace WarGame
{
    class ParamedicCommander : public Soldier 
    {
        public:

            ParamedicCommander(){ this->hp = MAX_HEALTHPC; this->maxHP = MAX_HEALTHPC; }
            ParamedicCommander(int player) { this->player = player; this->hp = MAX_HEALTHPC; this->maxHP = MAX_HEALTHPC; }
            
            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
            
    };
}