#include <iostream>

using namespace std;

bool inc = 1;
int old = 0;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	while (N--) {
		int x; cin >> x;
		if (x == old) {
			cout << "NO";
			return 0;
		}
		if (x > old) {
			if (!inc) {
				cout << "NO";
				return 0;
			}
			else old = x;
		}
		else {
			if (inc) {
				inc = 0;
			}
			old = x;
		}
	}

	cout << "YES";
    return 0;
}