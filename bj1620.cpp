#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, int> m;  // map<key, value>
	vector<string> v;
	string p;
	int N, M, key;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> p;
		m.insert(pair<string, int>(p, i + 1));
		v.push_back(p);
	}

	for (int i = 0; i < M; i++) {
		cin >> p;
		if (p[0] < '1' || p[0] > '9') {
			cout << m[p] << "\n";
		}

		else {
			key = stoi(p);
			cout << v[key - 1] << "\n";
		}
	}
	return 0;
}