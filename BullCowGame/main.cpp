#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FCowBullGame BCGame; // instantiate a new game

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
	int MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO change from FOR to while loop once we are validating tries
	for (int count = 1; count <= MaxTries; ++count) {
		std::string Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to the game
		// print number of bulls and cows

		std::cout << "Your guess was: " << Guess << '\n';
		std::cout << '\n';
	}

	// TODO summarise game
}

// introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH
		<< " letter isogram I'm thinking of?\n";
	std::cout << '\n';

	return;
}

std::string GetGuess() 
{
	// print the current try
	std::cout << "Try " << BCGame.GetCurrentTry() << ". ";

	// get the player's guess
	std::cout << "Type in your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);


	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you wanna play again (y/n)?\n";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

