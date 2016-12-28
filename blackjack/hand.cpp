#include "hand.h"

/*
 * Constructor for the Hand class
 */
Hand::Hand()
{

}

/*
 * Destructor for the Hand class.
 *
 * REMEMBER every class that inherits from Hand will call this method
 */
Hand::~Hand()  
{}

/*
 * Add a card to your hand
 *
 * Parameters: A card pointer for a card we wish to add to our hand
 * Returns: None
 */
void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}
 
/*
 * Cleans up all of the cards in our Hand.
 * This function must also delete all of the memory taken up by the cards
 *
 * Parameters: None
 * Returns: None
 */
void Hand::Clear()
{
	m_Cards.clear();
}

/*
 * Get the total points for our hand. Add up the points for each card
 * 
 * Parameters: none
 * Returns:
 *      If the hand is empty, return 0
 *      If one of the cards in the hand is face down, return 0
 *      Otherwise return the total value of all the cards in the hand.
 *      If one of the cards is an ACE and the total of the hand would be 21 or lower,
 *      treat the Ace as value 11 instead of 1.
 */
int Hand::GetTotal() const
{
    if (m_Cards.empty()) return 0;
    int points = 0;
    int i = 0;
    int temp;
    for (std::vector<Card*>::const_iterator it = m_Cards.begin(); it != m_Cards.end(); ++it) {
    	temp = m_Cards[i++]->GetValue();
    	if (temp == 0) return 0;
    	if (temp == 1 && points + 11 <= 21)
    		points += 21; 
    	else
    		points += temp;
    }
    return points;
}