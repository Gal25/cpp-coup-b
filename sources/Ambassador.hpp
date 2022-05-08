#include "Player.hpp"
#include "Captain.hpp"

using namespace std;

namespace coup {
    class Ambassador:public Player {

        public:
        Ambassador(Game &game, string const &name);
        void block(Captain &player);
        void transfer(Player &player1, Player &player2);
    };
}
