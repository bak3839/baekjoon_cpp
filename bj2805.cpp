#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<ll> v;
	ll N, M, tree, left, right, mid, max = 0, sum = 0, res;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> tree;
		v.push_back(tree);
		if (tree > max) max = tree;
	}

	left = 1, right = max;

	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < N; i++) {
			if (mid < v[i]) sum += v[i] - mid;
		}

		if (sum == M) {
			res = mid;
			break;
		}

		else if (sum > M) {
			left = mid + 1;
			res = mid;
		}

		else {
			right = mid - 1;
			res = right;
		}
	}

	cout << res;
	return 0;
}