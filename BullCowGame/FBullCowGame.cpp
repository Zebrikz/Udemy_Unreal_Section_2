#include "FBullCowGame.h"

int FCowBullGame::GetMaxTries() { return MyMaxTries; }

int FCowBullGame::GetCurrentTry() { return MyCurrentTry; }

void FCowBullGame::Reset()
{
	return;
}

bool FCowBullGame::IsGameWon()
{
	return false;
}

bool FCowBullGame::CheckGuessValidity(std::string)
{
	return false;
}
