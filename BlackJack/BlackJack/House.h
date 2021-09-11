#pragma once
#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\GenericPlayer.h>

class House : public GenericPlayer {
public:
    House(const std::string& name = "House");

    virtual ~House();

    virtual bool IsHitting() const;

    void FlipFirstCard();
};