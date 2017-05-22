#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();

// the entry point for our application
int main()
{
	PrintIntro();
	PlayGame();
	return 0; // exit the application
}

void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; ++count) {
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << '\n';
		cout << '\n';
	}
}

// introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 9;

	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH
		<< " letter isogram I'm thinking of?\n";
	cout << '\n';

	return;
}

string GetGuess() 
{
	// get the player's guess
	cout << "Type in your guess: ";
	string Guess = "";
	getline(cin, Guess);


	return Guess;
}

