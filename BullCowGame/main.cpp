/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// in unreal FText is used for strings displayed to the user 
using FText = std::string;
// in unreal int32 is used to support cross-compatiability
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
	bool IsGameRunning = false;
	do {
		PrintIntro();
		PlayGame();
		IsGameRunning = AskToPlayAgain();
	} while (IsGameRunning);
	return 0; // exit the application
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	for (int32 count = 1; count <= MaxTries; ++count) { // TODO change from FOR to while loop once we are validating tries
		FText Guess = GetValidGuess(); 

		// submit valid guess to the game, and receive counts
		FBullCowCount bull_cow_count = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << bull_cow_count.Bulls;
		std::cout << " Cows = " << bull_cow_count.Cows << "\n\n";
	}

	// TODO summarise game
}

// introduce the game
void PrintIntro() 
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength()
		<< " letter isogram I'm thinking of?\n";
	std::cout << '\n';

	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess() 
{
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		// get the player's guess
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Type in your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with no repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
}

bool AskToPlayAgain()
{
	std::cout << "Do you wanna play again (y/n)?\n";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

