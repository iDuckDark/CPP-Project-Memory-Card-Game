//
// Created by iDarkDuck on 2018-10-19.
//

#include "reward.h"


Reward::Reward(int nRubies) {
    if (nRubies >= 1 && nRubies <= 4) {
        this->nRubies = nRubies;
    } else {
        cout << "Error Initializing Reward: Rubies must be only 1 to 4! " << endl;
    }
}


ostream &operator<<(ostream &os, const Reward &reward) {
    os << "Reward has " << reward.getNRubies() << "Rubies";
    return os;
}


//Added Functions
int Reward::getNRubies() const {
    return nRubies;
}