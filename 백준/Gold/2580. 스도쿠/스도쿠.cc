#include <iostream>
#include <vector>

using namespace std;

int cnt = 81;

int sudoku[10][10];

bool rows[10][10];
bool cols[10][10];
bool square[10][10];

int Sqrnum(int i, int j) {
    if (1 <= i && i <= 3) {
        if (1 <= j && j <= 3) return 1;
        else if (4 <= j && j <= 6) return 2;
        else return 3;
    }

    else if (4 <= i && i <= 6) {
        if (1 <= j && j <= 3) return 4;
        else if (4 <= j && j <= 6) return 5;
        else return 6;
    }

    else {
        if (1 <= j && j <= 3) return 7;
        else if (4 <= j && j <= 6) return 8;
        else return 9;
    }
}

void Visit(int x, int y, int n) {
    rows[x][n] = true;
    cols[y][n] = true;
    square[Sqrnum(x, y)][n] = true;
}

void Unvisit(int x, int y, int n) {
    rows[x][n] = false;
    cols[y][n] = false;
    square[Sqrnum(x, y)][n] = false;
}

void Search(int x, int y) {
    if (cnt == 0) return;

    if (y > 9) {
        y = 1; x++;
    }

    if (x > 9) return;

    if (sudoku[x][y] != 0) Search(x, y + 1);

    else {
        for (int i = 1; i <= 9; i++) {
            if (rows[x][i] || cols[y][i] || square[Sqrnum(x, y)][i]) continue;

            cnt--;
            sudoku[x][y] = i;
            Visit(x, y, i);

            Search(x, y + 1);
            if (cnt == 0) return;

            cnt++;
            sudoku[x][y] = 0;
            Unvisit(x, y, i);
        }
    }
}

void Solution() {
    Search(1, 1);

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++)
            cout << sudoku[i][j] << " ";
        cout << "\n";
    }
}

void Input() {
    int n;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> n;
            sudoku[i][j] = n;

            if (n != 0) {                
                cnt--;
                rows[i][n] = true;
                cols[j][n] = true;
                square[Sqrnum(i, j)][n] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}