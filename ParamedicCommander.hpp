// Author - Dvir Sadon
#include "Soldier.hpp"
#include "Board.hpp"
#pragma once
using namespace std;

namespace WarGame
{
    class ParamedicCommander : public Soldier 
    {
        public:
            ParamedicCommander(){ this->hp = 200;}
            ParamedicCommander(int player) { this->player = player;}
            
            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
            
    };
}