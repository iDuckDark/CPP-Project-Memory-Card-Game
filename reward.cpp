#include "reward.h"

Reward::Reward(int nRubies) {
    if (nRubies >= 1 && nRubies <= 4) {
        _nRubies = nRubies;
    } else {
        //TODO throw exception error to prevent contructor from being contruct
        cout << "Error Initializing Reward: Rubies must be only 1 to 4! " << endl;
    }
}


ostream &operator<<(ostream &os, const Reward &reward) {
    if (reward.getNRubies() > 1) {

        os << "Reward has " << reward.getNRubies() << " Rubies";
    } else {
        os << "Reward has 1 Ruby";

    }
    return os;
}

//bool Reward::operator<(const Reward &other1, const Reward &other2) {
//    return other1.getNRubies() < other2.getNRubies();
//}

int Reward::getNRubies() const {
    return _nRubies;
}