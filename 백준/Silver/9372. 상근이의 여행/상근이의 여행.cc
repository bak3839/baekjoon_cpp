#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, N, M, s, e;

	cin >> T;

	while (T--) {
		cin >> N >> M;	
		for (int i = 0; i < M; i++) {
			cin >> s >> e;
		}
		cout << N - 1 << "\n";
	}
	return 0;
}