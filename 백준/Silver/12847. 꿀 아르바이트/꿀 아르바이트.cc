#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	ll sum = 0, res = 0;
	cin >> n >> m;
	vector<int> t(n);

	for (int i = 0; i < n; i++) {
		cin >> t[i];
		if (i < m) sum += t[i];
	}
	res = sum;

	for (int i = m; i < n; i++) {
		sum = sum - t[i - m] + t[i];
		if (res < sum) res = sum;
	}

	cout << res;

	return 0;
}