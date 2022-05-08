#include "Player.hpp"
#pragma once

using namespace std;

namespace coup {
    class Captain:public Player {

        public:
        Player* Playersteal;
        Captain(Game &game, string const &name);
        void block(Player &player);
        void steal(Player &player);
    };
}
