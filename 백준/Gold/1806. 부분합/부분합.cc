#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, S, sum = 0, res = 100001, l = -1, r = 0;
	cin >> N >> S;
	vector<int> v(N);

	for (int i = 0;i < N;i++) cin >> v[i];	
	sum = v[r];

	while (l < r) {
		if ((r >= N && sum < S) || res == 1) break;

		if (sum < S) {
			++r;
			if(r < N) sum += v[r];
		}

		else if (sum > S) {
			res = min(r - l, res);
			sum -= v[++l];
		}

		else if(sum == S) {
			res = min(r - l, res);
			++l; ++r;
			if (r < N) sum = sum - v[l] + v[r];
			else sum -= v[l];
		}
	}

	if (res == 100001) cout << 0;
	else cout << res;
	return 0;
}