#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>

using namespace std;

class Menu 
{
protected:
	// Protected vars
	int optionChoice;

public:
	// Default Constructor
	Menu();

	// Public methods
	void OptionDisplay();
	int OptionSelection();
	int getOptionChoice();
};

class InitialMenu: public Menu 
{
protected:
	// Protected vars

public:
	// Default Constructor
	InitialMenu();

	// Public methods
	virtual void OptionDisplay();
	virtual int OptionSelection();
};

class MainMenu: public Menu 
{
protected:
	// Protected vars


public:
	// Default Constructor
	MainMenu();

	// Public methods
	virtual void OptionDisplay();
	virtual int OptionSelection();
};

class InnerMenu: public Menu 
{
protected:
	// Protected vars

public:
	// Default Constructor
	InnerMenu();

	// Public methods
	virtual void OptionDisplay();
	virtual int OptionSelection();
};
#endif