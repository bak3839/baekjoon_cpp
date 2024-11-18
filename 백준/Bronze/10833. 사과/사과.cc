#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S, A, ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S >> A;
		ans += (A % S);
	}

	cout << ans;
	return 0;
}