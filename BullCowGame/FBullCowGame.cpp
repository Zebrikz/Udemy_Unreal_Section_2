#include "FBullCowGame.h"
#include <map>
#define TMap std::map

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
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return GameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	GameIsWon = false;
	return;
}



EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the guess isn't an iosgram 
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) { // if the guess isn't all lowercase 
		return EGuessStatus::Not_Lowercase; // TODO write function
	}
	else if (Guess.length() != GetHiddenWordLength()){ // if the guess length is wrong
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, increments turn, and returns counts
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount bull_cow_count;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
	
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar]) // if they match then
			{ 
				if (MHWChar == GChar) // if they're in the same place
				{ 
					bull_cow_count.Bulls++;	// increment bulls
				} else {
					bull_cow_count.Cows++; // increment cows
				}
			}
		}
	}

	if (bull_cow_count.Bulls == WordLength)
		GameIsWon = true;

	return bull_cow_count;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) return true;


	// setup our map
	TMap<char, bool> LetterSeen;
	
	// for all letters in the word
	for (auto Letter : Word) {
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter])
			return false; // we do NOT have an isogram
		else
			LetterSeen[Letter] = true;
	}

			
	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	//handle strings of zero lenght, \0, and spaces
	if (Word.length() <= 0)
		return true;
	
	//loop through the word checking if each letter is lowercase
	for (auto Letter : Word) {
		if (!islower(Letter))
			return false;
		else if (Letter == ' ')
			return false;
	}

	
	return true;
}
