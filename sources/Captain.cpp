#include "Captain.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

namespace coup {
    
    Captain::Captain(Game &game, string const &name): Player(game,name){
        this->PlayerRole = "Captain";
        this->Playersteal= this;
    }
    void Captain::block(Player &player){

        if(player.PlayerRole == "Captain" && player.LastAction == "steal"){
            player.flagBlock = true;
            this->LastAction= "block";
        }
        else{
            player.flagBlock = false;

            throw invalid_argument("you can not block player that is not a captain");
        }
        this->game.counter++;
    }

    void Captain::steal(Player &player){
         if (this->flagBlock){
                player.PlayerCoin+=2;
                this->PlayerCoin-=2;
                this->flagBlock = false;
                return;
            }
        if(this->namePlayer != game.turn()){
                throw invalid_argument("this is not your turn!");
                
            }
            this->Playersteal =this;

        if(player.PlayerCoin > 1 && !this->flagBlock){
            this->flagBlock = false;
            player.PlayerCoin-=2;
            this->PlayerCoin+=2;
            this->LastAction = "steal";
            this->Playersteal = &player;
        }
        else if (player.PlayerCoin == 1){
            this->flagBlock = false;
            player.PlayerCoin-=1;
            this->PlayerCoin+=1;
            this->LastAction = "steal";
            this->Playersteal = &player;
        }
        else{
            this->flagBlock = false;
            throw invalid_argument("you can not steal coins from other player becouse someone blocked you!");
        }
            this->game.counter++;

    }

}
