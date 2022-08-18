#include <iostream>;
#include <cstdlib>;

using namespace std;

void menu( int &round, int &userScore, int &NPC_score, bool continueGame);
void game(int& userScore, int& NPCscore, int& round, int&playerGuess, int& NPCguess, int& solution);
void updateScore(int playerGuess, int NPCguess, int& userScore, int& NPC_score, int solution);

int main() {
	int userScore = 0;
	int NPCscore = 0;
	int round = 1;
	bool continueGame = true;

	menu(round, userScore, NPCscore, continueGame);
	return 0;
}

void menu(int &round, int &userScore, int &NPCscore, bool continueGame) {

	do
	{
		cout << "\nWould you like to exit the game?\n";
		cout << "\n\t1. Exit Game\n";
		cout << "\n\t2. Play Game\n";
		cout << "\nSelection: ";

		int menuSelection = 0;
		cin >> menuSelection;

		switch (menuSelection) {
		case 1:
			continueGame = false;
			break;
		case 2:
			int initialRound = round;
			bool playAgain = true;

			do
			{
				int playerGuess = 0;
				int NPCguess = rand() % 5 + 1;
				int solution = rand() % 5 + 1;
				game(userScore, NPCscore, round, playerGuess, NPCguess, solution);
				playAgain = round - initialRound < 3;
			} while (playAgain);

			break;
		}

		cout << "\nFINAL SCORE:\n";
		cout << "\n\tPlayer1 - " << userScore << '\n';
		cout << "\n\tNPC - " << NPCscore << '\n';

		if (userScore > NPCscore) {
			cout << "\n\tYOU WIN!!!\n\n";
		}
		else if (NPCscore > userScore) {
			cout << "\n\tYOU LOSE!!!\n\n";
		}
		else if (userScore == NPCscore) {
			cout << "\n\tTIE!!!\n\n";
		}

		round = 1;
		userScore = 0;
		NPCscore = 0;

	} while (continueGame);

}

void game(int &userScore, int &NPCscore, int &round, int &playerGuess, int &NPCguess, int &solution) {
	cout << "\n\nROUND: " << round;

	cout << "\n\n\tGuess a number from 1 to 5: ";

	cin >> playerGuess;
	cout << "\n\t\tYou guessed: " << playerGuess;

	cout << "\n\t\tNPC guessed: " << NPCguess;
	cout << "\n\t\tThe correct answer is: " << solution;

	updateScore(playerGuess, NPCguess, userScore, NPCscore, solution);

	cout << "\n\n\tScore:\n";
	cout << "\n\t\tPlayer1 - " << userScore << '\n';
	cout << "\n\t\tNPC - " << NPCscore << '\n';

	round++;
}

void updateScore(int playerGuess, int NPCguess, int &userScore, int &NPCscore, int solution) {
	if (playerGuess == solution) {
		userScore++;
	}

	if (NPCguess == solution) {
		NPCscore++;
	}
}