#include "FBullCowGame.h"

// in unreal FString is used for game logic string manipulation
using FString = std::string;
// in unreal int32 is used to support cross-compatiability
using int32 = int;

FCowBullGame::FCowBullGame()
{
	Reset();
}

int32 FCowBullGame::GetMaxTries() const { return MyMaxTries; }
int32 FCowBullGame::GetCurrentTry() const { return MyCurrentTry; }

void FCowBullGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FCowBullGame::IsGameWon() const
{
	return false;
}

bool FCowBullGame::CheckGuessValidity(FString)
{
	return false;
}

// receives a VALID guess, increments turn, and returns counts
BullCowCount FCowBullGame::SubmitGuess(FString)
{
	// increment the turn number
	MyCurrentTry++;

	// setup return variable
	BullCowCount bull_cow_count;

	// loop through all letters in the guess
		// compare letters against the hidden word

	return bull_cow_count;
}
