// Author - Dvir Sadon
#pragma once
#include "Soldier.hpp"
#define MAX_HPP 100
using namespace std;


namespace WarGame
{
    class Paramedic : public Soldier 
    {
        public:
            Paramedic(){ this->hp = MAX_HPP; this->maxHP = MAX_HPP; }
            Paramedic(int player) { this->player = player; this->hp = MAX_HPP; this->maxHP = MAX_HPP; }
            
            void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> dest_location) override 
            {
                int my_player = board[dest_location.first][dest_location.second]->player;
                
                
            }
    };
}