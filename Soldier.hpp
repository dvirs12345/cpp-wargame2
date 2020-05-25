/**
 * Header file for the Soldier of the war game.
 * 
 * @author Dvir Sadon
 * @since  2020-05
 */
#pragma once  

namespace WarGame
{
    class Soldier
    {
        public:
            int player;
            int hp;

            Soldier(){ ; }
            Soldier(int player, int hp){this->player = player; this->hp = hp;}
    };
}