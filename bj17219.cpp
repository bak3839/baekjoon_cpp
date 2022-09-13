#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, string> m;  // map<key, value>
	string key, value, search;
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> key >> value;
		m.insert(pair<string, string>(key, value));
	}

	for (int i = 0; i < M; i++) {
		cin >> key;
		cout << m[key] << "\n";
	}

	return 0;
}