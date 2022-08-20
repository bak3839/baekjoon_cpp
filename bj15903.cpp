#include <iostream>
#include <queue>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<long long, vector<long long>, greater<long long>> pq;

	int n, m;
	long long c1, c2, a, sum = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		pq.push(a);
	}

	for (int i = 0; i < m; i++) {
		c1 = pq.top();
		pq.pop();

		c2 = pq.top();
		pq.pop();

		pq.push(c1 + c2);
		pq.push(c1 + c2);
	}

	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
	return 0;
}