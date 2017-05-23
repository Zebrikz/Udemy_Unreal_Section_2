#pragma once

#include <string>

class FCowBullGame {
public:
	void Reset(); // TODO make a more rich return value.
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string); // TODO make a more rich return value.

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};