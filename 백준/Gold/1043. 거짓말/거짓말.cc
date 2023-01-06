#include <iostream>
#include <vector>

using namespace std;

vector<bool> avoid;
vector<vector<short>> party;
vector<short> parent;

short getRoot(short x) {
	if (parent[x] == x) return x;
	else return parent[x] = getRoot(parent[x]);
}

bool find(short a, short b) {
	a = getRoot(a);
	b = getRoot(b);

	if (a == b) return false;
	else return true;
}

void Union(short a, short b) {
	a = getRoot(a);
	b = getRoot(b);

	if (avoid[a]) parent[b] = a;

	else if (avoid[b]) parent[a] = b;

	else {
		if (a > b) {
			short tmp = b;
			b = a;
			a = tmp;
		}
		parent[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	short N, M, k, n, p, cnt;
	cin >> N >> M;
	cnt = M;

	avoid.resize(N + 1);
	parent.resize(N + 1);
	party.resize(M + 1);

	cin >> k;

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < k; i++) {
		cin >> n;
		avoid[n] = true;
	}

	for (int i = 1; i <= M; i++) {
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> p;
			party[i].push_back(p);

			if (j > 0) {
				if (find(party[i][j - 1], p)) {
					Union(party[i][j - 1], p);
				}
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			short x = party[i][j];
			short root = getRoot(parent[x]);
			if (avoid[root]) {
				cnt--;
				break;
			}
		}
	}

	cout << cnt;
	return 0;
}