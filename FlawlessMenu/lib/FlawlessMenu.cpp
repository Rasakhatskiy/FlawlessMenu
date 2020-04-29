#include "FlawlessMenu.hpp"

namespace FlawlessMenu
{

	std::string Menu::Selector = "";
	std::string Menu::Filler = "";
	int(*Menu::GetKeyFunc)(void) = nullptr;

	Menu::Menu(std::string title)
	{
		Title = title;
		Cursor = 0;
		Type = Menu::MenuType::Submenu;
		Children.push_back(new Menu("Exit", MenuType::Exit));
	}

	Menu::Menu(std::string title, MenuType type)
	{
		Cursor = 0;
		Function = nullptr;
		Title = title;
		Item = title;
		Type = type;
	}


	void Menu::Draw()
	{
		system("CLS");

		std::cout << Filler + Title + Filler << std::endl;
		for (unsigned i = 0; i < Children.size(); ++i)
		{
			if (Cursor == i)	std::cout << Selector;
			else				std::cout << " ";

			std::cout << Children[i]->Item << std::endl;
		}
	}

	Menu::Button Menu::GetButton()
	{
		auto key = GetKeyFunc();
		if (key == 0x00 || key == 0xE0) key = GetKeyFunc();

		switch (key)
		{
			case 119: case 72:		return Button::Up;
				//case 97: case 75:
			case 115: case 80:		return Button::Down;
				//case 100: case 77:
				//case 113: case 81:	return Button::Quit;
			case 13:				return Button::Select;
				//case 8:				return Button::Return;
			default:				return Button::Undefined;
		}
	}


	void Menu::Add(std::string item, Menu * menu)
	{
		menu->Item = item;
		menu->Children[menu->Children.size() - 1]->Item = "Back";
		menu->Children[menu->Children.size() - 1]->Type = MenuType::Back;
		Children.insert(Children.end() - 1, menu);
	}

	void Menu::Add(std::string item, void(*f)(void))
	{
		Menu* menu = new Menu("", MenuType::Function);
		menu->Item = item;
		menu->Function = f;
		Children.insert(Children.end() - 1, menu);
	}


	int Menu::Start()
	{
		switch (Type)
		{
			case MenuType::Back:
				return 1;
			case MenuType::Home:
				return 2;
			case MenuType::Exit:
				return 1;
			case MenuType::Function:
				Function();
				return 0;
			case MenuType::Submenu:
				break;
			default:
				break;
		}
		int result;
		while (true)
		{
			Draw();
			auto button = GetButton();

			switch (button)
			{
				case Button::Undefined:
					continue;

				case Button::Up:
					if (Cursor > 0)
						Cursor--;
					continue;

				case Button::Down:
					if (Cursor < Children.size() - 1)
						Cursor++;
					continue;

				case Button::Select:
					system("CLS");
					result = Children[Cursor]->Start();
					if (result == 1) return 0;
					if (result == 2) return 2;
					else continue;

				default:
					continue;;
			}
		}
	}

}

