// Author - Dvir Sadon
#include "Soldier.hpp"

namespace WarGame
{
    class Sniper : public Soldier 
    {
        public:
            int dpa;

            Sniper(){ this->hp = 100; this->dpa = 50; }
            Sniper(int player) { this->player = player; }
    };
}