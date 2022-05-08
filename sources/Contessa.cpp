#include "Contessa.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

namespace coup {
    
    Contessa::Contessa(Game &game, string const &name): Player(game,name){
        this->PlayerRole = "Contessa";

    }

    void Contessa::block(Assassin &player){
         if(player.nametocoup == "playercoup"){

                throw invalid_argument("the assasin no do coup!");
            }
  

        if(player.PlayerRole == "Assassin" && player.LastAction == "coup"){ 
            this->LastAction= "block";
            this->game.addtovec(player.nametocoup);            
            
        }
        else{
            player.flagBlock = false;

            throw invalid_argument("you can not block player that is not a Assassin");
        }
    }
}
