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
                for(int i = dest_location.first-1; i < dest_location.second+1; i++)
                    for (int j = dest_location.second-1; j < dest_location.second+1; j++)
                        if(i >=0 && i < board.size() && j >= 0 && j < board[0].size()) // If within the board
                            if (board[i][j] != nullptr)
                                board[i][j]->hp = board[i][j]->maxHP; // Heal to full
            }
    };
}