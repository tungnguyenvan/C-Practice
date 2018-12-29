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

int main() {
	cout << "Wellcome to tic-tac-toe game!, play whith your way!" << endl;
	cout << "If you find any problem, please contact nguyentungtungtungnguyen@gmail.com" << endl << endl;
	
	cout << "SELECT YOUR MODE (1 - PLAYGAME, OTHER - EXIT GAME)" << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		drawMatrix();
	}

	system("pause");
	return 0;
}

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