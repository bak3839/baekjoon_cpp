#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> pq;
	vector<int> v;

	int N, M, c, w;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> c;
		pq.push(c);
	}

	for (int i = 0; i < M; i++) {
		cin >> w;
		v.push_back(w);
	}

	for (int i = 0; i < M; i++) {
		if (pq.top() < v[i]) {
			cout << "0";
			break;
		}
		else {
			c = pq.top() - v[i];
			pq.pop();
			pq.push(c);
		}

		if (i == M - 1) cout << "1";
	}
	return 0;
}