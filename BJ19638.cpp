#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> pq;
	
	int N, Hcenti, T, H, count = 0;

	cin >> N >> Hcenti >> T;
	for (int i = 0; i < N; i++) {
		cin >> H;
		if (H >= Hcenti) pq.push(H);
	}
	
	while(count < T && !pq.empty()) {
		if (pq.top() != 1) H = pq.top() / 2;
		else H = pq.top();

		if (H >= Hcenti) {
			pq.pop();
			pq.push(H);
		}

		else pq.pop();
		count++;
	}

	if (pq.empty()) cout << "YES\n" << count;
	else cout << "NO\n" << pq.top();

	return 0;
}