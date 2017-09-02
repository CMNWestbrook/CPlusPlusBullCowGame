# pragma once

#include "FBullCowApp.h"
#include <map> // library map
#define TMap std::map // instead of Using since less complex

// this is where constructor is defined to do what you want it to
FBullCowApp::FBullCowApp() //this is the default constructor
{
	// at runtime these will take over any initial values in the .h file
	//CurrentTry = 1;
	//MaxTries = 4;
	Reset(); // instead of above we call reset
}

int32 FBullCowApp::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowApp::GetHiddenWordLen() const { return HiddenWord.length(); }
bool FBullCowApp::IsGameWon() const{ return bWonGame; }

int32 FBullCowApp::GetMaxTries() const { 
	// return MaxTries;
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 5}, {5, 9}, {6, 12}, {7, 22} }
}; // braces can initialize
	return WordLengthToMaxTries[HiddenWord.length()];
}

void FBullCowApp::Reset()
{
	// making a constant expression MAX_TRIES makes it so 
	// it's easier to change MaxTries even when app gets very complex
	// constexpr int32 MAX_TRIES = 4; //deleted since max tries now dependent on HiddenWord length
	MaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ughz";
	HiddenWord = HIDDEN_WORD;

	CurrentTry = 1;
	bWonGame = false;
	return;
}

EGuessStatus FBullCowApp::CheckGuessIsCorrect(FString Guess) const
{
	if (!IsIsogram(Guess)) // if input not isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) // if guess not lowercase TODO write function if lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLen()) // if length of guess is incorrect
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::All_Good;
	}
		// return All_Good
}

// when valid guess recieved, increments turn, returns current turn
FBullCowCount FBullCowApp::SubmitValidGuess(FString Guess)
{
	CurrentTry++; // increment turn number
	// return variable
	FBullCowCount BullCowCount;

	// loop through all letters of the hidden word
	int32 WordLength = HiddenWord.length();
	for (int32 HWChar = 0; HWChar < WordLength; HWChar++) {
		//compare these letters against the user guess
		for (int32 GuessChar = 0; GuessChar < WordLength; GuessChar++) {
			// if they match
			if (Guess[GuessChar] == HiddenWord[HWChar]) {
				if (HWChar == GuessChar) { // if in same place
					BullCowCount.Bulls++; // increment bulls
				}
				else {
					BullCowCount.Cows++;// increment cows if not in same place
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bWonGame = true;
	}
	else {
		bWonGame = false;
	}
	return BullCowCount;
}

bool FBullCowApp::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	// loop through each letter of word
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) // like for letter in word?
	{
		Letter = tolower(Letter); // makes it so you can deal with mixed cases
		if (LetterSeen[Letter]) { // if letter is in map/dict
			return false; // no isogram yet
		} else {
			LetterSeen[Letter] = true; // add letter to the map/dictionary
		}		
	}
	return true;
}

bool FBullCowApp::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		// if isn't lowercase then return false
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}
