#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Card.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Hand.h>
#include <vector>

bj_Hand::bj_Hand() {
	m_Cards.reserve(7);
}

bj_Hand::~bj_Hand() {
	Clear();
}

void bj_Hand::Add(bj_Card* pCard) {
	m_Cards.push_back(pCard);
}

void bj_Hand::Clear() {
    std::vector<bj_Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        delete* iter;
        *iter = 0;
    }
    m_Cards.clear();
}

int GetTotal() const {
    if (m_Cards.empty()) return 0;

    if (m_Cards[0]->GetValue() == 0) return 0;

    int total = 0;
    std::vector<bj_Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        total += (*iter)->GetValue();

    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        if ((*iter)->GetValue() == bj_Card::ACE)
            containsAce = true;

    if (containsAce && total <= 11)
        total += 10;

    return total;
}