#include <iostream>
#include <queue>
#include <string>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq2;

	int T, k, n;
	string s;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) { // I 73  D 68
			cin >> s;

			if (s.compare("I") == 0) {
				cin >> n;
				pq.push(n);
				pq2.push(n);
			}

			else {
				cin >> n;
				if (n == 1) {
					if (pq.empty()) cout << "EMPTY\n";
					else pq.pop();
				}

				else if (n == -1) {
					if (pq2.empty()) cout << "EMPTY\n";
					else pq2.pop();
				}
			}
		}
	}

	cout << pq.top() << " " << pq2.top();
	return 0;
}