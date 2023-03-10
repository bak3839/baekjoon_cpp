#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

long long MAX(long long a, long long b) { return a > b ? a : b; }
long long MIN(long long a, long long b) { return a > b ? b : a; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long ans = 0;
	int N, K, Lmax, Lmin, Hmax, Hmin;
	cin >> N >> K;
	vector<long long> v(N);

	for (int i = 0; i < K; i++) {
		cin >> v[i];
		if (i == 0) Lmax = Lmin = v[i];
		else {
			Lmax = MAX(Lmax, v[i]);
			Lmin = MIN(Lmin, v[i]);
			ans += abs(v[i] - v[i - 1]);
		}
	}
	for (int i = K; i < N; i++) {
		cin >> v[i];
		if (i == K) Hmax = Hmin = v[i];
		else {
			Hmax = MAX(Hmax, v[i]);
			Hmin = MIN(Hmin, v[i]);
		}
	}

	if (K == 0) ans = Hmax - Hmin;
	else if (N != K) {
		int s;
		if (Hmin < Lmin) {
			s = (Lmin - Hmin) * (v[0] == Lmin || v[K - 1] == Lmin ? 1 : 2);
			ans += MIN(s, MIN(v[0] - Hmin, v[K - 1] - Hmin));
		}
		if (Hmax > Lmax) {
			s = (Hmax - Lmax) * (v[0] == Lmax || v[K - 1] == Lmax ? 1 : 2);
			ans += MIN(s, MIN(Hmax - v[0], Hmax - v[K - 1]));
		}
	}

	cout << ans;
	return 0;
}