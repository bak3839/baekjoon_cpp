#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, n, maxNum = 0, minNum = 1000000001;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> n;
        maxNum = max(maxNum, n);
        minNum = min(minNum, n);
    }

    cout << 2 * (maxNum - minNum);
    return 0;
}