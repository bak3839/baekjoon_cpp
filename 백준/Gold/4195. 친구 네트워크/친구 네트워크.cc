#include <iostream>
#include <vector>
#include <map>

using namespace std;

int F;
vector<int> parent;
map<int, int> counts;

int GetParent(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = GetParent(parent[x]);
}

void Union(int a, int b) {
    if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    counts[a] += counts[b];
    parent[b] = a;
}

void Solution() {
    int cnt = 1;
    string a, b;
    
    map<string, int> m;
    parent.push_back(0);

    while (F--) {
        int aParent, bParent;
        cin >> a >> b;

        if (m[a] == 0) {
            m[a] = cnt;
            counts[cnt] = 1;
            parent.push_back(cnt++);
        }

        if (m[b] == 0) {
            m[b] = cnt;
            counts[cnt] = 1;
            parent.push_back(cnt++);
        }

        aParent = GetParent(m[a]);
        bParent = GetParent(m[b]);

        if (aParent != bParent) Union(aParent, bParent);
        if (aParent <= bParent) cout << counts[aParent] << "\n";
        else cout << counts[bParent] << "\n";      
    }
    m.clear();
    parent.clear();
    counts.clear();
}

void Input() {
    cin >> F;
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}