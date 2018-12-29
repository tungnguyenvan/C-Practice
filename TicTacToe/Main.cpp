#include <iostream>

using namespace std;

const int MAX_ROW_COLUMN = 3;
char matrix[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char player = 'x';
int ticked = 0;
int playerWin = 0;
char nameA[10] = "";
char nameB[10] = "";

void drawMatrix();
void addName();
void runGame();
void input();
void togglePlayer();
bool restartGame(bool isWin);
void setToMatrix(int x, int y, char value);
void inputFails();

int main() {
	cout << "Wellcome to tic-tac-toe game!, play whith your way!" << endl;
	cout << "If you find any problem, please contact nguyentungtungtungnguyen@gmail.com" << endl << endl;
	
	cout << "SELECT YOUR MODE (1 - PLAYGAME, OTHER - EXIT GAME)" << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		addName();
		runGame();
	}

	system("pause");
	return 0;
}


/**
* Draw game play to console screen
*/
void drawMatrix() {
	cout << "\t*** TIC TAC TOE ***" << endl << "\tx: " << nameA << " --- o: "
		<< nameB << endl << endl << "\t    1   2   3" << endl << "\t  _____________" << endl;
	int temp = 1;
	for (int i = 0; i < MAX_ROW_COLUMN; i++) {
		cout << "\t" << i + 1 << " ";
		for (int j = 0; j < MAX_ROW_COLUMN; j++) {
				cout << "| " << matrix[i][j] << " ";
			if (temp == 3)
			{
				temp = 0;
				cout << "|";
				cout << "\n\t  -------------\n";
			}

			temp++;
		}
	}
}

/**
* Add name for 2 player
*/
void addName() {
	cout << "Enter Player 1 name: ";
	cin >> nameA;
	cout << "\nEnter Player 2 name: ";
	cin >> nameB;

	cout << "Do you start? : ";
	system("pause");
}

/**
* Run for game
*/
void runGame() {
	system("cls");
	drawMatrix();
	//cho người dùng tích nhiều lần
	while (ticked < 9)
	{
		input();
		if (playerWin > 0) {
			if (restartGame(true)) continue;
			else  break;
		}
	}
	if (ticked >= 9 && playerWin == 0) {
		if (restartGame(false)) {
			runGame();
			return;
		}
	}
}

/**
* Input number -> player ticked
*/
void input() {
	int select;
	cout << endl << endl;
	(player == 'x') ? cout << nameA : cout << nameB;
	cout << "\t" << player << ": type your number (row/column): ";
	cin >> select;

	int selectRow = select / 10 - 1;
	int selectColumn = select % 10 - 1;

	if (matrix[selectRow][selectColumn] != 'x' && matrix[selectRow][selectColumn] != 'o')
		setToMatrix(selectRow, selectColumn, player);
	else inputFails();

	cout << endl;
	system("cls");
	drawMatrix();
}

/**
* switch player "x" to "o" And "o" to "x"
*/
void togglePlayer() {
	(player == 'x') ? player = 'o' : player = 'x';
}

/**
* set data "x" or "o" to matrix
*/
void setToMatrix(int x, int y, char value) {
	matrix[x][y] = value;
	ticked++;
}

/**
* cout error if player choose data Exist
*/
void inputFails() {
	system("cls");
	drawMatrix();
	cout << "Your select is EXIT, Please select other place!" << endl;
	input();
}


/**
* request player restart game
*/
bool restartGame(bool isWin) {
	char restart;
	if (isWin) {
		(playerWin == 1) ? cout << nameA : cout << nameB;
		cout << "\t----> WIN ..." << endl << endl;
	}
	else cout << "not defeated" << endl << endl;
	cout << "Do you want restart? (y/n)";
	cin >> restart;

	if (restart == 'y')
	{
		system("cls");
		int index = 1;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				matrix[i][j] = ' ';
			}
		}
		ticked = 0;
		playerWin = 0;
		drawMatrix();
		return true;
	}
	else {
		cout << "Thanks for use!" << endl;
		return false;
	}
}