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
	vector<pii> pos;

	for (int i = 0; i < N; i++) {
		cin >> d;
		pos.push_back(make_pair(d - L, d + L));
	}

	sort(pos.begin(), pos.end());

	dup = -2100000000;

	for (int i = 1; i < N; i++) {

		if (pos[i - 1].second <= pos[i].first) {
			dup = pos[i - 1].second;
			continue;
		}

		if (dup <= pos[i].first) ans += abs(pos[i - 1].second - pos[i].first);
		else ans += abs(pos[i - 1].second - dup);

		dup = pos[i - 1].second;
	}

	cout << ans;

	return 0;
}