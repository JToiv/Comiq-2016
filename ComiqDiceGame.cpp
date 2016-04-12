// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

int main()
{
	cout << "Welcome!\n";
	cout << "Game begins!\n\n";

	int play = 1;
	int d1;
	int d2;
	int dsum;
	int guess = 0;
	string yn = "";

	string input = "";

	// Initialize random seed
	srand(time(NULL));

	while (play == 1)
	{
		input = "";

		while (true) {
			// Get the user's guess
			cout << "Guess the sum of two six-sided dice: ";
			getline(cin, input);

			// Check for valid input
			stringstream myStream(input);
			if (myStream >> guess)
				if (guess > 1 && guess < 13)
					break;
			cout << "Please enter a valid number. (2-12)" << endl << endl;
		}

		// Throw the dice
		d1 = rand() % 6 + 1;
		d2 = rand() % 6 + 1;
		dsum = d1 + d2;

		cout << "The sum of the dice is: " << dsum << endl;

		if (dsum == guess)
			cout << "You guessed right!" << endl << endl;
		else
			cout << "You guessed wrong!" << endl << endl;

		cout << "Play again? (y/n)" << endl;

		// Check whether to continue or end the game
		while (true)
		{
			getline(cin, yn);

			if (yn == "y") {
				play = 1;
				break;
			}
			else if (yn == "n") {
				play = 0;
				break;
			}
			else {
				cout << "Please enter a valid argument. (y/n)" << endl << endl;
			}
		}

		cout << endl;

	}

	cout << "Thank you for playing!" << endl << endl;
	//system("pause");

	return 0;

}

