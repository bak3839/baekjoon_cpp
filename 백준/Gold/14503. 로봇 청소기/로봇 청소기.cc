#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, num, r, c, d, cnt = 0, clear = 0;
	cin >> N >> M;
	cin >> r >> c >> d;

	vector<vector<int>> f(N);
	vector<int> v(M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			v[j] = num;
		}
		f[i] = v;
	}

	while (1) {
		if (f[r][c] == 0) {
			f[r][c] = 7;
			++clear;
		}

		if (cnt == 4) {
			cnt = 0;
			if (d == 0) {
				if (f[r + 1][c] == 1) break;
				r += 1;
			}

			else if (d == 1) {
				if (f[r][c - 1] == 1) break;
				c -= 1;
			}

			else if (d == 2) {
				if (f[r - 1][c] == 1) break;
				r -= 1;
			}

			else if (d == 3) {
				if (f[r][c + 1] == 1) break;
				c += 1;
			}
		}
		switch (d) {
		case 0:
			if (f[r][c - 1] == 0) {
				c -= 1;
				cnt = 0;
			}
			else ++cnt;
			d = 3;
			break;

		case 1:
			if (f[r - 1][c] == 0) {
				r -= 1;
				cnt = 0;
			}
			else ++cnt;
			d = 0;
			break;

		case 2:
			if (f[r][c + 1] == 0) {
				c += 1;
				cnt = 0;
			}
			else ++cnt;
			d = 1;
			break;

		case 3:
			if (f[r + 1][c] == 0) {
				r += 1;
				cnt = 0;
			}
			else ++cnt;
			d = 2;
			break;
		}
	}

	cout << clear;
	return 0;
}