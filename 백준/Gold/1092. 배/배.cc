#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, t = 0;

	cin >> N;
	vector<int> crain(N);
	for (int i = 0;i < N;i++) cin >> crain[i];
	sort(crain.begin(), crain.end());

	cin >> M;
	vector<int> box(M);
	for (int i = 0;i < M;i++) cin >> box[i];
	sort(box.begin(), box.end());

	int rest = M;

	if (box[M - 1] > crain[N - 1]) {
		cout << -1;
		return 0;
	}

	while (rest > 0) {
		int bin = rest - 1;
		int in = N - 1;

		while (in >= 0) {
			if (box[bin] <= crain[in]) {
				box.erase(box.begin() + bin);
				--bin; --rest; --in;
			}

			else --bin;

			if (bin < 0) break;
		}
		++t;
	}

	cout << t;

	return 0;
}