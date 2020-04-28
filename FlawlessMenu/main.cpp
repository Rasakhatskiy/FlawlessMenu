//#include "INCLUDE/FlawlessMenu.hpp"
//
//using namespace FlawlessMenu;
//
//
//void F1()
//{
//	std::cout << "F1" << std::endl;
//	_getch();
//}
//
//void F3()
//{
//	std::cout << "F3" << std::endl;
//	_getch();
//}
//
//int main()
//{
//	auto root = new Menu("Title main");
//	root->Add("1", F1);
//	root->Add("2", F1);
//	root->Add("3", F1);
//
//	auto newMenu = new Menu("Title child");
//
//	root->Add("4", newMenu);
//
//	for (int i = 0; i < 10000; i++)
//	{
//		auto sraka = new Menu("Sraka");
//		newMenu->Add("Sraka v spiske", sraka);
//	}
//
//	root->Start();
//}