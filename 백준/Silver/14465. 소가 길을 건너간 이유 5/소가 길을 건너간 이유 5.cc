#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, B, K, n, res = 1000001, sum = 0;
	cin >> N >> K >> B;

	vector<int> v(N + 1, 0);

	for (int i = 0; i < B; i++) {
		cin >> n;
		v[n] = 1;
	}
	
	for (int i = 1; i <= K; i++) {
		if (v[i]) sum++;
	}
	res = min(res, sum);

	for (int i = K + 1; i <= N; i++) {
		if (v[i]) sum++;
		if (v[i - K]) sum--;
		res = min(res, sum);
	}

	cout << res;
	return 0;
}