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

	cin >> M;

	for (int j = 0; j < M; j++) {
		itr = li.begin();
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			ch = str[i];

			if (ch == '<') {
				if(itr != li.begin()) itr--;
			}

			else if (ch == '>') {
				if(itr != li.end()) itr++;
			} 

			else if (ch == '-') {
				if (itr != li.begin()) {
					itr--;
					itr = li.erase(itr);
				}
			}

			else li.insert(itr, ch);
		}
		for (itr = li.begin(); itr != li.end();) {
			cout << *itr;
			itr = li.erase(itr);
		}
		cout << "\n";
	}
	return 0;
}