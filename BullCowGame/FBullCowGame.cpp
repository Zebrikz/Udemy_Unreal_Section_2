#include "FBullCowGame.h"

// in unreal FString is used for game logic string manipulation
using FString = std::string;
// in unreal int32 is used to support cross-compatiability
using int32 = int;

FCowBullGame::FCowBullGame()
{
	Reset();
}

int32 FCowBullGame::GetMaxTries() const { return MyMaxTries; }
int32 FCowBullGame::GetCurrentTry() const { return MyCurrentTry; }

void FCowBullGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	return;
}

bool FCowBullGame::IsGameWon() const
{
	return false;
}

bool FCowBullGame::CheckGuessValidity(FString)
{
	return false;
}
