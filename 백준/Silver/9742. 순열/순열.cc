#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool finish;
    int N, num, cnt;
    string S, ans;
    vector<char> v;

    while (cin >> S >> N) {
        finish = false;
        num = 1, cnt = 0;

        for (int i = 2; i <= S.size(); i++) num *= i;

        if (num >= N) {
            for (char ch : S) v.push_back(ch);

            do {
                cnt++;

                if (cnt == N) {
                    string tmp = "";

                    for (char ch : v) tmp.push_back(ch);

                    ans = tmp;
                    finish = true;
                }

            } while (next_permutation(v.begin(), v.end()));
        }

        cout << S << " " << N << " = ";

        if (finish) cout << ans << "\n";
        else cout << "No permutation\n";

        v.clear();
    }
    return 0;
}