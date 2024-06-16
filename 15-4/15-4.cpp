//
//  15-4.cpp
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Creature {
private:
	int strength;   // How much damage we can inflict
	int hitpoints;  // How much damage we can sustain
public:
	Creature() : strength(10), hitpoints(10) {}
	Creature(int newStrength, int newHit) : strength(newStrength), hitpoints(newHit) {}

	int getStrength() const { return strength; }
	int getHitpoints() const { return hitpoints; }
	void setStrength(int newStrength) { strength = newStrength; }
	void setHitpoints(int newHit) { hitpoints = newHit; }

	virtual string getSpecies() const = 0;
	virtual int getDamage() const;
	virtual ~Creature() {}
};

int Creature::getDamage() const {
	int damage = (rand() % strength) + 1;
	cout << getSpecies() << " attacks for " << damage << " points!" << endl;
	return damage;
}

class Demon : public Creature {
public:
	Demon() : Creature() {}
	Demon(int newStrength, int newHit) : Creature(newStrength, newHit) {}

	int getDamage() const override;
	string getSpecies() const override { return "Demon"; }
};

int Demon::getDamage() const {
	int damage = Creature::getDamage();
	if ((rand() % 100) < 5) {
		damage += 50;
		cout << "Demonic attack inflicts 50 additional damage points!" << endl;
	}
	return damage;
}

class Elf : public Creature {
public:
	Elf() : Creature() {}
	Elf(int newStrength, int newHit) : Creature(newStrength, newHit) {}

	int getDamage() const override;
	string getSpecies() const override { return "Elf"; }
};

int Elf::getDamage() const {
	int damage = Creature::getDamage();
	if ((rand() % 10) == 0) {
		cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
		damage *= 2;
	}
	return damage;
}

class Human : public Creature {
public:
	Human() : Creature() {}
	Human(int newStrength, int newHit) : Creature(newStrength, newHit) {}

	string getSpecies() const override { return "Human"; }
};

class Cyberdemon : public Demon {
public:
	Cyberdemon() : Demon() {}
	Cyberdemon(int newStrength, int newHit) : Demon(newStrength, newHit) {}

	string getSpecies() const override { return "Cyberdemon"; }
};

class Balrog : public Demon {
public:
	Balrog() : Demon() {}
	Balrog(int newStrength, int newHit) : Demon(newStrength, newHit) {}

	int getDamage() const override;
	string getSpecies() const override { return "Balrog"; }
};

int Balrog::getDamage() const {
	int damage = Demon::getDamage();
	int damage2 = (rand() % getStrength()) + 1;
	cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
	return damage + damage2;
}

void battleArena(Creature &creature1, Creature &creature2) {
	while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
		int damage1 = creature1.getDamage();
		int damage2 = creature2.getDamage();

		creature2.setHitpoints(creature2.getHitpoints() - damage1);
		creature1.setHitpoints(creature1.getHitpoints() - damage2);

		cout << creature1.getSpecies() << " has " << creature1.getHitpoints() << " hit points remaining." << endl;
		cout << creature2.getSpecies() << " has " << creature2.getHitpoints() << " hit points remaining." << endl;

		if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0) {
			cout << "Both creatures have died. It's a tie!" << endl;
			return;
		} else if (creature1.getHitpoints() <= 0) {
			cout << creature2.getSpecies() << " wins!" << endl;
			return;
		} else if (creature2.getHitpoints() <= 0) {
			cout << creature1.getSpecies() << " wins!" << endl;
			return;
		}
	}
}

int main() {
	srand(time(0));

	Human human(20, 100);
	Cyberdemon cyberdemon(30, 100);
	Balrog balrog(40, 100);
	Elf elf(25, 100);

	cout << "Battle between Human and Cyberdemon:" << endl;
	battleArena(human, cyberdemon);

	cout << "\nBattle between Balrog and Elf:" << endl;
	battleArena(balrog, elf);

	cout << "\nBattle between Human and Elf:" << endl;
	battleArena(human, elf);

	cout << "\nBattle between Cyberdemon and Balrog:" << endl;
	battleArena(cyberdemon, balrog);

	return 0;
}
