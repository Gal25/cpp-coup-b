#include <vector>
#include <iostream>
// #include "Player.hpp"

#pragma once



using namespace std;

namespace coup {
    class Game{
        

        public:
        int counter;
        vector<string> players_names;
        bool startgame;


        Game();
        void putplayer(string const &namePlayer);
        void deletefromvec(string const &nametoDel);
        void addtovec(string const &name);
        string turn();
        vector<string> players() const;
        string winner()const;   
    };

    
}
