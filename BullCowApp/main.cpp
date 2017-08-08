/* Introduction of class: 
This is the console executeable that makes use of the BullCow class.
For game logic see the FBullCowApp class
*/

#include <iostream>
#include <string>
#include "FBullCowApp.h"

// adjustment for Unreal - FText is for user interaction
using FText = std::string;
using int32 = int;

//using namespace std; too dangerous in wrong places or forgotten about

void PrintIntro();
void PlayTheGame();
FText GetCorrectGuess();
bool PlayAgainOption();
void PrintGameSummary();

FBullCowApp BCApp; // instantiation of a new game

// num of turns is same as word length, put at top to change easily
// constexpr int32 NUM_OF_CHARS = BCApp.GetHiddenWordLen();

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
	std::cout << "\nWelcome one and all to the Bulls and Cows game!\n";
	std::cout << "It's super fun, like so fun I can't even\n";
	std::cout << "Guess the " << BCApp.GetHiddenWordLen();
	std::cout << " character isogram!\n\n";
	return;
}


void PlayTheGame()
{
	// every time it's initialized the BCApp.Reset resets the values
	BCApp.Reset();
	int32 MaxTries = BCApp.GetMaxTries();

	// loop for each turn that we ask for guess while game is 
	// NOT yet won and also still tries remaining
	while(!BCApp.IsGameWon() && BCApp.GetCurrentTry() <= MaxTries){

	// ??change from FOR to WHILE loop once we start validating trires
	// for (int32 i = 1; i <= MaxTries; i++) 
		FText Guess = GetCorrectGuess();

		// Valid guess is submitted
		FBullCowCount BullCowCount = BCApp.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "  Cows = " << BullCowCount.Cows << "\n\n";
	}
	// TODO summary of game
	PrintGameSummary();
	return;
}

// prompt the player to make a guess
FText GetCorrectGuess() {
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from player
		int32 CurrentTry = BCApp.GetCurrentTry();
		std::cout << "This is guess number " << CurrentTry << ". \n";
		std::cout << "Enter a word that's " << BCApp.GetHiddenWordLen(); 
		std::cout << " characters long: ";
		
		std::getline(std::cin, Guess);

		Status = BCApp.CheckGuessIsCorrect(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Wrong length, enter a word with " << BCApp.GetHiddenWordLen() << " letters. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Enter a word that does not have repeating letters. \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters \n";
			break;
		default:
			// assumes the user guess is correct
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::All_Good); // keep going until no errors
	return Guess;
}

bool PlayAgainOption()
{
	std::cout << "Would you like to play again using the same hidden word? (Y/N) " ;
	FText UserResponse = "";
	std::getline(std::cin, UserResponse);
	std::cout << std::endl;
	// 1 is true 0 is false
	return (UserResponse[0] == 'y') || (UserResponse[0] == 'Y');
	// note to self, this doesn't work: return (UserResponse[0] == 'y' || 'Y');
}

void PrintGameSummary()
{
	if (BCApp.IsGameWon()) 
	{
		std::cout << "You have won! You may now return to the multiverse.\n\n";
	}
	else
	{
		std::cout << "No dice. Try again.\n";
	}
}
