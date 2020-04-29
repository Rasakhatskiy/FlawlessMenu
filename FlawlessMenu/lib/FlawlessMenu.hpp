#ifndef FLAWLESS_MENU_HPP
#define FLAWLESS_MENU_HPP

#include <string>
#include <iostream>
#include <vector>


namespace FlawlessMenu
{
	class Menu
	{
		enum class Button
		{
			Undefined, Up, Down, Select
		};

		enum class MenuType
		{
			Back, Home, Exit, Function, Submenu
		};

		//Submenu list
		std::vector<Menu *> Children;

		//Title on the top of menu
		std::string Title;

		//Name of that menu in list
		std::string Item;

		//Selector position in current menu
		int Cursor;

		//Functionality of menu
		MenuType Type;

		//Function for execute when selected
		void (*Function)(void);

		//Clears screen and draws menu
		void Draw();

		//Gets next action on menu
		Button GetButton();

		//Private constructor
		Menu(std::string title, MenuType type);
	public:
		//	item1
		//	-->item2
		//	item3
		static std::string Selector;

		//	=======Title=====
		static std::string Filler;

		//Function for waiting for input the key 
		static int(*GetKeyFunc)(void);

		Menu(std::string title);

		//Add submenu
		void Add(std::string, Menu* menu);

		//Add menu item
		void Add(std::string, void (*f)(void));

		//Start menu
		int Start();
	};
}

#endif