#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int T, K;
	ll sum, f, f1, f2;

	cin >> T;
	for (int i = 0; i < T; i++) {
		sum = 0;
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> f;
			pq.push(f);
		}

		while (pq.size() > 1) {
			f1 = pq.top(); pq.pop();
			f2 = pq.top(); pq.pop();
			sum += f1 + f2;
			pq.push(f1 + f2);
		}

		cout << sum << "\n";
		pq.pop();
	}

	return 0;
}