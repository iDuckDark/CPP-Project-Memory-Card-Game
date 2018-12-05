#include "reward.h"
#include "rewarddeck.h"
#include <cassert>

//#define TEST_REWARD

Reward::Reward(const int &nRubies) {
    if (nRubies >= 1 && nRubies <= 4) _nRubies = nRubies;
    else throw out_of_range("Error Initializing Reward: Rubies must be only 1 to 4! ");
}

Reward::Reward(const Reward &reward) = default;

Reward &Reward::operator=(const Reward &reward) {
    if (this != &reward) this->_nRubies = reward.getNRubies();
    return (*this);
}

int Reward::getNRubies() const { return _nRubies; }

ostream &operator<<(ostream &os, const Reward &reward) {
    return (os << "Reward has " << reward.getNRubies() << (reward.getNRubies() > 1 ? " Rubies" : " Ruby"));
}

bool operator<(const Reward &r1, const Reward &r2) { return r1.getNRubies() < r2.getNRubies(); }

bool operator>(const Reward &r1, const Reward &r2) { return r1.getNRubies() > r2.getNRubies(); }

bool operator==(const Reward &r1, const Reward &r2) { return r1.getNRubies() == r2.getNRubies(); }

Reward &Reward::operator=(const int &nRubiesOther) {
    if (nRubiesOther >= 1 && nRubiesOther <= 4) _nRubies = nRubiesOther;
    else throw out_of_range("Error Equal Assignment Reward from int: Rubies must be only 1 to 4! ");
    return *this;
}

Reward::operator int() { return getNRubies(); }

#ifdef TEST_REWARD

int main() {
    cout<<"TEST_REWARD"<<endl;
    RewardDeck& r = RewardDeck::make_RewardDeck();
    Reward* reward = r.getNext();
    Reward* reward2 = r.getNext();
    for(int i = 0;i<6;i++){
        if(*reward>*reward2){
            assert(*reward>*reward2);
        }else if(*reward<*reward2){
            assert(*reward<*reward2);
        }else{
            assert(*reward == *reward2);
        }
        cout<<"Reward Value "<<reward2->getNRubies()<<endl;
        reward2 = r.getNext();
    }
}

#endif // TEST_REWARD