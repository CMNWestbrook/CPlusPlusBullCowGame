#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayTheGame();
string GuessPrompt();

// num of turns is same as word length, put at top to change easily
constexpr int NUM_OF_TURNS = 4;

// Beginning of app!
int main() 
{
	PrintIntro();
	PlayTheGame();
	cout << endl;
	return 0; // gets user out of the app
}

// introduce the game with basic text
void PrintIntro() {
	cout << "Wecome one and all to the Bulls and Cows game!\n";
	cout << "It's super fun, like so fun I can't even\n";
	cout << "Guess the " << NUM_OF_TURNS << " character isogram!\n\n";
	return;
}


void PlayTheGame()
{
	for (int i = 1; i <= NUM_OF_TURNS; i++) {
		string Guess = GuessPrompt();
		// repeat the guess back to the player by printing it
		cout << "Your guess is the word " << Guess << endl;
		cout << endl;
	}
}


// prompt the player to make a guess
string GuessPrompt() {
	cout << "Enter a word that's " << NUM_OF_TURNS << " characters long: ";
	string Guess = "";
	getline(cin, Guess);
	// cin >> Guess;
	return Guess;
}