// TASK 2: 
#pragma once
#include <iostream>
using namespace std;

template <class T>
class Leaderboard
{
private:
	int MAX_PLAYERS = 100;
	string* playerNames;
	T* scores;
	int noOfPlayers = 0;

public:
	Leaderboard() {
		playerNames = new string[MAX_PLAYERS];
		scores = new T[MAX_PLAYERS];

	}

	void sortByScoreDecreasing() {
		for (int i = 0; i < noOfPlayers - 1; i++) {
			for (int j = 0; j < noOfPlayers - i - 1; j++) {
				if (scores[j] < scores[j + 1]) {

					T tempScore = scores[j];
					scores[j] = scores[j + 1];
					scores[j + 1] = tempScore;

					string tempName = playerNames[j];
					playerNames[j] = playerNames[j + 1];
					playerNames[j + 1] = tempName;
				}
			}
		}
	}


	void addPlayer(string name, T score) {
		playerNames[noOfPlayers] = name;
		scores[noOfPlayers++] = score;
		cout << "Player Added...!\n";
	}

	string getWinner() {
		if (noOfPlayers == 0)
			return "No players available";

		sortByScoreDecreasing();
		return playerNames[0];
	}

	void display() {
		cout << "\n\n===============================================\n";
		for (int i = 0; i < noOfPlayers; i++) {
			cout << "Player " << i + 1 << "-> Name: " << playerNames[i] << ", Scores: " << scores[i] << "\n";
		}
		cout << "===============================================\n\n";
	}

	~Leaderboard() {
		delete[] playerNames;
		delete[] scores;
	}

};

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