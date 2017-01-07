#include "hand.h"

/*
 * Constructor for the Hand class
 */
Hand::Hand()
{
	m_Cards.reserve(7);
}

/*
 * Destructor for the Hand class.
 *
 * REMEMBER every class that inherits from Hand will call this method
 */
Hand::~Hand()  
{
	Clear();
}

/*
 * Add a card to your hand
 *
 * Parameters: A card pointer for a card we wish to add to our hand
 * Returns: None
 */
void Hand::Add(Card* pCard)
{
	if(pCard != nullptr)
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
	std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
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
    //if no cards in hand, return 0
    if (m_Cards.empty())
        return 0;
  
    //if a first card has value of 0, then card is face down; return 0
    if (m_Cards[0]->GetValue() == 0)
        return 0;
    
    //add up card values, treat each Ace as 1
    int total = 0;
    std::vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        total += (*iter)->GetValue();
                  
    //determine if hand contains an Ace
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        if ((*iter)->GetValue() == Card::ACE)
            containsAce = true;
          
    /* if hand contains Ace and total is low enough, treat Ace as 11
     * Don't forget if the total of the hand WITH the Ace would be 21,
     * we could only have 11 currently.
     * Also we can only do this for a maximum of one Ace. With two Aces we
     * would have a value of 22, which is over 21.
     */
    if (containsAce && total <= 11)
        //add only 10 since we've already added 1 for the Ace
        total += 10;   
            
    return total;
}