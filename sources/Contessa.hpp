#include "Player.hpp"
#include "Assassin.hpp"

using namespace std;

namespace coup {
    class Contessa:public Player {

        public:
        Contessa(Game &game, string const &name);
        void block(Assassin &player);
    };
}
