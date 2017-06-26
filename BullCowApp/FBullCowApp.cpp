#include "FBullCowApp.h"

FBullCowApp::FBullCowApp()
{
	CurrentTry = 1;
	MaxTries = 4;
}

// common format:
int FBullCowApp::GetMaxTries() const { return MaxTries; }
int FBullCowApp::GetCurrentTry() const { return CurrentTry; }

void FBullCowApp::Reset()
{
	return;
}

bool FBullCowApp::WonOrLost() const
{
	return false;
}

bool FBullCowApp::CheckGuessIsCorrect(std::string)
{
	return false;
}
