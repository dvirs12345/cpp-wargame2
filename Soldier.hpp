/**
 * Header file for the Soldier of the war game.
 * 
 * @author Dvir Sadon
 * @since  2020-05
 */
#pragma once  
#include <iostream>
#include <vector>
using namespace std;

namespace WarGame
{
    class Soldier
    {
        public:
            int player;
            int hp;
            int maxHP;

            Soldier(){ ; }
            Soldier(int player, int hp, int maxHP){ this->player = player; this->hp = hp; this->maxHP = maxHP; }

            virtual void MAction(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
    };
}