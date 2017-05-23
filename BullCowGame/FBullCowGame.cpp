#include "FBullCowGame.h"

// in unreal FString is used for game logic string manipulation
using FString = std::string;
// in unreal int32 is used to support cross-compatiability
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// receives a VALID guess, increments turn, and returns counts
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup return variable
	FBullCowCount bull_cow_count;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			if (Guess[GChar] == MyHiddenWord[MHWChar]) { // if they match then
				if (MHWChar == GChar) { // if they're in the same place
					bull_cow_count.Bulls++;	// increment bulls
				} else {
					bull_cow_count.Cows++; // increment cows
				}
			}
		}
	}

	return bull_cow_count;
}
