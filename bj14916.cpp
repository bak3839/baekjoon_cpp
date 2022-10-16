#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, res = 0;
	cin >> n;

	vector<int> v(n + 1, -1);
	v[2] = 1;
	v[4] = 2;
	v[5] = 1;

	for (int i = 6; i <= n; i++) {
		if (v[i - 2] != -1 && v[i - 5] != -1) {
			v[i] = min(v[i - 2], v[i - 5]) + 1;
		}

		else if (v[i - 2] != -1) v[i] = v[i - 2] + 1;
		else if (v[i - 5] != -1) v[i] = v[i - 5] + 1;
	}
	
	cout << v[n];
	return 0;
}