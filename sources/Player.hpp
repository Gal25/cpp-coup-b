#include "Game.hpp"
#include <iostream>

#pragma once


using namespace std;

namespace coup {
    class Player {
            
        public:
            Game &game; 
            int PlayerCoin;
            string PlayerRole;
            string namePlayer;
            bool flagBlock;
            string LastAction;
            
            Player(Game &game,string const &nameplayer);
            void income();
            void foreign_aid();
            virtual void coup(Player &player);
            string role() const;
            int coins() const;
    };
}
