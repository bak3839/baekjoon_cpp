#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll sum = 0;
	int N;
	cin >> N;

	vector<int> v(N);
	

	for (int i = 0;i < N;i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());

	int index = 0;
	for (;index < N;index++) {
		if (v[index] > 0) break;
	}

	if (index != 0) sort(v.begin(), v.begin() + index, greater<int>());

	for (int i = N - 1; i > 0;i--) {
		if (v[i] == 0 && i != 1) continue;

		int sub_sum = v[i] + v[i - 1];
		int sub_mul = v[i] * v[i - 1];

		if (sub_sum < sub_mul) {
			sum = sum - sub_sum + sub_mul;
			i--;
		}
	}

	cout << sum;
	return 0;
}