#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, N, res;
    cin >> T;

    while (T--) {
        cin >> N;
        vector<int> v(N);

        for (int i = 0; i < N; i++) {
            cin >> v[i];
            if (i == 0) res = v[i];

            else {
                if (v[i] + v[i - 1] > 0) {
                    v[i] += v[i - 1]; 
                    res = max(res, v[i]);
                }
                else {
                    res = max(res, v[i]);
                    v[i] = 0;
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}