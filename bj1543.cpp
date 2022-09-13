#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str, search;
	int index, cnt = 0;
	getline(cin, str);
	getline(cin, search);

	for (int i = 0; i < str.size();) {
		index = str.find(search, i);
		if (index == string::npos) break;
		i = search.size() + index;
		cnt++;
	}

	cout << cnt ;
	return 0;
}