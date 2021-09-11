#pragma once
#include <iostream>

class bj_Card {
public:
    enum e_dignity {ACE = 1, TWO, THREE, FOUR, 
        FIVE, SIX, SEVEN, 
        EIGHT, NINE, TEN,
        JACK, QUEEN, KING, BACK };

    enum e_suit { DIAMONDS, HEARTS, CLUBS, SPADES};

    bj_Card(e_dignity d = ACE, e_suit s = SPADES, bool ifu = true) {};

    void Flip() {};

    int GetValue() const { };

    friend std::ostream& operator<<(std::ostream& os, const bj_Card& aCard);

private:
    e_dignity c_Dignity;
    e_suit c_Suit;
    bool m_IsFaceUp;

};



