#include "main.h"

/*
 * This is your main title screen for your game
 *
 * Start by setting up the seed for your random number generator
 * Print a message to your players that they are playing your game!
 * Find out how many players wish to play (between [1, 7])
 *
 * Use the standard input to find out their names then create a blackjack game
 * Create some loop logic such that we can play the game over and over again
 * so long as the players say they wish to play again.
 */
int main()
{
	srand(time(0));
    std::cout << "\t\tWelcome to Blackjack!\n\n";
    
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        std::cout << "How many players? (1 - 7): ";
        std::cin >> numPlayers;
    }   

    std::vector<std::string> names;
    std::string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        std::cout << "Enter player name: ";
        std::cin >> name;
        names.push_back(name);
    }
    std::cout << std::endl;

    //the game loop        
    Game aGame(names);
    char again = 'y';
    do
    {
        aGame.Play();
        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> again;
    } while (again == 'y' || again == 'Y');

    std::cout << "Thank you so much for playing our game!\n";
    return 0;
}