#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	double ans = 0.0, max_drink = 0.0;
	int N;
	cin >> N;
	vector<double> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		max_drink = max(max_drink, v[i]);
	}

	for (int i = 0; i < N; i++) {
		if (v[i] == max_drink) continue;

		ans += double(v[i] / 2);
	}
	ans += max_drink;

	cout << ans;
	return 0;
}