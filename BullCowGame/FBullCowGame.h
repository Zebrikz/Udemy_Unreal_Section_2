#pragma once

#include <string>

// in unreal FString is used for game logic string manipulation
using FString = std::string;
// in unreal int32 is used to support cross-compatiability
using int32 = int;

class FCowBullGame {
public:
	FCowBullGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(FString); // TODO make a more rich return value.
	// provide a method for counting bulls & cows, and increasing turn numbers

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
};