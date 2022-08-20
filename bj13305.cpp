#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> oil;
	vector<int> road;

	int N, l, m, k = 0, count;
	long long sum = 0;

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> m;
		road.push_back(m);
	}

	for (int i = 0; i < N; i++) {
		cin >> l;
		oil.push_back(l);
	}

	
	while (k < N - 1) {
		if (k == N - 1) sum += road[k] * oil[k];

		if (oil[k] > oil[k + 1]) {
			sum += oil[k] * road[k];
			k++;
		}

		else {
			int min = oil[k];
			while (1) {
				sum += road[k] * min;
				k++;
				if (k >= N - 1 || oil[k] < min) break;
			}
		}
	}

	cout << sum;
	return 0;
}