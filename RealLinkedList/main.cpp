#include<iostream>
#include "linkedList.cpp"


int main()
{
	LinkedList<int> list;
	list.push_back(535);
	list.push_back(43);
	list.push_back(34);

	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << list[i] << "\n";
	}
	std::cout << "\n";


	list.push_front(6686);

	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << list[i] << "\n";
	}
	std::cout << "\n";

	list.insert(5675676575756, 2);

	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << list[i] << "\n";
	}
	std::cout << "\n";

	list.removeAt(3);

	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << list[i] << "\n";
	}
	std::cout << "\n";

	return 0;
}