#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> v;
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) v.push_back(s.substr(i));
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
	return 0;
}