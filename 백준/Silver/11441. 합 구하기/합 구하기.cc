#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, T;
	cin >> N;
	vector<int> v(N + 1);
	v[0] = 0;

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}

	cin >> T;

	int a, b;
	while (T--) {
		cin >> a >> b;
		cout << v[b] - v[a - 1] << "\n";
	}
	return 0;
}