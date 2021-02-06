#include "engine.h"

Jedi::Jedi(string name, int health) : Character(name, health)
{
	SetName(name);
	SetHealth(health);
	SetWeapon();
}

Sith::Sith(string name, int health) :Character (name, health)
{
	SetName(name);
	SetHealth(health);
	SetWeapon();
}

Mandalorian::Mandalorian(string name, int health) : Character(name, health)
{
	SetName(name);
	SetHealth(health);
	SetWeapon();
}

ostream& operator<<(ostream& out, Weapon* weapon)
{
	out << "Weapon: " << weapon->GetWeaponName() << "\n\n" << weapon->GetDesc() << "\n\nBase Weapon Damage: " << weapon->GetDamage() << "\n\nAbility 1: " << weapon->GetAbilities(0) << " | Ability 2: " << weapon->GetAbilities(1)
	<< " | Ability 3: " << weapon->GetAbilities(2) << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
	return out;
}

