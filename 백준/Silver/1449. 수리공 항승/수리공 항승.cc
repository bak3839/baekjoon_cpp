#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L, cnt = 0;

	cin >> N >> L;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N;) {
		++cnt;
		int len = v[i] + L - 1;
		while (i < N && v[i] <= len) ++i;
	}

	cout << cnt;
	return 0;
}