#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

// the entry point for our application
int main()
{
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0; // exit the application
}

void PlayGame()
{
	FCowBullGame BCGame; // instantiate a new game

	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; ++count) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << '\n';
		std::cout << '\n';
	}
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

