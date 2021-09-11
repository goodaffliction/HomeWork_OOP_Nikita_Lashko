#pragma once
#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Card.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Hand.h>
#include <vector>

class GenericPlayer : public bj_Hand {
protected:
    std::string m_Name;
public:
    GenericPlayer(const std::string& name = "");

    virtual ~GenericPlayer();

    virtual bool IsHitting() const = 0;

    bool IsBusted() const;

    void Bust() const;

    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
};