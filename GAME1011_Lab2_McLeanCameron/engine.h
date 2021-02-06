#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Character
{
private:
	string m_name;
	int m_health;
public:
	Character() {}

	virtual ~Character()
	{
		
	}
	Character(string name, int health)
	{
		SetHealth(health);
		SetName(name);
	}

	virtual void SetName(string name)
	{
		m_name = name;
	}

	void SetHealth(int health)
	{
		m_health = health;
	}

	string GetName() const
	{
		return m_name;
	}
	
	int GetHealth() const
	{
		return m_health;
	}
	
	virtual void DisplayInfo()
	{
		cout << "Name: " << GetName() << " | Health: " << GetHealth();
	}
};

class Weapon
{
private:
	string m_weaponName;
	string m_description;
	int m_damage;
	string m_abilities[3];
	
public:
	Character* character;
	Weapon() {}

	void SetWeaponName(string weapon)
	{
		m_weaponName = weapon;
	}

	void SetDesc(string description)
	{
		m_description = description;
	}

	void SetDamage(int damage)
	{
		m_damage = damage;
	}

	void SetAbilities(string ability1, string ability2, string ability3)
	{
		m_abilities[0] = ability1;
		m_abilities[1] = ability2;
		m_abilities[2] = ability3;
	}
	
	string GetWeaponName()
	{
		return m_weaponName;
	}

	string GetDesc()
	{
		return m_description;
	}

	int GetDamage() const
	{
		return m_damage;
	}

	string GetAbilities(int i)
	{
		return m_abilities[i];
	}

	
	friend ostream& operator<<(ostream& out, Weapon* weapon);
};


class Jedi : public Character
{
private:
	Weapon* m_weapon;
public:
	Jedi(string name, int health);
	
	void SetWeapon()
	{
		m_weapon = new Weapon;
		m_weapon->SetWeaponName("Blue Lightsaber");
		m_weapon->SetDesc("A blade of plasma powered by Kyber Crystals. Jedi's utilize this tool to learn focus\nand discipline, as well as defending the balance of the Universe.");
		m_weapon->SetDamage(90);
		m_weapon->SetAbilities("Force Push", "Mind Trick", "Force Bond");
	}

	void SetName(string name) override
	{
		name = "Jedi Master " + name;
		Character::SetName(name); 
	}
	
	Weapon* GetWeapon() const
	{
		return m_weapon;
	}

	void DisplayInfo() override
	{
		cout << GetName();
		cout << " | Health: " << GetHealth() << " | ";
		cout << m_weapon;
	}

};


class Sith : public Character
{
private:
	Weapon* m_weapon;
public:
	Sith(string name, int health);

	void SetWeapon()
	{
		m_weapon = new Weapon;
		m_weapon->SetWeaponName("Red Lightsaber");
		m_weapon->SetDesc("A blade of plasma powered by Kyber Crystals. A Sith utilizes the lightsaber to cause pain\nand destruction. A Sith lightsaber is red because the Kyber Crystal has been stolen, and are bleeding from being\nforced to bend to the Sith's will.");
		m_weapon->SetDamage(125);
		m_weapon->SetAbilities("Unrelenting Power", "Force Lightning", "Force Bleed");
	}

	void SetName(string name) override
	{
		name = "Darth " + name;
		Character::SetName(name);
	}

	Weapon* GetWeapon() const
	{
		return m_weapon;
	}

	void DisplayInfo() override
	{
		cout << GetName();
		cout << " | Health: " << GetHealth() << " | ";
		cout << m_weapon;
	}

};

class Mandalorian : public Character
{
private:
	Weapon* m_weapon;
public:
	Mandalorian(string name, int health);
	
	void SetWeapon()
	{
		m_weapon = new Weapon;
		m_weapon->SetWeaponName("Amban phase-pulse blaster");
		m_weapon->SetDesc("A disruptor sniper rifle, most iconically utilized by the bounty hunter Din Djarin.");
		m_weapon->SetDamage(150);
		m_weapon->SetAbilities("Grappling Line", "Paralysis Dart", "Repulsor Blast");
	}

	void SetName(string name) override
	{
		name = "Mand'alor " + name;
		Character::SetName(name);
	}

	Weapon* GetWeapon() const
	{
		return m_weapon;
	}

	void DisplayInfo() override
	{
		cout << GetName();
		cout << " | Health: " << GetHealth() << " | ";
		cout << m_weapon;
	}

};





#endif