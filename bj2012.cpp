#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll N, res = 0;
	cin >> N;

	vector<ll> v(N);

	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) res += abs(v[i] - (i + 1));

	cout << res;
	return 0;
}