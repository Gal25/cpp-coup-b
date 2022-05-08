#include "Ambassador.hpp"
// #include "Player.hpp"
// #include "Captain.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

namespace coup {
    
    Ambassador::Ambassador(Game &game, string const &name) : Player(game,name){
        this->PlayerRole = "Ambassador";
    }

    void Ambassador::block(Captain &player){

        if (player.PlayerRole == "Captain" && player.LastAction == "steal"){
            player.flagBlock = true;
            player.steal(*player.Playersteal);
            this->LastAction = "block";
        }
        else{
            player.flagBlock = false;
            throw invalid_argument("you can not block player that is not a captain");
        }

    }

    void Ambassador::transfer(Player &player1, Player &player2){
        if(this->namePlayer != game.turn()){
            throw invalid_argument("this is not your turn!");

        }
        if (player1.coins() != 0){
                player2.PlayerCoin++;
                player1.PlayerCoin--;
                this->LastAction = "transfer";

        }
        else{
            throw invalid_argument("to player1 have not enough coins to transfer");
        }
        this->game.counter++;


    }

}
