#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int K;
    string S;

    cin >> K >> S;

    stack<int> n, s;
    vector<int> v;

    bool flag = false;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'N') {
            n.push(1);
            if (!flag) {
                v.push_back(s.size());
                while (!s.empty()) s.pop();
            }
            flag = true;
        }
        else if (S[i] == 'S') {
            s.push(1);
            if (flag) {
                v.push_back(n.size());
                while (!n.empty()) n.pop();
            }
            flag = false;
        }
    }

    if (flag) {
        v.push_back(n.size());
    }
    else v.push_back(s.size());

    v.push_back(0);

    int res = 0;

    for (int i = 1; i < v.size(); i++) {
        res = max(res, 2 * min(v[i - 1], v[i]));
    }

    cout << res;
    return 0;
}