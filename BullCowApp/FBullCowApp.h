#pragma once
// pragma once makes sure anything importend is only imported once
// never use namespace in header files

#include <string>

// the following help the code conform to Unreal standards
using FString = std::string;
using int32 = int;

//struct is always public class
// all initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	All_Good,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowApp {
public:
	// public is stuff within interface best to only have methods and no variables
	FBullCowApp(); //constructor

	// const means can't change member variables of method

	int32 GetHiddenWordLen() const;
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessIsCorrect(FString) const;

	// a new type where we submit valid guess
	// counts bulls & cows and increment try # if guess is valid
	FBullCowCount SubmitValidGuess(FString);

	void Reset(); // TODO make a more rich? return value

private:
	// private is for helper functions and variables we don't care about in interface
	// initialisation is in constructor in FBullCowApp.cpp
	// could do it here if didn't need to change values each game
	int32 CurrentTry;
	// int32 MaxTries; //deleted since MaxTries now changes depending on word length
	FString HiddenWord;
	bool bWonGame;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};