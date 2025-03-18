#include <bits/stdc++.h>

using namespace std;

int ans = INT_MIN, N;

string S;
queue<int> n;
queue<char> oper;
vector<string> v;

void calulate() {
    int n, res = stoi(v[0]);

    for (int i = 1; i < v.size(); i += 2) {
        n = stoi(v[i + 1]);

        if (v[i] == "+") {
            res += n;
        }
        else if (v[i] == "-") {
            res -= n;
        }
        else {
            res *= n;
        }
    }

    ans = max(ans, res);
}

void go(int idx) {
    if (idx >= N) {
        calulate();
        return;
    }

    if (idx < N - 1 && '0' <= S[idx] && S[idx] <= '9') {
        int n1 = S[idx] - '0', n2 = S[idx + 2] - '0', res = 0;

        if (S[idx + 1] == '+') {
            res = n1 + n2;
        }
        else if (S[idx + 1] == '-') {
            res = n1 - n2;
        }
        else {
            res = n1 * n2;
        }

        v.push_back(to_string(res));
        go(idx + 3);
        v.pop_back();
    }

    v.push_back(string(1, S[idx]));
    go(idx + 1);
    v.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> S;
    go(0);
    cout << ans;
    return 0;
}
