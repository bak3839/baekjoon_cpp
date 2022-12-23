#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, B, K, n, res = 1000001;
	cin >> N >> K >> B;

	vector<int> v;

	for (int i = 0; i < B; i++) {
		cin >> n;
		v.push_back(n);
	}

	int l = 1, r = K;

	while (r <= N) {
		int cnt = 0;
		for (int i = 0; i < B; i++) {
			if (l <= v[i] && v[i] <= r) cnt++;
		}
		res = min(res, cnt);
		l++; r++;
	}

	cout << res;
	return 0;
}