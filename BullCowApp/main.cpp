#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GuessPromptAndPrintBack();

// num of turns is same as word length
constexpr int WORD_LENGTH = 3;

// beginning of app
int main() 
{
	PrintIntro();

	for (int i = 1; i <= WORD_LENGTH; i++)
	{
		GuessPromptAndPrintBack();
		cout << endl;
	}

	cout << endl;
	return 0;
}

// introduce the game with basic text
void PrintIntro() {
	cout << "Wecome one and all to the Bulls and Cows game!\n";
	cout << "It's super fun, like so fun I can't even\n";
	cout << "Guess the " << WORD_LENGTH << " character isogram!\n\n";
	return;
}

// prompt the player to make a guess
string GuessPromptAndPrintBack() {
	cout << "Enter a word that's " << WORD_LENGTH << " characters long: ";
	string Guess = "";
	getline(cin, Guess);
	// cin >> Guess;
	// repeat the guess back to the player by printing it
	cout << "Your guess is the word " << Guess << endl;
	return Guess;
}