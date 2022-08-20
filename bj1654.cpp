#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<ll> v;
	ll N, M, lan, left, right, mid, sum = 0, res = 0, max = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> lan;
		v.push_back(lan);
		if (max < lan) max = lan;
	}

	left = 1, right = max;

	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid <= v[i]) sum += (v[i] / mid);
		}

		if (sum >= M) {
			left = mid + 1;
			if (res < mid) res = mid;
		}

		else {
			right = mid - 1;
		}
	}

	cout << res;
	return 0;
}