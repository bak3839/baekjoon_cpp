#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int w;
    int s;
    int e;
}Lecture;

int n, k, ans;
vector<bool> use;
vector<Lecture> lec;
vector<vector<bool>> t;

void Search(int sum, int x) {
    if (sum == k) {
        ans++;
        return;
    }

    for (int i = x; i < n; i++) {
        bool pass = true;
        Lecture l = lec[i];

        if (l.w == 5 || use[i]) continue;

        for (int j = l.s; j <= l.e; j++) {
            if (t[l.w][j]) {
                pass = false;
                break;
            }
        }

        if (!pass) continue;

        use[i] = true;
        for (int j = l.s; j <= l.e; j++) t[l.w][j] = true;

        Search(sum + (l.e - l.s + 1), i + 1);

        use[i] = false;
        for (int j = l.s; j <= l.e; j++) t[l.w][j] = false;
    }
}

void Solution() {
    Search(0, 0);
    cout << ans;
}

void Input() {
    cin >> n >> k;

    lec.resize(n);
    use.resize(n, false);
    t.resize(6, vector<bool>(11, false));

    for (int i = 0; i < n; i++) 
        cin >> lec[i].w >> lec[i].s >> lec[i].e;
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
