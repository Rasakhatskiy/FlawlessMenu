#include "lib/FlawlessMenu.hpp"
#include <conio.h>

using namespace FlawlessMenu;


void F1()
{
	std::cout << "F1" << std::endl;
	char a = 0;
	do
	{
		a = 0;
		std::cout << "Enter number: ";
		int n; std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			std::cout << i << std::endl;
		}
		
		while (a != 'y' && a != 'Y' && a != 'n' && a != 'N')
		{
			std::cout << "One more time? (y/n) : ";
			std::cin >> a;
		}
		if (a == 'n' || a == 'N') break;
	} while (true);
}

void F2()
{
	std::cout << "F2" << std::endl;
	char a = 0;
	do
	{
		a = 0;
		std::cout << "Enter number: ";
		int n; std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			std::cout << (char)i << std::endl;
		}

		while (a != 'y' && a != 'Y' && a != 'n' && a != 'N')
		{
			std::cout << "One more time? (y/n) : ";
			std::cin >> a;
		}
		if (a == 'n' || a == 'N') break;
	} while (true);
}

void F3()
{
	std::cout << "F3" << std::endl;
	char a = 0;
	do
	{
		a = 0;
		std::cout << "Enter number: ";
		int n; std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			std::cout << 0 - i << std::endl;
		}

		while (a != 'y' && a != 'Y' && a != 'n' && a != 'N')
		{
			std::cout << "One more time? (y/n) : ";
			std::cin >> a;
		}
		if (a == 'n' || a == 'N') break;
	} while (true);
}

int main()
{
	//Setup static variables first
	Menu::Selector = "-->";
	Menu::Filler = "==========";
	Menu::GetKeyFunc = _getch;

	auto root = new Menu("Title main");
	root->Add("1", F1);
	root->Add("2", F2);
	root->Add("3", F3);

	auto newMenu = new Menu("Title child");
	newMenu->Add("3", F3);
	newMenu->Add("2", F2);
	newMenu->Add("1", F1);

	root->Add("4", newMenu);
	root->Start();
}