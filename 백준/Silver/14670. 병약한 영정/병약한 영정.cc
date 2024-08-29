#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, Q;
int A[101];
vector<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(A, 0xff, sizeof(A));

	cin >> N;
	while (N--) {
		int x, y; cin >> x >> y;
		A[x] = y;
	}
	cin >> N;
	while (N--) {
		bool chk = 1;
		ans.clear();
		cin >> Q;
		while (Q--) {
			int x; cin >> x;
			if (A[x] < 0) chk = 0;
			else ans.emplace_back(A[x]);
		}
		if (chk) {
			for (auto &x : ans) cout << x << ' ';
			cout << '\n';
		}
		else cout << "YOU DIED\n";
	}
}