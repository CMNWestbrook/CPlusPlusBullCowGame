#pragma once
// pragma once makes sure anything importend is only imported once
// never use namespace in header files

#include <string>

class FBullCowApp {
public:
	// public is stuff within interface
	FBullCowApp();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool WonOrLost() const;

	void Reset();
	bool CheckGuessIsCorrect(std::string);



private:
	// private is for helper functions and variables don't care about in interface
	// initialisation in constructor
	// could do it here if didn't need to change values each game
	int CurrentTry;
	int MaxTries;

};