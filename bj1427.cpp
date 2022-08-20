#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char n1, char n2) {
	if (n1 > n2) return 1;
	else return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string num;
	cin >> num;

	sort(num.begin(), num.end(), cmp);
	cout << num;
	return 0;
}