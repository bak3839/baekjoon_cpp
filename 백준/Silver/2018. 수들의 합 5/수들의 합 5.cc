#include <iostream>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, pos1 = 1, pos2 = 1, sum = 1, res = 1;
	cin >> n;

	while (pos2 != n){
		if (sum == n){
			res++, pos2++;
			sum += pos2;
		}
		else if (sum > n){
			sum -= pos1;
			pos1++;
		}
		else{
			pos2++;
			sum += pos2;
		}
	}

	cout << res;
	return 0;
}