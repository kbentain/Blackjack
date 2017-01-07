#ifndef CARD_H
#define CARD_H

#include "common.h"

class Card
{
public:
    /* 
    * An enumeration of the rank.
    *
    */
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
               JACK, QUEEN, KING};

    /* enumeration of the suit
    *
    */
    enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

    /* overloading << operator so can send Card object to standard output 
     * 
     * This function must be marked as a friend in order to read the values of Card
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);


    /* The Card constructor
     * Set the default values of a card to be ACE for rank, SPADES for suit, and true for ifu
     */
    Card(rank r = ACE, suit s = SPADES, bool ifu = true); 

    /*
    * returns the value of a card, 1 - 11 based on blackjack rules
    *
    */
    int GetValue() const;

    //flips a card; if face up, becomes face down and vice versa
    void Flip();
    
private:
    // Classic card values: Ace, 2-10, Jack, Queen, King
    rank m_Rank;

    // Classic card suits: Clubs, Diamonds, Hearts, Spades
    suit m_Suit;

    // Tell us whether our card is face up or not
    bool m_IsFaceUp;
};

#endif