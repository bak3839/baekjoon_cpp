#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	list<char> li;
	list<char>::iterator itr;
	string str;
	char ch;
	int M;

	cin >> str;
	for (int i = 0; i < str.size(); i++) li.push_back(str[i]);

	itr = li.end();

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> ch;

		if (ch == 'P') {
			cin >> ch;
			li.insert(itr, ch);
		}

		else if (ch == 'B') {
			if (itr != li.begin()) {
				itr--;
				itr = li.erase(itr);
			}
		}

		else if (ch == 'D') {
			if (itr != li.end()) itr++;
		}

		else if (ch == 'L') {
			if (itr != li.begin()) itr--;
		}
	}
	for (itr = li.begin(); itr != li.end(); itr++) cout << *itr;
	return 0;
}