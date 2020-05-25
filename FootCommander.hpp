// Author - Dvir Sadon


namespace WarGame
{
    class FootCommander : public Soldier 
    {
        public:
            int dpa;

            FootCommander(){ this->hp = 150; this->dpa = 20; }
            FootCommander(int player) { this->player = player;}

    };
}