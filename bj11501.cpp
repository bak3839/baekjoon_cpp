#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, N;
	
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> v(N);
		
		ll res = 0;
		int big = 0;

		for (int i = 0; i < N; i++) cin >> v[i];
		
		for (int i = N - 1; i >= 0; i--) {
			big = max(big, v[i]);
			res += big - v[i];
		}

		cout << res << "\n";
	}
	return 0;
}