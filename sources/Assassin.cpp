#include "Assassin.hpp"
#include "Player.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

namespace coup {
    const int seven = 7;
    Assassin::Assassin(Game &game, string const &name): Player(game,name){
                this->PlayerRole = "Assassin";
                // this->placetocoup=0;
    }
    
    void Assassin::coup(Player &player){
        if(this->namePlayer != game.turn()){

                throw invalid_argument("this is not your turn!");
            }
        for (size_t i =0; i< this->game.players_names.size(); i++){
                if ( this->game.players_names[i]== '~'+player.namePlayer){
                    throw invalid_argument("this player is not in the game ");
                }
               
        }
        if(this->PlayerCoin >=3 && this->PlayerCoin < seven && !this->flagBlock){
            this->PlayerCoin -=3;
            this->flagBlock = false;
            this->LastAction = "coup";
            this->nametocoup = player.namePlayer;
            // this->placetocoup = player.place;
            this->game.deletefromvec(player.namePlayer);
        }
        else if(this->PlayerCoin >= seven && !this->flagBlock ){
 
            this->nametocoup = "playercoup";
            this->LastAction = "coup";
            this->PlayerCoin -=seven;
            this->flagBlock = false;
            this->game.deletefromvec(player.namePlayer);
        }
        else{
            this->flagBlock = false;

            throw invalid_argument("if you want to coup someone you need to have at list 3 coins");
        }

        this->game.counter++;
   
    }

}
