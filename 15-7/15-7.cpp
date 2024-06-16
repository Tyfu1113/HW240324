#include <iostream>
#include <cstdlib>
#include <ctime>

class Dice {
public:
	Dice();
	Dice(int numSides);
	virtual int rollDice() const;
protected:
	int numSides;
};

Dice::Dice() : numSides(6) {
	srand(time(NULL)); // Seeds random number generator
}

Dice::Dice(int numSides) : numSides(numSides) {
	srand(time(NULL)); // Seeds random number generator
}

int Dice::rollDice() const {
	return (rand() % numSides) + 1;
}

// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2) {
	return die1.rollDice() + die2.rollDice();
}

class LoadedDice : public Dice {
public:
	LoadedDice();
	LoadedDice(int numSides);
	int rollDice() const override;
};

LoadedDice::LoadedDice() : Dice() {}

LoadedDice::LoadedDice(int numSides) : Dice(numSides) {}

int LoadedDice::rollDice() const {
	if (rand() % 2 == 0) { // 50% chance
		return numSides;
	} else {
		return Dice::rollDice();
	}
}

int main() {
	Dice die1(6);
	Dice die2(6);

	std::cout << "Rolling two standard dice 10 times:" << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << rollTwoDice(die1, die2) << std::endl;
	}

	LoadedDice ldie1(6);
	LoadedDice ldie2(6);

	std::cout << "Rolling two loaded dice 10 times:" << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << rollTwoDice(ldie1, ldie2) << std::endl;
	}

	return 0;
}
