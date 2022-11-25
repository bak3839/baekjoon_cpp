#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, X, sum = 0, cnt = 0;
	cin >> N >> X;
	vector<int> v(N);

	for (int i = 0;i < N;i++) {
		cin >> v[i];
		if (i < X) sum += v[i];
	}

	int m = sum;
	++cnt;

	for (int i = X;i < N;i++) {
		sum = sum - v[i - X] + v[i];
		if (m < sum) {
			cnt = 1;
			m = sum;
		}

		else if (m == sum) ++cnt;
	}

	if (m == 0) cout << "SAD";
	else cout << m << "\n" << cnt;


	return 0;
}