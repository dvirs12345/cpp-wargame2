// Author - Dvir Sadon
#include "Soldier.hpp"

namespace WarGame
{
    class ParamedicCommander : public Soldier 
    {
        public:
            ParamedicCommander(){ this->hp = 200;}
            ParamedicCommander(int player) { this->player = player;}
    };
}