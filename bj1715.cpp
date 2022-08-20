#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;

	int N, num, n1, n2, sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}

	while (pq.size() != 1) {
		n1 = pq.top();
		pq.pop();

		n2 = pq.top();
		pq.pop();

		sum += n1 + n2;
		pq.push(n1 + n2);
	}

	cout << sum;
	return 0;
}