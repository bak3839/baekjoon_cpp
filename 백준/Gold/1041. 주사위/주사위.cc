#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll res = 0, N;
	cin >> N;
	vector<ll> v(6);
	vector<ll> d(3);

	for (int i = 0; i < 6; i++) cin >> v[i];

	if (N == 1) {
		ll n = 0;
		for (int i = 0; i < 6; i++) {
			res += v[i];
			n = max(n, v[i]);
		}
		res -= n;
	}

	else {
		d[0] = min(v[0], v[5]);
		d[1] = min(v[1], v[4]);
		d[2] = min(v[2], v[3]);
		sort(d.begin(), d.end());

		res = (N * d[1]) * 4;
		res += ((N - 1) * N * d[0]) * 4;
		res += d[2] * 4;
		res += ((N - 2) * d[1]) * 4;
		res += ((N - 2) * (N - 2)) * d[0];	
	}

	cout << res;
	return 0;
}