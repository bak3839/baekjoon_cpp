#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K, min = 0;
	cin >> N >> K;

	vector<int> s(N);
	vector<int> res(N - 1);

	for (int i = 0; i < N; i++) cin >> s[i];
	sort(s.begin(), s.end());

	for (int i = 0; i < N - 1; i++) res[i] = s[i + 1] - s[i];
	sort(res.begin(), res.end());

	for (int i = 0; i < N - K; i++) min += res[i];
	cout << min;
	return 0;
}