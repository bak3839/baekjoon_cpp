#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll s, s1, s2, sum = 1;
	int T, N;

	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> s;
			pq.push(s);
		}

		if (N == 1) {
			cout << "1" << "\n";
			pq.pop();
			continue;
		}

		while (pq.size() != 1) {
			s1 = pq.top(); pq.pop();
			s2 = pq.top(); pq.pop();
			sum *= ((s1 % 1000000007) * (s2 % 1000000007) % 1000000007);
			sum %= 1000000007;
			pq.push(s1 * s2);
		}

		cout << sum << "\n";
		sum = 1;
		pq.pop();
	}
	return 0;
}