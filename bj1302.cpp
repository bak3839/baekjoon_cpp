#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, int> m;
	string p, res;
	int N, max = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p;
		if (i == 0 || (max == 1 && res.compare(p) > 0)) {
			res = p;
			max = 1;
		}
		else if (m.find(p) != m.end()) {
			m[p]++;
			if (max == m[p] && res.compare(p) > 0) res = p;
			else if (max < m[p]) {
				res = p;
				max = m[p];
			}
			continue;
		}
		m.insert(pair<string, int>(p, 1));
	}

	cout << res;
	return 0;
}