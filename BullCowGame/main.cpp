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
void PrintGameSummary();

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

	// loop asking for guesses while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		// submit valid guess to the game, and receive counts
		FBullCowCount bull_cow_count = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << bull_cow_count.Bulls;
		std::cout << " Cows = " << bull_cow_count.Cows << "\n\n";
	}


	PrintGameSummary();
	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		//print won condition
		std::cout << "Congradulations! You won! *slow clapping*\n";
	}
	else {
		//prin lose condition
		std::cout << "Congradulations! You lost lawl! *slight faster clapping*\n";
	}

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
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		// get the player's guess
		std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << 
			". Type in your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with no repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play agian with the same hidden word (y/n)?\n";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

