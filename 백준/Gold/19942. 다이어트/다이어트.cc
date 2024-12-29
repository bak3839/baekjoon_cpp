#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct {
    int p, f, s, v, c;
}Food;

int mp, mf, ms, mv;
int N, ans = 10000001;
vector<int> idx;
vector<Food> foods;
map<int, vector<int>> m;

bool calc() {
    int p = 0, f = 0, s = 0, v = 0, c = 0;

    for (int n : idx) {
        p += foods[n].p;
        f += foods[n].f;
        s += foods[n].s;
        v += foods[n].v;
        c += foods[n].c;
    }

    if (p >= mp && f >= mf && s >= ms && v >= mv) {
        if (ans > c) {
            m[c] = idx;
            ans = c;
        }
        return true;
    }

    return false;
}

void search(int x) {
    if (calc()) return;

    for (int i = x; i < N; i++) {
        idx.push_back(i);
        search(i + 1);
        idx.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p, f, s, v, c;
    cin >> N;

    foods.resize(N);
    cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < N; i++) {
        cin >> p >> f >> s >> v >> c;
        foods[i] = { p, f, s, v, c };
    }

    search(0);

    if (ans == 10000001) cout << -1;
    else {
        cout << ans << "\n";
        for (int n : m[ans])
            cout << n + 1 << " ";
    }
    
    return 0;
}