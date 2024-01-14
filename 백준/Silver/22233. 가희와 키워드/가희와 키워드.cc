#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int N, M;
set<string> s;

void Solution() {
    string str;
    set<string>::iterator iter;

    for (int i = 0; i < M; i++) {
        cin >> str;

        string token;
        stringstream parse(str);

        while (getline(parse, token, ',')) {
            iter = s.find(token);

            if (iter != s.end()) s.erase(iter);
        }

        cout << s.size() << "\n";
    }
}

void Input() {
    string keyword;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> keyword;
        s.insert(keyword);
    }
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
