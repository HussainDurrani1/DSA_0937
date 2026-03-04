// TASK 3: 
#pragma once
#include <iostream>
#include "Leaderboard.h"
using namespace std;

int main() {
	Leaderboard<int> gameBoard;

	gameBoard.addPlayer("Ali", 1500);
	gameBoard.addPlayer("Bobby", 2300);
	gameBoard.addPlayer("Talha", 1900);

	gameBoard.display();
	cout << "Winner: " << gameBoard.getWinner() << endl;
	cout << endl;

	Leaderboard<double> gpaBoard;

	gpaBoard.addPlayer("Hussain", 3.5);
	gpaBoard.addPlayer("Esha", 3.9);
	gpaBoard.addPlayer("Fahad", 3.7);

	gpaBoard.display();
	cout << "Top Performer (Highest GPA): " << gpaBoard.getWinner() << endl;

	return 0;
}