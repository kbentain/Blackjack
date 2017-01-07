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
	std::vector<Player>::iterator players;
	for (int i = 0; i < 2; i++) {
		for (players = m_Players.begin();
		 players != m_Players.end(); ++players)      
        	m_Deck.Deal(*players);
    	m_Deck.Deal(m_House);
	}
	m_House.FlipFirstCard();
	for (players = m_Players.begin(); players != m_Players.end(); ++players)
		std::cout << *players << "\n";
	std::cout << m_House << "\n";
	for (players = m_Players.begin();
		 players != m_Players.end(); ++players)      
        	m_Deck.AdditionalCards(*players);
    m_House.FlipFirstCard();
    std::cout << m_House << "\n";
    m_Deck.AdditionalCards(m_House);
    if (m_House.IsBusted()) {
    	for (players = m_Players.begin(); players != m_Players.end(); ++players) {
    		if (!players->IsBusted())
    			players->Win();
    	}
    }
    else {
    	for (players = m_Players.begin(); players != m_Players.end(); ++players) {
    		if (!players->IsBusted()) {
    			if (players->GetTotal() > m_House.GetTotal())
    				players->Win();
    			else if (players->GetTotal() == m_House.GetTotal())
    				players->Push();
    			else
    				players->Lose();
    		}
    	}
    }
    for (players = m_Players.begin(); players != m_Players.end(); ++players)
    	players->Clear();
    m_House.Clear();
}

