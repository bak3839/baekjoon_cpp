#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, n1, n2, cnt = 0;
    cin >> N >> M;

    deque<int> dq1, dq2;
    vector<int> g1, g2;
    
    for (int i = 0; i < N; i++) {
        cin >> n1 >> n2;
        dq1.push_front(n1);
        dq2.push_front(n2);
    }

    bool dodo = true;

    for (int i = 0; i < M; i++) {
        if (dodo) {
            g1.push_back(dq1.front());
            dq1.pop_front();
        }
        else {
            g2.push_back(dq2.front());
            dq2.pop_front();
        }

        if (dq1.empty() || dq2.empty()) break;

        bool dodo_bell = false, su_bell = false;

        if (!g1.empty() && !g2.empty()) {
            if (g1.back() + g2.back() == 5) {
                su_bell = true;
            }

            else if (g1.back() == 5 || g2.back() == 5) {
                dodo_bell = true;
            }
        }

        else if (g1.empty() && !g2.empty()) {
            if (g2.back() == 5) dodo_bell = true;
        }

        else if (!g1.empty() && g2.empty()) {
            if (g1.back() == 5) dodo_bell = true;
        }

        if (dodo_bell) {
            for (int n : g2) dq1.push_back(n);
            for (int n : g1) dq1.push_back(n);
            g1.clear();
            g2.clear();
        }
        else if (su_bell) {
            for (int n : g1) dq2.push_back(n);
            for (int n : g2) dq2.push_back(n);
            g1.clear();
            g2.clear();
        }
        
        if (dodo) dodo = false;
        else dodo = true;
    }

    if (dq1.size() > dq2.size()) cout << "do";
    else if (dq1.size() < dq2.size()) cout << "su";
    else cout << "dosu";

    return 0;
}