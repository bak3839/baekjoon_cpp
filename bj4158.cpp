#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int N, M, num, index1 = 0, index2 = 0, cnt = 0;
		bool pass = false;

		cin >> N >> M;

		vector<int> v1(N);
		vector<int> v2(M);

		if (N == 0 && M == 0) break;

		for (int i = 0; i < N; i++) {
			cin >> num;
			v1[i] = num;
		}

		for (int i = 0; i < M; i++) {
			cin >> num;
			v2[i] = num;
		}

		while (index1 < N && index2 < M) {
			if (v1[index1] == v2[index2]) {
				++index1; ++index2;
				++cnt;
			}

			else if (v1[index1] > v2[index2]) ++index2;
			else ++index1;
		}

		if (index1 == N && index2 == M) {
			cout << cnt << "\n";
			continue;
		}

		if (index1 == N) {
			--index1;
			pass = false;
		}
		else if (index2 == M) {
			--index2;
			pass = true;
		}

		while (index1 < N && pass == true) {
			if (v1[index1] > v2[index2]) break;
			if (v1[index1++] == v2[index2]) ++cnt;
		}

		while (index2 < M && pass == false) {
			if (v1[index1] < v2[index2]) break;
			if (v1[index1] == v2[index2++]) ++cnt;
		}
		cout << cnt << "\n";
	}
	return 0;
}