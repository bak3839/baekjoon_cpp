#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> v;
	int N, M, num, left, right, mid;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		left = 0; right = N - 1;
		while (1) {
			mid = (left + right) / 2;

			if (left > right) {
				cout << "0\n";
				break;
			}

			if (num == v[mid]) {
				cout << "1\n";
				break;
			}

			else if (num < v[mid]) right = mid - 1;

			else left = mid + 1;
		}
	}

	return 0;
}