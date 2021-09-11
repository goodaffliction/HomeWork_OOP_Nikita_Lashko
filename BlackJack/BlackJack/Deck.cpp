#pragma once
#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Card.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Hand.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\GenericPLayer.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Deck.h>
#include <algorithm>

Deck::Deck(){
    m_Cards.reserve(52);
    Populate();
}

Deck::~Deck(){}

void Deck::Populate() {
    Clear();
    for (int s = bj_Card::DIAMONDS; s <= bj_Card::SPADES; ++s)    {
        for (int r = bj_Card::ACE; r <= bj_Card::KING; ++r)        {
            Add(new bj_Card(static_cast<bj_Card::e_dignity>(r),
                static_cast<bj_Card::e_suit>(s)));
        }
    }
}

void Deck::Deal(bj_Hand& aHand) {
    if (!m_Cards.empty())    {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else    {
        std::cout << "Out of cards. Unable to deal.";
    }
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer) {
    std::cout << std::endl;
    while (!(aGenericPlayer.IsBusted()) || aGenericPlayer.IsHitting()) {
        Deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;

        if (aGenericPlayer.IsBusted()) {
            aGenericPlayer.Bust();
        }
    }
}

