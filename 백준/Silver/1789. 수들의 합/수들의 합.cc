#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long N, i = 0;
    cin >> N;

    while (N > 0) N -= ++i;

    if (N != 0) i -= 1;
    cout << i;
    return 0;
}