#include <iostream>
#include <string>

using namespace std;

int N;
string board[100];
bool chk = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int r = 0; r < N; r++) cin >> board[r];

	for (int r = 0; r < N; r++) {
		for (int c = r + 1; c < N; c++) {
			if (board[r][c] != board[c][r]) chk = 0;
		}
	}

	if (chk) cout << "YES";
	else cout << "NO";
}