#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<int> ans;
vector<string> coin;
string res[8] = { "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH" };

void Solution() {
    for (int i = 0; i < N; i++) {
        string now = coin[i];
        ans.resize(8, 0);

        for (int j = 0; j < 8; j++) {
            int cnt = 0, index = 0;

            while (now.find(res[j], index) != string::npos) {
                index = now.find(res[j], index) + 1;
                ans[j]++;
            }
        }
        for (int i = 0; i < 8; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        ans.clear();
    }
}

void Input() {
    cin >> N;

    coin.resize(N);

    for (int i = 0; i < N; i++)
        cin >> coin[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}