#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    long long ans = 1;
    cin >> N;

    vector<long long> num(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num.begin(), num.end());

    for (auto n : num) {
        if (n != ans) {
            cout << ans;
            return 0;
        }

        ans++;
    }

    cout << ans;
    return 0;
}