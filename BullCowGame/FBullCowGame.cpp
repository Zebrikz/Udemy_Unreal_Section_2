#include "FBullCowGame.h"

FCowBullGame::FCowBullGame()
{
	Reset();
}

int FCowBullGame::GetMaxTries() const { return MyMaxTries; }
int FCowBullGame::GetCurrentTry() const { return MyCurrentTry; }

void FCowBullGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	return;
}

bool FCowBullGame::IsGameWon() const
{
	return false;
}

bool FCowBullGame::CheckGuessValidity(std::string)
{
	return false;
}
