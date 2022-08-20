#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2)) return 1;
		else if (abs(n1) == abs(n2)) {
			if (n1 > n2) return 1;
			else return 0;
		}
		else return 0;
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, cmp> pq;
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << "0" << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(x);
	}
	return 0;
}