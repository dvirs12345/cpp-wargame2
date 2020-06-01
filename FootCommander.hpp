// Author - Dvir Sadon
#pragma once

namespace WarGame
{
    class FootCommander : public Soldier 
    {
        public:
            int dpa;

            FootCommander(){ this->hp = 150; this->dpa = 20; }
            FootCommander(int player) { this->player = player;}

            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override
            {
                
            }
    };
}