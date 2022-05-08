#include "Player.hpp"
#pragma once

using namespace std;

namespace coup {
    class Assassin:public Player {
  
        public:
        string nametocoup;
        // int placetocoup;
        Assassin(Game &game, string const &name);
        virtual void coup(Player &player);
    };
}
