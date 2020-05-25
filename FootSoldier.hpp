// Author - Dvir Sadon
#include "Soldier.hpp"

namespace WarGame
{
    class FootSoldier : public Soldier 
    {
        public:
            int dpa;

            FootSoldier(){ this->hp = 100; this->dpa = 10; }
            FootSoldier(int player) { this->player = player;}
    };
}