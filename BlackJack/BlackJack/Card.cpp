#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Card.h>
#include <vector>

bj_Card::bj_Card(e_dignity d, e_suit s, bool b) {
    c_Dignity = d;
    c_Suit = s;
    m_IsFaceUp = b;
}

void bj_Card::Flip() {
    m_IsFaceUp = !(m_IsFaceUp);
}

int bj_Card::GetValue() const {
    int value = 0;
    if (m_IsFaceUp) {
        value = c_Dignity;
        if (value > 10)
            value = 10;
    }
    return value;
}

std::ostream& operator<<(std::ostream& os, const bj_Card& aCard) {
    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const std::string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.m_IsFaceUp)
        os << RANKS[aCard.c_Dignity] << SUITS[aCard.c_Suit];
    else
        os << "XX";
    return os;
}