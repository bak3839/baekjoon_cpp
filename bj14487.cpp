#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, num, res = 0;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n - 1; i++) res += v[i];
	cout << res;
	return 0;
}