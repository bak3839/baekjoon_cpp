#include <iostream>

using namespace std;

long long DP[36];

int main() {
    int N;
    cin >> N;

	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 2;
	
	for (int i = 3; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			DP[i] += (DP[j] * DP[i - 1 - j]);
		}
	}
    
	cout << DP[N];
    return 0;
}