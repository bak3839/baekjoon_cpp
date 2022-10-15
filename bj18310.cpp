#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int len;
	if (N % 2) len = (N + 1) / 2 - 1;
	else len = N / 2 - 1;

	cout << v[len];

	return 0;
}