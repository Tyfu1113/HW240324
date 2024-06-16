//
//  14-9.cpp
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

	virtual string getSpecies() const { return "Unknown"; }
	virtual int getDamage() const;
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

bool ContainsKeyword(const Creature& creature, const string& keyword) {
	return creature.getSpecies().find(keyword) != string::npos;
}

int main() {
	srand(time(0));

	Human human(23, 30);
	Cyberdemon cyberdemon(31, 40);
	Balrog balrog(39, 50);
	Elf elf(23, 35);

	cout << human.getSpecies() << " damage: " << human.getDamage() << endl;
	cout << cyberdemon.getSpecies() << " damage: " << cyberdemon.getDamage() << endl;
	cout << balrog.getSpecies() << " damage: " << balrog.getDamage() << endl;
	cout << elf.getSpecies() << " damage: " << elf.getDamage() << endl;

	return 0;
}
