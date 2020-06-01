// Author - Dvir Sadon
#pragma once
#include "Soldier.hpp"
using namespace std;


namespace WarGame
{
    class Paramedic : public Soldier 
    {
        public:
            Paramedic(){ this->hp = 100; }
            Paramedic(int player) { this->player = player;}
            
            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override 
            {

            }
    };
}