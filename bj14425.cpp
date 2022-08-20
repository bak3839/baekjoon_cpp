#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set<string> s;
	string str;
	vector<string> res;
	int N, M, count = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (s.find(str) != s.end()) count++;
	}

	cout << count;

	return 0;
}