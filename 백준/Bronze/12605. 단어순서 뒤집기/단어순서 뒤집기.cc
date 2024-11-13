#include <iostream>
#include <string>
#include <sstream>
#include <stack>;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<string> S;
	int T, count = 0;
	cin >> T;
	cin.ignore();

	while (count != T) {
		string str, word;
		getline(cin, str);

		stringstream ss(str);

		while (ss >> word)
			S.push(word);

		cout << "Case #" << ++count << ": ";
		while (!S.empty()) {
			cout << S.top() << " ";
			S.pop();
		}
		cout << "\n";
	}

	return 0;
}