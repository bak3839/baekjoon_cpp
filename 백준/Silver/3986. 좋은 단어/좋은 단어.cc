#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<string> word;

void Solution() {
    string str;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        bool pass = true;
        stack<char> s;
        str = word[i];

        for (int j = 0; j < str.size(); j++) {
            if (s.empty()) s.push(str[j]);
            else if (s.top() == str[j]) s.pop();
            else s.push(str[j]);
        }

        if (!s.empty()) pass = false;
        if (pass) ans++;
    }

    cout << ans;
}

void Input() {
    cin >> N;

    word.resize(N);

    for (int i = 0; i < N; i++)
        cin >> word[i];
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