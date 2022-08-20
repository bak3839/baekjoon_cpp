#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int s;
	int m;
}Rank;

bool cmp(Rank r1, Rank r2) {
	if (r1.s < r2.s) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Rank r;
	int T, N, s, m, count = 1;

	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<Rank> v;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> s >> m;
			r.s = s;
			r.m = m;
			v.push_back(r);
		}
		sort(v.begin(), v.end(), cmp);

		int pass = v[0].m;
		for (int k = 1; k < v.size(); k++) {
			if (pass > v[k].m) {
				count++;
				pass = v[k].m;
			}
		}

		cout << count << "\n";
		count = 1;
	}

	return 0;
}