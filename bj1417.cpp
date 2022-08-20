#include <iostream>
#include <queue>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, vote, point, count = 0;
	priority_queue<int> pq;


	cin >> N >> point;

	for (int i = 1; i < N; i++) {
		cin >> vote;
		pq.push(vote);
	}

	while (!pq.empty() && pq.top() >= point) {
		vote = pq.top() - 1;
		pq.pop();
		pq.push(vote);
		point++;
		count++;
	}

	cout << count;
	return 0;
}