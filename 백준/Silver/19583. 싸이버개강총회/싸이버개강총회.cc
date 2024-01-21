#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using pss = pair<string, string>;

string S, E, Q;
vector<pss> chatLog;

void Solution() {
    int ans = 0;
    set<string> s;
    set<string>::iterator iter;

    for (int i = 0; i < chatLog.size(); i++) {
        string time = chatLog[i].first;
        string name = chatLog[i].second;

        if (time <= S)
            s.insert(name);

        else if (E <= time && time <= Q) {
            iter = s.find(name);

            if (iter != s.end()) {
                s.erase(iter);
                ans++;
            }
        }
    }

    cout << ans;
}

void Input() {
    string name, time;
    cin >> S >> E >> Q;

    while (cin >> time >> name) {
        chatLog.push_back({ time, name });
    }
    sort(chatLog.begin(), chatLog.end());
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
