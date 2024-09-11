//Quinn Nash

#include "Functions.h"

#include "LifeCell.h"
#include "ConwayCell.h"
#include "FredKinCell.h"
#include "SeedsCell.h"
#include "ModifiedFredkinCell.h"
#include "SurpriseCell.h"

#include <iostream>
#include <Windows.h>
#include<cstdlib>

using namespace std;


LifeCell* pLife[5];

ConwayCell con;
FredKinCell fred;
ModifiedFredkinCell modFred;
SeedsCell seed;
SurpriseCell surprise;
//Nelson dog;

int main()
{
	//assign object address to the element of the array
	pLife[0] = &con;
	pLife[1] = &fred;
	pLife[2] = &modFred;
	pLife[3] = &seed;
	pLife[4] = &surprise;

	//get size of pLife
	int pLifeLength{ sizeof(pLife) / sizeof(pLife[0]) };

	//variables
	int lifeCount{ 0 };
	int config{ -1 };
	string pattern{ "" };

	//for checking repeat on play loop
	char answer{ 'y'};
	bool valid{ false }; 

	//For changing console color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD defaultAttributes;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

	//use to set back to default color and to get random color
	defaultAttributes = consoleInfo.wAttributes;
	int randColor{ 0 };

	HWND console = GetConsoleWindow();
	if (console != NULL) {
		ShowWindow(console, SW_MAXIMIZE);
	}

	// Providing a seed value
	srand((unsigned)time(NULL));

	WriteInstructions();

	//play loop
	do
	{
		//reset valid and lifeCount at start of each play loop
		valid = false;
		lifeCount = 0;		

		//get user selection
		config = UserChoosesAnImplementation() - 1;
		pattern = UserChoosesInitialpattern();

		Sleep(1000);
		system("cls");

		//set the chosen pattern into chosen cell
		pLife[config]->SetPattern(pattern);

		//show starting pattern
		Sleep(1000);
		system("cls");

		//run simulation
		do
		{
			randColor = rand() % 15 + 1;

			SetConsoleTextAttribute(hConsole, randColor);

			pLife[config]->UpdateBoard();
			cout << pLife[config]->PrintBoard();
			Sleep(300);
			system("cls");
			lifeCount++;
		} while (lifeCount < 40);

		//set back to default color
		SetConsoleTextAttribute(hConsole, defaultAttributes);
		
		//show final board
		cout << pLife[config]->PrintBoard() << endl << endl;
		cout << "Final Board Above" << endl;

		//char answer to go again
		
		do
		{
			cout << "\n\nWould like like to go again Play Again?\n\t(y to keep playing anything else will exit): ";
			cin >> answer;

			if (cin.fail()) { // Input failed
				cout << "Invalid input. Please enter a char, and enter 'y' to go again" << endl << endl;
				cin.clear(); // Clear error flags
				cin.ignore(); // Ignore invalid input
			}
			else
			{
				valid = true;
			}

		} while (!valid);

		//clear the arrays
		for (int i = 0; i < pLifeLength; i++)
		{
			pLife[i]->Clear();
		}

	} while (answer == 'y');

	WriteGoodbye();

	return 0;
}