#include <iostream>
#include <string>
#include "FBullCowApp.h"

//using namespace std; too dangerous in wrong places or forgotten about

void PrintIntro();
void PlayTheGame();
std::string GuessPrompt();
bool PlayAgainOption();

FBullCowApp BCApp; // instantiation of a new game

// num of turns is same as word length, put at top to change easily
constexpr int NUM_OF_CHARS = 4;

// Beginning of app!
int main() 
{
	bool bPlayingAgain = false;
	do
	{
	PrintIntro();
	PlayTheGame();
	bPlayingAgain = PlayAgainOption();
	}
	while (bPlayingAgain);

	return 0; // gets user out of the app
}

// introduce the game with basic text
void PrintIntro() {
	std::cout << "Wecome one and all to the Bulls and Cows game!\n";
	std::cout << "It's super fun, like so fun I can't even\n";
	std::cout << "Guess the " << NUM_OF_CHARS << " character isogram!\n\n";
	return;
}


void PlayTheGame()
{
	BCApp.Reset();
	int MaxTries = BCApp.GetMaxTries();

	for (int i = 1; i <= MaxTries; i++) {
		std::string Guess = GuessPrompt();
		// repeat the guess back to the player by printing it
		std::cout << "Your guess is the word " << Guess << "." << std::endl;
		std::cout << std::endl;
	}
}


// prompt the player to make a guess
std::string GuessPrompt() {
	int CurrentTry = BCApp.GetCurrentTry();
	std::cout << "Enter a word that's " << NUM_OF_CHARS << " characters long: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	std::cout << "This is guess number " << CurrentTry << ". ";
	// std::cin >> Guess;
	return Guess;
}

bool PlayAgainOption()
{
	std::cout << "Would you like to play again? (Y/N) " ;
	std::string UserResponse = "";
	std::getline(std::cin, UserResponse);
	std::cout << std::endl;
	// 1 is true 0 is false
	return (UserResponse[0] == 'y') || (UserResponse[0] == 'Y');
	// note to self, this doesn't work: return (UserResponse[0] == 'y' || 'Y');
}
