/*! Interactive console menu.
* \file FlawlessMenu.hpp
* \author Maksym Rasakhatskyi
* \version 1.0 29/04/20
*/

#ifndef FLAWLESS_MENU_HPP
#define FLAWLESS_MENU_HPP

#include <string>
#include <iostream>
#include <vector>

/*! Flawless menu namespace*/
namespace FlawlessMenu
{
	class Menu
	{
		/*! Keyboard button actions*/
		enum class Button
		{
			/*! No action.*/
			Undefined, 
			
			/*! Move up.*/
			Up, 
			
			/*! Move down.*/
			Down, 
			
			/*! Select menu item.*/
			Select
		};

		/*! Menu item purpose.*/
		enum class MenuType
		{
			/*! Go up to parent menu.*/
			Back, 
			
			/*! Return to main menu.*/
			Home, 
			
			/*! Exit the program.*/
			Exit,
			
			/*! Execute assigned function.*/
			Function, 
			
			/*! Go down to submenu.*/
			Submenu
		};

		/*! Submenu list.*/
		std::vector<Menu *> Children;

		/*! Title on the top of menu.*/
		std::string Title;

		/*! Displayed name of that menu in list.*/
		std::string Item;

		/*! Selector position in current menu.*/
		int Cursor;

		/*! Functionality of menu.*/
		MenuType Type;

		/*! Function for execute when selected*/
		void (*Function)(void);

		/*! Clears screen and draws menu.*/
		void Draw();

		/*! Gets next action on menu.*/
		Button GetButton();

		/*! Private constructor. Sets title and type.
		* \param title Title and name in displayed menu.
		* \param type Functionality of menu.
		*/ 
		Menu(std::string title, MenuType type);
	public:
		
		/*! Selector. Displayed before menu item. ">item 1"*/
		static std::string Selector;

		/*! Filler. Fills title with sybols. "=======Title=====" */
		static std::string Filler;

		/*! Function for waiting for input the key. I typically use _getch().
		* \returns Key from keyboard.
		*/
		static int(*GetKeyFunc)(void);

		/*! Constructor. Creates empty menu with title and exit.*/
		Menu(std::string title);

		/*! Add submenu to current menu.
		* \param item Displayed name.
		* \param menu Flawless menu as submenu.
		*/
		void Add(std::string item, Menu* menu);

		/*! Add submenu to current menu.
		* \param item Displayed name.
		* \param f Function to execute.
		*/
		void Add(std::string item, void (*f)(void));

		/*! Starts current menu.
		* \returns Code of menu functionality.
		*/
		int Start();
	};
}

#endif