#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> v(41, { -1,-1 });
	v[0].first = 1;
	v[0].second = 0;
	v[1].first = 0;
	v[1].second = 1;

	int T, index = 2;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		if (v[n].first != -1) {
			cout << v[n].first << " " << v[n].second << "\n";
			continue;
		}

		for (; index <= n; index++) {
			v[index].first = v[index - 1].first + v[index - 2].first;
			v[index].second = v[index - 1].second + v[index - 2].second;
		}

		cout << v[n].first << " " << v[n].second << "\n";
	}

	return 0;
}