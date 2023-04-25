#include <iostream>
#include <string>

using namespace std;

const int SIZE = 8;

void GetPosition(string& pos, int& row, int& col)
{
	row = pos[1] - '0';
	col = pos[0] - 'A' + 1;
}

void GetDirection(char& command, int& dirRow, int& dirCol)
{
	switch (command)
	{
	case 'R':
		dirCol++;
		break;
	case 'L':
		dirCol--;
		break;
	case 'B':
		dirRow--;
		break;
	case 'T':
		dirRow++;
		break;
	default:
		break;
	}
}

bool IsValidPosition(int row, int col)
{
	return 0 < row && row <= SIZE &&
		0 < col && col <= SIZE;
}

void SetPosition(string& pos, int row, int col)
{
	pos[0] = 'A' + (col - 1);
	pos[1] = row + '0';
}

int main()
{
	string kingPosition, stonePosition, move;
	int moveCount, kingRow, kingCol, stoneRow, stoneCol;

	cin >> kingPosition >> stonePosition >> moveCount;

	GetPosition(kingPosition, kingRow, kingCol);
	GetPosition(stonePosition, stoneRow, stoneCol);
	
	for (int i = 0; i < moveCount; ++i)
	{
		int dirRow = 0, dirCol = 0;

		cin >> move;

		for (int j = 0; j < move.length(); ++j)
		{
			GetDirection(move[j], dirRow, dirCol);
		}

		if (IsValidPosition(kingRow + dirRow, kingCol + dirCol))
		{
			string preKingPosition = kingPosition;
			int preKingRow = kingRow;
			int preKingCol = kingCol;

			kingRow += dirRow;
			kingCol += dirCol;

			SetPosition(kingPosition, kingRow, kingCol);

			if (kingPosition == stonePosition)
			{
				if (IsValidPosition(stoneRow + dirRow, stoneCol + dirCol))
				{
					stoneRow += dirRow;
					stoneCol += dirCol;

					SetPosition(stonePosition, stoneRow, stoneCol);
				}
				else
				{
					kingPosition = preKingPosition;
					kingRow = preKingRow;
					kingCol = preKingCol;
				}
			}
		}
	}

	cout << kingPosition << " " << stonePosition << endl;
}