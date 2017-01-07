//Blackjack
//Plays a simple version of the casino game of blackjack; for 1 - 7 players


#include "game.h"

/*
 * The constructor for a Blackjack game.
 * We must create a player for every player name given to us in the parameter std::vector
 * It must also populate the deck and shuffle the cards
 *
 * Parameters: A reference to a std::vector filled with names of the players
 */
Game::Game(const std::vector<std::string>& names)
{
    for (std::vector<std::string>::const_iterator pName = names.begin();
     pName != names.end(); ++pName)      
        m_Players.push_back(Player(*pName));
	m_Deck.Populate();
	m_Deck.Shuffle();
}

/*
 * The destructor for the blackjack game.
 */
Game::~Game()
{}

/*
 * All of the logic to play the blackjack game. You will need to follow the rules here.
 *
 * Start by dealing out a card to every player and then dealing a card to the House.
 * For a second time deal a card to every player and then deal a card to the House.
 * Make sure the first card of the House is flipped.
 *
 * Display every player's hand so they know what they have followed by the House's hand
 *
 * Deal additional cards to every player in order
 *
 * Flip the House's first card and print the hand of the House.
 *
 * Deal additional cards to the House. Then Check the win conditions
 *
 * If the house is busted, for every player which has not currently busted, announce
 * to them that they have won
 *
 * If the House did not bust we must check to see who won
 *
 * For every player, if they have not busted, check:
 * 1. If their total is greater than the house's total. Annouce that they've won.
 * 2. If their total is equal to the house's total. Annouce that they have pushed.
 * 3. Otherwise annouce that the player has lost.
 *
 * At the end, Make sure to clear the hands of each Player and the House.
 *
 * Parameters: None
 * Returns: None
 */
void Game::Play()
{
	//deal initial 2 cards to everyone
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
            m_Deck.Deal(*pPlayer);
        m_Deck.Deal(m_House);
    }
    
    //hide house's first card
    m_House.FlipFirstCard();    
    
    //display everyone's hand
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
        std::cout << *pPlayer << std::endl;
    std::cout << m_House << std::endl;

    //deal additional cards to players
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        m_Deck.AdditionalCards(*pPlayer);    

    //reveal house's first card
    m_House.FlipFirstCard();    
    std::cout << std::endl << m_House; 
  
    //deal additional cards to house
    m_Deck.AdditionalCards(m_House);

    if (m_House.IsBusted())
    {
        //everyone still playing wins
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
            if ( !(pPlayer->IsBusted()) )
                pPlayer->Win();
    }
    else
    {
         //compare each player still playing to house
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
            if ( !(pPlayer->IsBusted()) )
            {
                if (pPlayer->GetTotal() > m_House.GetTotal())
                    pPlayer->Win();
                else if (pPlayer->GetTotal() < m_House.GetTotal())
                    pPlayer->Lose();
                else
                    pPlayer->Push();
            }
    }

    //remove everyone's cards
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
        pPlayer->Clear();
    m_House.Clear();
}

