#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, N, M, num;
	cin >> T;

	while (T--) {
		set<int> s;

		cin >> N;
		for (int i = 0;i < N;i++) {
			cin >> num;
			s.insert(num);
		}

		cin >> M;
		vector<int> v(M, 0);
		for (int i = 0;i < M;i++) {
			cin >> num;
			if (s.find(num) != s.end()) cout << "1\n";
			else cout << "0\n";
		}
	}

	return 0;
}