#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);
	pair<int, int> res = { 2000000001, 0 };

	for (int i = 0; i < N; i++) cin >> v[i];
	int l = 0, r = v.size() - 1;

	while (l < r) {
		int sum = v[l] + v[r];
		if (sum == 0) {
			res = { v[l],v[r] };
			break;
		}

		else if (sum > 0) {
			if (abs(res.first + res.second) > abs(sum)) res = { v[l],v[r] };
			--r;
		}

		else if (sum < 0) {
			if (abs(res.first + res.second) > abs(sum)) res = { v[l],v[r] };
			++l;
		}
	}

	cout << res.first << " " << res.second;

	return 0;
}