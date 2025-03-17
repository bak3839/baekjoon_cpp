#include <iostream>
#include <string.h>
#include <stack>
#include <vector>

using namespace std;

stack<char> s;

int cmp(char ch[]) {
	int len = strlen(ch);
	char open_ch;
	for (int i = 0; i < len; i++) {
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
		char str[101] = { 0, };
		cin.getline(str, 101);
		if (strcmp(str, ".") == 0) break;
		if (cmp(str) == 1) cout << "yes" << "\n";
		else cout << "no" << "\n";
		while (!s.empty()) s.pop();
	}
	return 0;
}