#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int N, K, ans;
vector<char> num;

void Search(string res) {
    if (res.size() > s.size()) return;

    if (res.size() != 0) {
        int tmp = stoi(res);

        if (tmp <= N && ans < tmp) ans = tmp;
    }

    for (int i = 0; i < K; i++) {
        Search(res + num[i]);
    }
}

void Solution() {
    Search("");

    cout << ans;
}

void Input() {
    cin >> N >> K;
    
    num.resize(K);
    s = to_string(N);

    for (int i = 0; i < K; i++)
        cin >> num[i];
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