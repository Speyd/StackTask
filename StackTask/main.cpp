#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

#pragma region Special_Abilities

void ClearScrean() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tStack" << endl;
}

void Enter() {
	string enter;
	cin.ignore();
	do {
		cout << "Press enter to continue: "; getline(cin, enter);
	} while (!enter.empty());
}

Types DefinitionType(const int index)
{
	if (index == 0)return Static;
	else if (index == 1)return Dynamic;
	else return Dynamic;
}
#pragma endregion

template <typename T>
void AddSymbol(Stack<T>& symbols)
{
	char symbol;
	int choice{ 0 };

	do {

		ClearScrean();
		cout << "[1] - Add one symbo\n[2] - Add 'n' symbols\n[0] - Exit" << endl;

		if (choice >= 0 || choice <= 2)cout << "Enter your choice: ";
		else cout << "There is no such choice!\nEnter your choice again: ";
		cin >> choice;

	} while (choice < 0 || choice > 2);

	ClearScrean();

	if (choice != 0) 
	{
		int amountSymbol{ 1 };
		if(choice == 2)
		{
			cout << "Enter the number of symbols to add: "; cin >> amountSymbol;
		}

		for(size_t i{1}; i <= amountSymbol; i++)
		{
			ClearScrean();
			cout << "Enter " << i << "-th symbol: "; cin >> symbol;
			symbols.push(symbol);
		}
	}

}

template <typename T>
void DeleteSymbol(Stack<T>& symbols)
{
	int choice{ 0 };

	do {

		ClearScrean();
		cout << "[1] - Delete one symbo\n[2] - Delete 'n' symbols\n[0] - Exit" << endl;

		if (choice >= 0 || choice <= 2)cout << "Enter your choice: ";
		else cout << "There is no such choice!\nEnter your choice again: ";
		cin >> choice;

	} while (choice < 0 || choice > 2);

	ClearScrean();

	if (choice != 0)
	{
		int amountSymbol{ 1 };
		if (choice == 2)
		{
			cout << "Enter the number of symbols to delete: "; cin >> amountSymbol;
		}

		for (size_t i{ 1 }; i <= amountSymbol; i++) symbols.pop();
	}

}

int main()
{
	int tempSize{ 0 }, choice{ 0 }, typeStack{ 0 };

	do {

		ClearScrean();
		cout << "Type stack?\n[1] - Static\n[2] - Dynamic" << endl;

		if (choice >= 0 || choice <= 7)cout << "Enter your choice: ";
		else cout << "There is no such choice!\nEnter your choice again: ";
		cin >> typeStack;

	} while (choice < 0 || choice > 7);
	typeStack--;


	if (typeStack == Static)
	{
		ClearScrean();
		cout << "Enter const size for stack: "; cin >> tempSize;
	}
	Stack<char> symbols{ tempSize, DefinitionType(typeStack)};

	do {

		do {

			ClearScrean();
			cout << "[1] - Add symbol(-s)\n[2] - Delete symbol\n[3] - Amount symbol\n"
				 << "[4] - Checking the stack for empty\n[5] - Checking the stack for filling\n"
				 << "[6] - Clear stack\n[7] - Getting the last symbol\n[0] - Exit" << endl;

			if (choice >= 0 || choice <= 7)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";
			cin >> choice;

		} while (choice < 0 || choice > 7);

		ClearScrean();

		switch(choice)
		{
		case 1:AddSymbol(symbols); break;

		case 2:DeleteSymbol(symbols); break;

		case 3: cout << "Amount symbol: " << symbols.size() << endl; break;

		case 4:cout << "Stack empty(0 - no | 1 - yes)?: " << symbols.empty() << endl; break;

		case 5:cout << "Stack filling(0 - no | 1 - yes)?: " << symbols.fill() << endl; break;

		case 6:symbols.clear(); break;

		case 7:cout << "Last stack symbol: " << symbols.top() << endl; break;
		}

		if (choice != 0)Enter();

	} while (choice != 0);


	return 0;
}