// Author - Dvir Sadon
#include "Soldier.hpp"

namespace WarGame
{
    class Paramedic : public Soldier 
    {
        public:
            Paramedic(){ this->hp = 100; }
            Paramedic(int player) { this->player = player;}
    };
}