//Quinn Nash

#include "Functions.h"
#include <iostream>

void WriteInstructions()
{
	cout << "Welcome to The Game of Life:" << endl;
	cout << "\tIn this game you will watch the life cycle of a cell" << endl;
	cout << "\tThe cell will repopulate and depopulate according to a predetermined set of rules" << endl << endl;
	cout << "Here's how to play:" << endl;
	cout << "\tSelect a number, 1-5, from a menu of options to determine the life cycle of your cell" << endl;
	cout << "\tNext, again select a number, 1-5, from a menu of options to determine the starting pattern of your cell" << endl << endl;
	cout << "\t\tThen get ready for show time!" << endl << endl;

}

int UserChoosesAnImplementation()
{
	int choice{ 0 };
	bool validInput{ false };

	do
	{
		//have user select a cell type
		cout << "Cell Types:" << endl;
		cout << "\t1: Conway Cell" << endl;
		cout << "\t2: Fredkin  Cell" << endl;
		cout << "\t3: Modified Fredkin  Cell" << endl;
		cout << "\t4: Seeds Conway Cell" << endl;
		cout << "\t5: Surprise Cell" << endl;
		cout << "Select a cell type (1-5)" << endl;

		cin >> choice;

		if (cin.fail()) { // Input failed
			cout << "Invalid input. Please enter an integer." << endl << endl;
			cin.clear(); // Clear error flags
			cin.ignore(); // Ignore invalid input
		}
		else {
			if (choice > 5 || choice < 1)
			{
				cout << "Must select 1, 2, 3, 4, or 5" << endl << endl;
			}
			else
			{
				validInput = true; // Input is valid, break the loop
			}
		}
	} while (!validInput);
	
	//helps ignore decimals like 1.5
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return choice;
}

string UserChoosesInitialpattern()
{
	int choice{ 0 };
	bool validInput{ false };
	string fileName{ "" };

	do
	{
		//give user choice of however many patterns and number them
		cout << "\n Pattern Types" << endl;
		cout << "\t 1: Eyes" << endl;
		cout << "\t 2: Plane" << endl;
		cout << "\t 3: Spiral" << endl;
		cout << "\t 4: Stick Figure" << endl;
		cout << "\t 5: Target" << endl;

		cin >> choice;

		if (cin.fail()) { // Input failed
			cout << "Invalid input. Please enter an integer." << endl << endl;
			cin.clear(); // Clear error flags
			cin.ignore(); // Ignore invalid input
		}
		else {
			if (choice > 5 || choice < 1)
			{
				cout << "Must select 1, 2, 3, 4, or 5" << endl << endl;
			}
			else
			{
				validInput = true; // Input is valid, break the loop
			}
		}
	} while (!validInput);

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//set file name of choice
	switch (choice)
	{
		case 1:
			fileName = "eyes.txt";
			break;
		case 2:
			fileName = "plane.txt";
			break;
		case 3:
			fileName = "spiral.txt";
			break;
		case 4:
			fileName = "stickfigure.txt";
			break;
		case 5:
			fileName = "target.txt";
			break;
	}

	return fileName;
}

void WriteGoodbye()
{
	cout << endl << endl << "Thank you for playing..." << endl;
	cout << endl << "\t\tThe Game of Life" << endl << endl;
}

