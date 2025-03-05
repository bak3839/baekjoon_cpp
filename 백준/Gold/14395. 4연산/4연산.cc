#include <bits/stdc++.h>

using namespace std;
using pls = pair<long long, string>;

int S, T;
set<long long> visited;
char operation[4] = { '*', '+', '-', '/' };

void bfs() {
    queue<pls> q;
    q.push({ S, "" });
    visited.insert(S);

    if (S == T) {
        cout << 0;
        return;
    }

    while (q.size()) {
        long long s = q.front().first;
        string str = q.front().second;
        q.pop();

        if (s == T) {
            cout << str;
            return;
        }

        long long next = s * s;
        if (visited.find(next) == visited.end()) {
            q.push({ next, str + '*' });
            visited.insert(s * s);
        }

        next = s + s;
        if (visited.find(next) == visited.end()) {
            q.push({ next, str + '+' });
            visited.insert(next);
        }

        if (visited.find(0) == visited.end()) {
            q.push({ 0, str + '-' });
            visited.insert(0);
        }

        if (s != 0 && (visited.find(1) == visited.end())) {
            q.push({ 1, str + '/' });
            visited.insert(1);
        }
    }

    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> T;

    bfs();
    return 0;
}
