#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, l, r, res, res_l, res_r;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	l = 0; r = N - 1;
	res = 2000000001;

	while (l < r) {
		int sum = v[l] + v[r];
		res = min(res, abs(sum));

		if (abs(sum) == res) {
			res_l = v[l];
			res_r = v[r];
		}

		if (sum == 0) break;
		else if (sum < 0) ++l;
		else --r;
	}

	cout << res_l << " " << res_r;
	return 0;
}