#include "engine.h"
#include <iostream>
using namespace std;
int MenuSelection;
int tempHealth;
int tempSelect;
string tempName;
Character* Characters[15] = { nullptr };
bool running = true;
int charNumb;

int main()
{	
	while (running)
	{
		// Main Menu / Menu Selection
		while (MenuSelection == 0)
		{
			cout << "Welcome to the STAR WARS CHARACTER CREATION Menu!\n\nPlease select from one of the following Options:\n\n1. Create new Character\n\n";
			cout << "2. View all created Characters\n\n3. Delete a Character\n\n4.Exit Program\n\nSelection: ";
			cin >> MenuSelection;
			if (MenuSelection < 1 || MenuSelection > 4)
			{
				system("cls");
				cout << "Improper Selection! Please try again.\n\n";
				MenuSelection = 0;
			}
			system("cls");
		}
		// Character Creation
		while (MenuSelection == 1)
		{
			cout << "Character Creation\n\nPlease Enter Name: ";
			cin.ignore();
			getline(cin, tempName);
			cout << "\n\nPlease Enter Health: ";
			cin >> tempHealth;
			system("cls");
			cout << "Name: " << tempName << " | Health: " << tempHealth;
			cout << "\n\nPlease choose your Alliegence from the following Selection\n\n1. Jedi\n\n2. Sith\n\n3. Mandalorian\n\nSelection: ";
			cin >> tempSelect;
			// Create Character based on Alliegence chosen
			switch (tempSelect)
			{
			case 1:
			{
				for (int i = 0; i < 15; i++)
				{
					Character* pCharacter = Characters[i];
					if (pCharacter == nullptr)
					{
						Characters[i] = new Jedi(tempName, tempHealth);
						MenuSelection = 0;
						system("cls");
						break;
					}
				}
				break;
			}
			case 2:
			{
				for (int i = 0; i < 15; i++)
				{
					Character* pCharacter = Characters[i];
					if (pCharacter == nullptr)
					{
						Characters[i] = new Sith(tempName, tempHealth);
						MenuSelection = 0;
						system("cls");
						break;
					}
				}
				break;
			}
			case 3:
			{
				for (int i = 0; i < 15; i++)
				{
					Character* pCharacter = Characters[i];
					if (pCharacter == nullptr)
					{
						Characters[i] = new Mandalorian(tempName, tempHealth);
						MenuSelection = 0;
						system("cls");
						break;
					}
				}
				break;
			}
			default:
			{
				system("cls");
				cout << "Invalid choice of Alliegence! Please Try again.\n\n";
			}
			}
		}
		// View Character
		while(MenuSelection==2)
		{
			charNumb = 0;
			for (int i = 0; i < 15; i++)
			{
				Character* pCharacter = Characters[i];
				if (pCharacter == nullptr)
				{
					continue;
				}
				charNumb++;
				cout << charNumb << ". ";
				pCharacter->DisplayInfo();
			}
			MenuSelection = 0;
			if(charNumb == 0)
			{
				cout << "You haven't made any characters yet!";
			}
			cout << "\n\nPressing any key will bring you back to the main menu.\n\n";
			system("pause");
			system("cls");
		}
		// Delete Character
		while(MenuSelection==3)
		{
			cout << "Delete a Character\n\n";
			for (int i = 0; i < 15; i++)
			{
				Character* pCharacter = Characters[i];
				if (pCharacter == nullptr)
				{
					cout << "Save Slot " << i + 1 << ". EMPTY SAVE SLOT\n";
					continue;
				}
				cout << "Save Slot " << i + 1 << ". ";
				cout << pCharacter->GetName() << "\n";
			}
			cout << "Please enter which character you would like to delete (by save slot number)\nOr enter 0 to return to the main menu: ";
			cin >> tempSelect;
			if(tempSelect==0)
			{
				MenuSelection = 0;
				system("cls");
			}
			if(tempSelect >= 1 && tempSelect <= 15)
			{
				if(Characters[tempSelect-1] == nullptr)
				{
					system("cls");
					cout << "Invalid option: No character exists at said location.\n\n";
				}
				else
				{
					delete Characters[tempSelect-1];
					Characters[tempSelect-1] = nullptr;
					
					system("cls");
				}
			}
		}
		if(MenuSelection==4)
		{
			cout << "Thank you for Playing! May the force be with you!\n";
			running = false;
		}		
	}//end of running
	//Cleaning
	for (int i = 0; i < 15; i++)
	{
		Character* pCharacter = Characters[i];
		if (pCharacter == nullptr)
		{
			continue;
		}
		cout << "deleting character...\n";
		delete pCharacter;
	}
}

