#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int N;
vector<string> fan;
vector<string> order;

bool cmp(string s1, string s2) {
    if (s1[0] < s2[0]) return true;
    else if (s1[0] == s2[0]) return stoi(s1.substr(2, s1.size() - 2)) < stoi(s2.substr(2, s2.size() - 2));
    else return false;
}

void Solution() {
    int cnt = 0;
    bool pass = true;
    stack<string> s;  

    for (int i = 0; i < N * 5; i++) {
        if (order[cnt] == fan[i]) {
            cnt++;     
        }

        else if (!s.empty() && order[cnt] == s.top()) {
            s.pop();
            cnt++;
            i--;
        }

        else if (order[cnt] != fan[i]) {
            if (!s.empty() && !cmp(fan[i], s.top())) {
                pass = false;
                break;
            }

            s.push(fan[i]);
        }

        else {
            pass = false;
            break;
        }
    }

    if (pass) cout << "GOOD";
    else cout << "BAD";
}

void Input() {
    cin >> N;

    fan.resize(N * 5);
    order.resize(N * 5);

    for (int i = 0; i < N * 5; i++) {
        cin >> fan[i];
        order[i] = fan[i];
    }

    sort(order.begin(), order.end(), cmp);
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
