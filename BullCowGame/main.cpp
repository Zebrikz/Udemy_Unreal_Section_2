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
FText GetGuess();
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
	// TODO change from FOR to while loop once we are validating tries
	for (int32 count = 1; count <= MaxTries; ++count) {
		FText Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to the game, and receive counts
		FBullCowCount bull_cow_count = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << bull_cow_count.Bulls;
		std::cout << " Cows = " << bull_cow_count.Cows << '\n';

		std::cout << "Your guess was: " << Guess << '\n';
		std::cout << '\n';
	}

	// TODO summarise game
}

// introduce the game
void PrintIntro() 
{
	constexpr int32 WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH
		<< " letter isogram I'm thinking of?\n";
	std::cout << '\n';

	return;
}

FText GetGuess() 
{
	// print the current try
	std::cout << "Try " << BCGame.GetCurrentTry() << ". ";

	// get the player's guess
	std::cout << "Type in your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);


	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you wanna play again (y/n)?\n";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

