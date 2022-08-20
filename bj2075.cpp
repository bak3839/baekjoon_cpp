#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			if (i == 0) pq.push(x);
			else if (pq.top() < x) {
				pq.pop();
				pq.push(x);
			}
		}
	}

	cout << pq.top();
	return 0;
}