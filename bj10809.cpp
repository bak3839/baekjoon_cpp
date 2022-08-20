#include <iostream>
#include <string.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char str[101];
	cin >> str;

	int res[26] = { -1, };
	for (int i = 0; i < 23; i++) res[i] = -1;
	for (int i = 0; i < strlen(str); i++) {
		int n = str[i] - 96;
		if (res[n - 1] == -1) res[n - 1] = i;
	}
	for (int i = 0; i < 26; i++) cout << res[i] << " ";
	return 0;
}