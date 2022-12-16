#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, T;
	cin >> T;
	
	while (T--) {
		int num = 1;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			num *= M - i;
			num /= 1 + i;
		}
		cout << num << "\n";
	}
	return 0;
}