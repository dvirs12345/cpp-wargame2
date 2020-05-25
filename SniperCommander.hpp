// Author - Dvir Sadon
#include "Soldier.hpp"

namespace WarGame
{
    class SniperCommander : public Soldier 
    {
        public:
            int dpa;

            SniperCommander(){ this->hp = 120; this->dpa = 100; }
            SniperCommander(int player) { this->player = player;}
    };
}