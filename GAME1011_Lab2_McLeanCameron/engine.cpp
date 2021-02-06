#include "engine.h"

Jedi::Jedi(const string name, const int health) : Character(name, health)
{
	Jedi::SetName(name);
	SetHealth(health);
	SetWeapon();
}

Sith::Sith(const string name, const int health) :Character (name, health)
{
	Sith::SetName(name);
	SetHealth(health);
	SetWeapon();
}

Mandalorian::Mandalorian(const string name, const int health) : Character(name, health)
{
	Mandalorian::SetName(name);
	SetHealth(health);
	SetWeapon();
}

ostream& operator<<(ostream& output, Weapon* weapon)
{
	output << "Weapon: " << weapon->GetWeaponName() << "\n\n" << weapon->GetDesc() << "\n\nBase Weapon Damage: " << weapon->GetDamage() << "\n\nAbility 1: " << weapon->GetAbilities(0) << " | Ability 2: " << weapon->GetAbilities(1)
	<< " | Ability 3: " << weapon->GetAbilities(2) << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
	return output;
}

