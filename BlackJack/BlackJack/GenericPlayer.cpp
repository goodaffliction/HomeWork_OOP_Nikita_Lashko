#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Card.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Hand.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\GenericPLayer.h>
#include <vector>

GenericPlayer::GenericPlayer(const std::string& name) :	m_Name(name) {}

GenericPlayer::~GenericPlayer() {}

bool GenericPlayer::IsBusted() const {
        return (GetTotal() > 21);
}

void GenericPlayer::Bust() const {
    std::cout << m_Name << ", you lose!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenPlr) {
    os << aGenPlr.m_Name << ":\t";
    std::vector<bj_Card*>::const_iterator pCard;
    if (!aGenPlr.m_Cards.empty()) {
        for (pCard = aGenPlr.m_Cards.begin(); pCard != aGenPlr.m_Cards.end(); ++pCard) {
            os << *(*pCard) << "\t";
        }
        if (aGenPlr.GetTotal() != 0) {
            std::cout << "(" << aGenPlr.GetTotal() << ")";
        }
    }
    else {
        os << "<empty>";
    }
    return os;
}