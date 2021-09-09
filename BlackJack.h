#pragma once
#include <vector>

class bj_Card {
private:
    e_dignity c_Dignity;
    e_suit c_Suit;
    bool m_IsFaceUp;

public:
    enum e_dignity {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING, BACK
    };
    enum e_suit { DIAMONDS, HEARTS, CLUBS, SPADES, UNKNOWN };

    bj_Card(e_dignity d, e_suit s, bool b) {
        c_Dignity = d;
        c_Suit = s;
        m_IsFaceUp = b;
    }
    void Card::Flip() {
        m_IsFaceUp = !(m_IsFaceUp);
    }

    int Card::GetValue() const {
        int value = 0;
        if (m_IsFaceUp) {
            value = e_dignity;
            if (value > 10)
                value = 10;
        }
        return value;
    }

    friend ostream& operator<<(ostream& os, const Card& aCard);
};

ostream& operator<<(ostream& os, const Card& aCard) {
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.m_IsFaceUp)
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    else
        os << "XX";
    return os;
}

class bj_Hand {
protected:
    vector<Card*> m_Cards;
public:
    Hand() {
        m_Cards.reserve(7);
    };

    virtual ~Hand() {
        Clear();
    };

    void Add(Card* pCard) {
        m_Cards.push_back(pCard);
    };

    void Clear() {
        vector<Card*>::iterator iter = m_Cards.begin();
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
            delete* iter;
            *iter = 0;
        }
        m_Cards.clear();
    };

    int GetTotal() const {
        if (m_Cards.empty()) return 0;

        if (m_Cards[0]->GetValue() == 0) return 0;

        int total = 0;
        vector<Card*>::const_iterator iter;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            total += (*iter)->GetValue();

        bool containsAce = false;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            if ((*iter)->GetValue() == Card::ACE)
                containsAce = true;

        if (containsAce && total <= 11)
            total += 10;

        return total;
    };
};

class GenericPlayer : public bj_Hand {
protected:
    string m_Name;
public:
    GenericPlayer(const std::string& name = "") : m_Name(name);
    virtual ~GenericPlayer() {}
    virtual bool IsHitting() const = 0;
    bool IsBusted() const {
        return (GetTotal() > 21);
    }
    void Bust() const {
        std::cout << m_Name << ", you lose!" << std::endl;
    }
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenPlr) {
        os << aGenPlr.m_Name << ":\t";
        vector<Card*>::const_iterator pCard;
        if (!aGenPlr.m_Cards.empty()) {
            for (pCard = aGenPlr.m_Cards.begin(); pCard != aGenPlr.m_Cards.end(); ++pCard) {
                os << *(*pCard) << "\t";
            }
            if (aGenericPlayer.GetTotal() != 0){
                cout << "(" << aGenericPlayer.GetTotal() << ")";
            }
        }
        else {
            os << "<empty>";
        }
        return os;
    }
};

class Player : public GenericPlayer {
public:
    Player(const string& name = "");
    virtual ~Player();
    virtual bool IsHitting() const {
        std::cout << m_Name << ", do you want a hit? (Y/N): ";
        char response;
        std::cin >> response;
        return (response == 'y' || response == 'Y');
    }
    void Win() const {
        std::cout << m_Name << " wins.\n";
    }
    void Lose() const {
        std::cout << m_Name << " loses.\n";
    }
    void Push() const {
        std::cout << m_Name << " pushes.\n";
    }
};

class House : public GenericPlayer {
public:
    House(const string& name = "House");
    virtual ~House();
    virtual bool IsHitting() const {
        return (GetTotal() <= 16);
    }
    void FlipFirstCard() {
        if (!(m_Cards.empty()))
            m_Cards[0]->Flip();
        else
            cout << "No card to flip!\n";
    }
};


