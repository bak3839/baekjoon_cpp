#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long ans = 0;
	int N, L, d, dup;
	cin >> N >> L;
	vector<int> pos;

	for (int i = 0; i < N; i++) {
		cin >> d;
		pos.push_back(d);
	}

	sort(pos.begin(), pos.end());

	dup = -2100000000;

	for (int i = 1; i < N; i++) {
		int s = pos[i] - L;
		int e = pos[i] + L;

		if (pos[i - 1] + L <= s) {
			dup = pos[i - 1] + L;
			continue;
		}

		if (dup <= s) ans += abs(pos[i - 1] + L - s);
		else ans += abs(pos[i - 1] + L - dup);

		dup = pos[i - 1] + L;
	}

	cout << ans;

	return 0;
}