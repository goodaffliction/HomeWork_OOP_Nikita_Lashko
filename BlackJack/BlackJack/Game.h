#pragma once
#include <iostream>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\House.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Deck.h>
#include <C:Users\good_\Desktop\ForTests\OOP\HomeWork7\BlackJack\BlackJack\Player.h>
#include <vector>

class Game
{
public:
    Game(const std::vector<std::string>& names);

    ~Game();

    void Play();

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
};
