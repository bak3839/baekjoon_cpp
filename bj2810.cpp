#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, count = 0;
	char c[51];
	

	cin >> N;
	cin >> c;

	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == 'L') i++;
		count++;
	}
	count++;

	if (N > count) cout << count;
	else cout << N;
	return 0;
}