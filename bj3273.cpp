#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, cnt = 0;
	cin >> n;
	vector<int> v(n);

	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	cin >> x;

	int left = 0, right = n - 1;

	while (left < right) {
		int sum = v[left] + v[right];
		if (sum == x) {
			++cnt;
			++left; --right;
		}
		else if (sum > x) --right;
		else ++left;
	}

	cout << cnt;
	return 0;
}