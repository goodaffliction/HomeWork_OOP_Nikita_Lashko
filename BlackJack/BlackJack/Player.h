#pragma once
#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\GenericPlayer.h>

class Player : public GenericPlayer {
public:
    Player(const std::string& name = "");

    virtual ~Player();

    virtual bool IsHitting() const;

    void Win() const;

    void Lose() const;

    void Push() const;
};