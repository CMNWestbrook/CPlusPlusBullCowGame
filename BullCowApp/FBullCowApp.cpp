#include "FBullCowApp.h"

// this is where constructor is defined to do what you want it to
FBullCowApp::FBullCowApp()
{
	// at runtime these will take over any initial values in the .h file
	//CurrentTry = 1;
	//MaxTries = 4;
	// instead of above we call reset
	Reset();
}

int32 FBullCowApp::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowApp::GetHiddenWordLen() const { return HiddenWord.length(); }
int32 FBullCowApp::GetMaxTries() const { return MaxTries; }
bool FBullCowApp::IsGameWon() const{ return bWonGame; }

void FBullCowApp::Reset()
{
	// making a constant expression MAX_TRIES makes it so 
	// it's easier to change MaxTries even when app gets very complex
	constexpr int32 MAX_TRIES = 4;
	MaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ughz";
	HiddenWord = HIDDEN_WORD;

	CurrentTry = 1;
	bWonGame = false;
	return;
}

EGuessStatus FBullCowApp::CheckGuessIsCorrect(FString Guess) const
{
	if (false) // if input not isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if guess not lowercase
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
