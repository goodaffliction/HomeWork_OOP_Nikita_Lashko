#pragma once
#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Hand.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\GenericPLayer.h>

class Deck : public bj_Hand
{
public:
    Deck();

    virtual ~Deck();

    void Populate();

    void Shuffle();

    void Deal(bj_Hand& aHand);

    void AdditionalCards(GenericPlayer& aGenericPlayer);
};
