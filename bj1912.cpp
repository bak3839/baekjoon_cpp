#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	int res_max = v[0], sub_max = v[0];

	for (int i = 1; i < n; i++) {
		sub_max = max(sub_max + v[i], v[i]);
		res_max = max(res_max, sub_max);
	}

	cout << res_max;
	return 0;
}