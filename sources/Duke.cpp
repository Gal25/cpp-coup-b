#include "Duke.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

namespace coup {
    
    Duke::Duke(Game &game, string const &name): Player(game,name){
        this->PlayerRole = "Duke";

    }
    void Duke::block(Player &player){
     
        if(player.LastAction == "foreign_aid"){
            player.flagBlock = true;
            this->LastAction = "block";
            player.foreign_aid();

        }
        else{
            player.flagBlock = false;

            throw invalid_argument("you can not block player that not chose action foreign_aid");

        }
    }

    void Duke::tax(){
        if(this->namePlayer != game.turn()){

            throw invalid_argument("this is not your turn!");
        }
        this->PlayerCoin+=3;
        this->LastAction ="tax";
        this->game.counter++;
    }

}
