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

	set<string> s1;
	set<string> s2;
	string name;
	vector<string> res;
	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name;
		s1.insert(name);
	}

	for (int i = 0; i < M; i++) {
		cin >> name;
		s2.insert(name);
	}

	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(res));

	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";

	return 0;
}