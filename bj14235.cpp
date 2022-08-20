#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> pq;

	int n, a, g;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {
			if (pq.empty()) cout << "-1\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			for (int j = 0; j < a; j++) {
				cin >> g;
				pq.push(g);
			}
		}
	}

	return 0;
}