#ifndef FLAWLESS_MENU_HPP
#define FLAWLESS_MENU_HPP

#include <string>
#include <iostream>
#include <conio.h>
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

		std::string Selector;// = "-->";
		//Menu* Parent;
		std::vector<Menu *> Children;
		std::string Title;
		std::string Item;
		int Cursor;
		MenuType Type;


		void (*Function)(void);

		void Draw();
		Button GetButton();

		Menu(std::string title, MenuType type);
	public:
		Menu(std::string title);

		void Add(std::string, Menu* menu);
		void Add(std::string, void (*f)(void));

		int Start();
	};
}

#endif