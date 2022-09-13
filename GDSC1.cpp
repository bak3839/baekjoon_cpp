#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "GDSC";
	int N, index = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cout << str[index++];
		if (index == 4) index = 0;
	}
	return 0;
}