#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s;

int cmp(string ch) {
	char open_ch;
	for (int i = 0; i < ch.length(); i++) {
		switch (ch[i]) {
		case'(': case'[': {
			s.push(ch[i]);
			break;
		}
		case')': case']': {
			if (s.empty()) {
				return 0;
			}
			else {
				open_ch = s.top();
				s.pop();
				if (open_ch == '(' && ch[i] != ')' ||
					open_ch == '[' && ch[i] != ']') {
					return 0;
				}
			}
			break;
		}
		}
	}
	if (!s.empty()) return 0;
	else return 1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		string str;
		getline(cin, str);
		if (str.compare(".") == 0) break;
		if (cmp(str) == 1) cout << "yes" << "\n";
		else cout << "no" << "\n";
		while (!s.empty()) s.pop();
	}
	return 0;
}