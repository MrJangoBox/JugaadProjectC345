#include "Menu.h"

#include <iostream>
#include <vector>

using namespace std;

//Default Constructor for parent Menu
Menu::Menu()
{
	
}

void Menu::OptionDisplay()
{
	cout << "Method of Base Class for different menus, so should not be called";
}


int Menu::OptionSelection()
{
	cout << "Method of Base Class for different menus, so should not be called";
	return 0;
}

int Menu::getOptionChoice()
{
	return optionChoice;
}

//Default Constructor for child InitialMenu
InitialMenu::InitialMenu()
{
	OptionDisplay();
	optionChoice = OptionSelection();
}

void InitialMenu::OptionDisplay()
{
	cout << "\n\n****************** Risk Game Menu *******************" << endl;
	cout << "\nOption[1]: Start New Game \nOption[2]: Load Previous Game \nOption[3]: Exit Game \n\nChoose one Option: " << endl; 
}


int InitialMenu::OptionSelection()
{
	int optionChoosen = 0;

	cin >> optionChoosen;

	while(optionChoosen != 1 && optionChoosen != 2 && optionChoosen != 3)
	{
		cout << "\nInvalid option, please try again ";
		cin >> optionChoosen;
	}

	return optionChoosen;
}

//Default Constructor for child MainMenu
MainMenu::MainMenu()
{
	OptionDisplay();
	optionChoice = OptionSelection();
}

void MainMenu::OptionDisplay()
{
	cout << "\n\n****************** Risk Game Menu *******************" << endl;
	cout << "\nOption[1]: Save Game\nOption[2]: Exit Game \nOption[3]: Continue \n\nChoose one Option: " << endl; 
}


int MainMenu::OptionSelection()
{
	int optionChoosen = 0;

	cin >> optionChoosen;

	while(optionChoosen != 1 && optionChoosen != 2 && optionChoosen != 3)
	{
		cout << "\nInvalid option, please try again ";
		cin >> optionChoosen;
	}

	return optionChoosen;
}

//Default Constructor for child InnerMenu
InnerMenu::InnerMenu()
{
	OptionDisplay();
	optionChoice = OptionSelection();
}

void InnerMenu::OptionDisplay()
{
	cout << "\n\n****************** Risk Inner Menu *******************" << endl;
	cout << "\nOption[1]: Exit Game \nOption[2]: Continue \n\nChoose one Option: " << endl; 
}


int InnerMenu::OptionSelection()
{
	int optionChoosen = 0;

	cin >> optionChoosen;

	while(optionChoosen != 1 && optionChoosen != 2)
	{
		cout << "\nInvalid option, please try again ";
		cin >> optionChoosen;
	}

	return optionChoosen;
}