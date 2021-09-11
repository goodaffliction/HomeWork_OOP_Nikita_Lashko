#pragma once
#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Card.h>

class bj_Hand {
protected:
    std::vector<bj_Card*> m_Cards;
public:
    bj_Hand();

    virtual ~bj_Hand();

    void Add(bj_Card*);

    void Clear();

    int GetTotal() const;
};
