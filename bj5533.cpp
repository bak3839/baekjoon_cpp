#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num[200][4] = {0,};
	int N, score;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> score;
			num[i][j] = score;
		}
	}
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (num[j][i] == num[k][i]) {
					num[k][i] = 0;
					count++;
				}
			}
			if (count > 0) num[j][i] = 0;
			count = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			num[i][3] += num[i][j];
		}
		cout << num[i][3] << "\n";
	}
	return 0;
}