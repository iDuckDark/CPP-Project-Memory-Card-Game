#include "reward.h"

Reward::Reward(int nRubies) {
    if (nRubies >= 1 && nRubies <= 4) _nRubies = nRubies;
    else throw out_of_range("Error Initializing Reward: Rubies must be only 1 to 4! ");
}

int Reward::getNRubies() const { return _nRubies; }

ostream &operator<<(ostream &os, const Reward &reward) {
    os << "Reward has " << reward.getNRubies() << (reward.getNRubies() > 1 ? " Rubies" : " Ruby");
    return os;
}

//bool Reward::operator<(const Reward &other1, const Reward &other2) {
//    return other1.getNRubies() < other2.getNRubies();
//}

