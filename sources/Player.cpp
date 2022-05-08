#include <vector>
#include <stdexcept>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"



using namespace std;

namespace coup {
        const int seven = 7;
        const int six =6;
        const int ten=10;
        Player::Player(Game &game , string const &nameplayer) : game(game) , namePlayer(nameplayer){
            if (game.startgame){
                throw invalid_argument("the game started");
            }
            game.putplayer(namePlayer);
            this->PlayerCoin=0;
            this->flagBlock = false;
            
        }
        void Player::income(){
            if(this->namePlayer != game.turn()){

                throw invalid_argument("this is not your turn!");
            }
             if ( this->game.players_names.size() == 1 ||this->game.players_names.size() >six ){
                 throw invalid_argument("11couldnt start a game with one player");
             }

            this->game.startgame = true;
            this->PlayerCoin+=1;
            this->LastAction ="income";
            this->game.counter++;
   
        
        }


         void Player::coup(Player &player){
              if(this->namePlayer != game.turn()){
                throw invalid_argument("this is not your turn!");
            }

             
            for (size_t i =0; i< this->game.players_names.size(); i++){
                if ( this->game.players_names[i]== '~'+player.namePlayer){
                    throw invalid_argument("this player is not in the game ");
                }
            }
            
            if(this->PlayerCoin >= seven){
                this->PlayerCoin -=seven;
                this->LastAction = "coup";
                this->game.deletefromvec(player.namePlayer);

            }
            else{
                throw invalid_argument("you can not coup the player becouse you do not have enough coins");
            }
            this->game.counter++;
            

        }
        void Player::foreign_aid(){
            if(this->flagBlock){
                this->flagBlock = false;
                this->PlayerCoin -=2;
                return;
            }
             if ( this->game.players_names.size() == 1 ||this->game.players_names.size() >six ){
                 throw invalid_argument("couldnt start a game with one player");
             }
             if (this->coins() >=ten){
                 throw invalid_argument("you need to coup");
             }
            if(this->namePlayer != game.turn()){
                throw invalid_argument("this is not your turn!");
            }
            this->game.startgame = true;
            this->PlayerCoin+=2;
            this->LastAction = "foreign_aid";
            this->game.counter++;

         }
        string Player::role() const{
            return this->PlayerRole;
        }
        int Player::coins() const{
            return this->PlayerCoin;
        } 
    
}
