#include "player.h"

/*
 * The Player constructor.
 * 
 * Call the super constructor with the given name
 */
Player::Player(const std::string& name):
	GenericPlayer(name)
{}

/*
 * Player destructor
 */
Player::~Player()
{}
    
/*
 * Prompt the player whether they wish to hit with the message
 * "<name>, do you want a hit? (Y/N): "
 * Use the standard input to record their answer.
 *
 * Parameters: None
 * Returns:
 *      true if the answer was 'y' or 'Y'
 *      false otherwise
 *
 */
bool Player::IsHitting() const
{
	std::cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

/*
 * Announce to the player that they have won. Use the message:
 * "<name> wins.\n"
 *
 * Parameters: None
 * Returns: None
 */
void Player::Win() const
{
	std::cout << m_Name << " wins.\n";
}

/*
 * Announce to the player that they have lost. Use the message:
 * "<name> loses.\n"
 *
 * Parameters: None
 * Returns: None
 */
void Player::Lose() const
{
	std::cout << m_Name << " loses.\n";
}

/*
 * Announce to the player that they have pushed (tied). Use the message:
 * "<name> pushes.\n"
 *
 * Parameters: None
 * Returns: None
 */
void Player::Push() const
{
	std::cout << m_Name << " pushes.\n";
}