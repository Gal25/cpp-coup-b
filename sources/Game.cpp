#include <vector>
#include <stdexcept>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"



using namespace std;

namespace coup {
        const int six =6;
        Game::Game(){
                string str;
                for(int i=0; i< players_names.size(); i++){
                        players_names.push_back(str);
                }
                this->counter=0;
                this->startgame =false;
        }

        void Game::putplayer(string const &namePlayer){
                if(this->players_names.size()>= six ){
                        throw invalid_argument("to much players");
                }
                this->players_names.push_back(namePlayer);
        }


        void Game::deletefromvec(string const &nametoDel){
                size_t j = 1;
                size_t k = 0;
                for (size_t i=0; i< this->players_names.size(); i++){
                        if(nametoDel == this->players_names[i]){
                                this->players_names[i] = '~'+this->players_names[i];
                        }
                }
        }

        void Game::addtovec(string const &name){
                size_t j = 0;
                size_t k = 0;
                for (size_t i=0; i< this->players_names.size(); i++){
                        if(this->players_names[i] == '~'+name){
                                this->players_names[i] = name; 
                        }
                }
        }

        string Game::turn(){
                int size =(this->players_names.size());
                size_t turn = size_t(this->counter % size);
                for(size_t i = 0; i <this->players_names.size(); i++){
                        if(this->players_names[turn][0]!= '~'){

                                return this->players_names[turn];
                        }
                        this->counter++;
                        turn= size_t(this->counter % size);

                }
                         return this->players_names[turn];
        }

        vector<string> Game::players() const{ 
                vector<string> newvec;
                for(size_t i = 0; i <this->players_names.size(); i++){
                        if(this->players_names[i][0]!= '~'){
                                newvec.push_back(this->players_names[i]);
                        }

                }

                return newvec;
        }

        string Game::winner()const{
               
                if(this->players().size() >1){
                        throw invalid_argument("the game is stil not over!");
                }
                 if (!this->startgame){
                        throw invalid_argument("the game need to start");
                }                
                return this->players().at(0);
        }   

    
}