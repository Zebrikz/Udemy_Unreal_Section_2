#include "FBullCowGame.h"

int FCowBullGame::GetMaxTries() const { return MyMaxTries; }

int FCowBullGame::GetCurrentTry() const { return MyCurrentTry; }

void FCowBullGame::Reset()
{
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
