#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> v;
	map<int, int> m;
	int N, c, M, value;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> c;
		if (m.find(c) != m.end()) m[c]++;
		else m.insert(pair<int, int>(c, 1));
	}

	cin >> M;

	/*for (int i = 0; i < M; i++) {
		cin >> c;
		if (m.find(c) != m.end()) v.push_back(m[c]);
		else v.push_back(0);
	}


	for (int i = 0; i < M; i++) {
		cout << v[i] << " ";
	}*/
	for (int i = 0; i < M; i++) {
		cin >> c;
		v.push_back(c);
	}

	for (int i = 0; i < M; i++) {
		if (m.find(v[i]) != m.end()) {
			cout << m[v[i]] << " ";
		}
		else cout << "0 ";
	}
	return 0;
}